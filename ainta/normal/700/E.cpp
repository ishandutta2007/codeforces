#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define SZ 262144
using namespace std;
int n, Rank[201000], SA[201000], LCP[201000][20], Low[201000], IT[SZ+SZ];
char p[201000];
struct SA{
    int a, b, num;
    bool operator<(const SA &p)const{
        return a!=p.a?a<p.a:b<p.b;
    }
}w[201000];
void Make_SA(){
    int i, L = 1;
    for(i=0;i<n;i++)w[i].a=p[i],w[i].b=p[i+1],w[i].num=i;
    while(1){
        sort(w,w+n);
        int cnt = 0;
        for(i=0;i<n;i++){
            if(!i || w[i-1]<w[i])cnt++;
            Rank[w[i].num] = cnt;
        }
        if(cnt==n)break;
        L<<=1;
        for(i=0;i<n;i++){
            w[i].a=Rank[i];
            if(i+L>=n)w[i].b=0;
            else w[i].b=Rank[i+L];
            w[i].num=i;
        }
    }
    for(i=0;i<n;i++)SA[Rank[i]]=i;
}
void Make_LCP(){
    int i, l = 0, x, y, j;
    for(i=0;i<n;i++){
        if(l)l--;
        x = Rank[i];
        if(x==n)continue;
        y=SA[x+1];
        while(p[i+l]==p[y+l])l++;
        LCP[x][0]=l;
    }
    for(i=0;i<17;i++){
        for(j=1;j<n;j++){
            if(j+(1<<i)>n)continue;
            LCP[j][i+1]=min(LCP[j+(1<<i)][i], LCP[j][i]);
        }
    }
    for(i=1;i<=n;i++){
        Low[i]=Low[i-1];
        if((1<<(Low[i]+1)) <= i)Low[i]++;
    }
}
void Ins(int a, int b){
    a+=SZ;
    IT[a]=b;
    while(a!=1){
        a>>=1;
        IT[a]=min(IT[a+a],IT[a+a+1]);
    }
}
int get_LCP(int a, int b){
    if(a>b)swap(a,b);
    int t = Low[b-a];
    return min(LCP[a][t], LCP[b-(1<<t)][t]);
}
pii Range(int a, int l){
    int b = 1, e = a-1, mid, r1 = a, r2 = a;
    while(b<=e){
        mid=(b+e)>>1;
        if(get_LCP(mid,a)>=l){
            r1=mid;
            e=mid-1;
        }
        else b=mid+1;
    }
    b = a+1, e = n;
    while(b<=e){
        mid=(b+e)>>1;
        if(get_LCP(a,mid)>=l){
            r2=mid;
            b=mid+1;
        }
        else e=mid-1;
    }
    return pii(r1,r2);
}
int Min(int b, int e){
    b+=SZ,e+=SZ;
    int r = 1e9;
    while(b<=e){
        r=min(r,min(IT[b],IT[e]));
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
int Calc(int a){
    int c = 1, L = 1;
    while(1){
        pii tp = Range(Rank[a], L);
        int t = Min(tp.first, tp.second);
        if(t>n)return c;
        int l = get_LCP(Rank[a],Rank[t]);
        c += (l-L)/(t-a)+1;
        L += t-a + (l-L)/(t-a)*(t-a);
    }
}
int main(){
    int i, res = 0;
    scanf("%d",&n);
    scanf("%s",p);
    Make_SA();
    Make_LCP();
    for(i=1;i<=n;i++)Ins(i,SA[i]);
    for(i=0;i<n;i++){
        Ins(Rank[i],1e9);
        res = max(res,Calc(i));
    }
    printf("%d\n",res);
}