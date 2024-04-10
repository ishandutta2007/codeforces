#include<stdio.h>
#include<algorithm>
#include<vector>
#define Block 200
#define SZ 1048576
#define SZ2 65536
using namespace std;
int BE[51000], L, n, C[701000], Rank[701000], LCP[701000], ord1[701000], ord2[701000], SA[701000], IT[SZ+SZ+2], mm, Res[501000][2], CC[50100];
int IT2[SZ2+SZ2+2][2];
char p[701000];
struct QQ{
    int l, r, t1, t2, num;
    bool operator <(const QQ &p)const{
        return t2 < p.t2;
    }
};
vector<QQ>E[510];
struct A{
    int a, b, num;
}w[701000];
struct B{
    int x, num;
    bool operator<(const B &p)const{
        return x<p.x;
    }
}P[50100];
void Suffix_Array(){
    int i, MM = max(L, 300), LL = 1, cnt;
    for(i=0;i<L;i++){
        w[i].a = p[i], w[i].b = p[i+1];
    }
    while(1){
        for(i=0;i<=MM;i++)C[i]=0;
        for(i=0;i<L;i++)C[w[i].b]++;
        for(i=1;i<=MM;i++)C[i]+=C[i-1];
        for(i=0;i<L;i++)ord1[--C[w[i].b]] = i;
        for(i=0;i<=MM;i++)C[i]=0;
        for(i=0;i<L;i++)C[w[i].a]++;
        for(i=1;i<=MM;i++)C[i]+=C[i-1];
        for(i=L-1;i>=0;i--)ord2[--C[w[ord1[i]].a]] = ord1[i];
        cnt = 0;
        for(i=0;i<L;i++){
            if(i==0 || w[ord2[i]].a != w[ord2[i-1]].a || w[ord2[i]].b != w[ord2[i-1]].b)cnt++;
            Rank[ord2[i]] = cnt;
        }
        LL*=2;
        if(LL>L)break;
        for(i=0;i<L;i++){
            w[i].a = Rank[i];
            if(i+LL>=L)w[i].b = 0;
            else w[i].b = Rank[i+LL];
        }
    }
    for(i=0;i<L;i++)SA[Rank[i]] = i;
}
void Ins(int a, int b){
    a+=SZ;
    IT[a] = b;
    while(a!=1){
        a>>=1;
        IT[a] = min(IT[a*2],IT[a*2+1]);
    }
}
void Get_LCP(){
    int i, t = 0, x, y;
    for(i=0;i<L;i++){
        if(t)t--;
        x = Rank[i];
        if(x == L)continue;
        y = SA[x+1];
        while(p[i+t]==p[y+t])t++;
        LCP[x] = t;
    }
    for(i=1;i<L;i++)Ins(i,LCP[i]);
}
int Left(int x, int l){
    x = x+SZ-1;
    while(IT[x] >= l)x = (x-1)>>1;
    while(x<SZ){
        x=x*2+1;
        if(IT[x] >= l)x--;
    }
    return x-SZ+1;
}
int Right(int x, int l){
    x = x+SZ;
    while(IT[x] >= l)x = (x+1)>>1;
    while(x<SZ){
        x=x*2;
        if(IT[x] >= l)x++;
    }
    return x-SZ;
}
int Get(int num){
    int b = 1, e = mm, r = mm+1, mid;
    while(b<=e){
        mid = (b+e)>>1;
        if(P[mid].x >= num){
            r = mid;
            e = mid - 1;
        }
        else b = mid + 1;
    }
    return r;
}
void Add(int a){
    a += SZ2;
    IT2[a][0]++;
    while(a!=1){
        a>>=1;
        if(IT2[a+a][0]<IT2[a+a+1][0]){
            IT2[a][0] = IT2[a+a+1][0];
            IT2[a][1] = IT2[a+a+1][1];
        }
        else{
            IT2[a][0] = IT2[a+a][0];
            IT2[a][1] = IT2[a+a][1];
        }
    }
}
int GetMax(int l, int r){
    l+=SZ2, r+=SZ2;
    int MM = -1, d = 0, ll = l;
    while(l<=r){
        if(MM < IT2[l][0] || (MM == IT2[l][0] && IT2[l][1] < d)){
            MM = IT2[l][0], d = IT2[l][1];
        }
        if(MM < IT2[r][0] || (MM == IT2[r][0] && IT2[r][1] < d)){
            MM = IT2[r][0], d = IT2[r][1];
        }
        l=(l+1)>>1,r=(r-1)>>1;
    }
    if(!d)d = ll;
    return d;
}
int main(){
    int i, j, t1, t2;
    scanf("%s",p);
    for(i=0;p[i];i++);
    p[i] = ' ';
    L = i+1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        BE[i] = L;
        scanf("%s",p+L);
        for(j=L;p[j];j++);
        p[j] = ' ';
        L = j+1;
    }
    BE[n+1] = L;
    Suffix_Array();
    Get_LCP();
    for(i=1;i<=n;i++){
        for(j=BE[i];j<BE[i+1];j++){
            mm++;
            P[mm].num = i;
            P[mm].x = Rank[j];
        }
    }
    sort(P+1,P+mm+1);
    int Q;
    scanf("%d",&Q);
    for(i=0;i<Q;i++){
        int l, r, b, e;
        scanf("%d%d%d%d",&l,&r,&b,&e);
        b--,e--;
        t1 = Get(Left(Rank[b],e-b+1));
        t2 = Get(Right(Rank[b],e-b+1)+1) - 1;
        if(t2 - t1 <= Block){
            int Mx = -1, x = -1;
            for(j=t1;j<=t2;j++){
                CC[P[j].num]++;
                if(l<=P[j].num && P[j].num<=r && (Mx < CC[P[j].num] || (Mx == CC[P[j].num] && P[j].num < x))){
                    Mx = CC[P[j].num];
                    x = P[j].num;
                }
            }
            if(x==-1)Res[i][0]=l,Res[i][1]=0;
            else Res[i][0]=x,Res[i][1]=Mx;
            for(j=t1;j<=t2;j++){
                CC[P[j].num]--;
            }
        }
        else{
            QQ tp;
            tp.num=i,tp.l=l,tp.r=r,tp.t1=t1,tp.t2=t2;
            E[(t1+Block-1)/Block].push_back(tp);
        }
    }
    for(i=1;i<=mm/Block;i++){
        if(E[i].empty())continue;
        for(j=0;j<=SZ2+SZ2;j++){
            IT2[j][0] = 0;
            if(j>=SZ2)IT2[j][1]=j-SZ2;
        }
        for(j=1;j<=n;j++)CC[j]=0;
        sort(E[i].begin(),E[i].end());
        int pv = i*Block;
        for(j=0;j<E[i].size();j++){
            while(pv <= E[i][j].t2){
                CC[P[pv].num]++;
                Add(P[pv].num);
                pv++;
            }
            int Mx = -1, x = -1;
            x = GetMax(E[i][j].l,E[i][j].r);
            Mx = CC[x];
            for(int k=i*Block-1;k>=E[i][j].t1;k--){
                CC[P[k].num]++;
                if(E[i][j].l<=P[k].num && P[k].num<=E[i][j].r && (Mx < CC[P[k].num] || (Mx == CC[P[k].num] && P[k].num < x))){
                    Mx = CC[P[k].num];
                    x = P[k].num;
                }
            }
            Res[E[i][j].num][0] = x, Res[E[i][j].num][1] = Mx;
            for(int k=i*Block-1;k>=E[i][j].t1;k--){
                CC[P[k].num]--;
            }
        }
    }
    for(i=0;i<Q;i++){
        printf("%d %d\n",Res[i][0],Res[i][1]);
    }
}