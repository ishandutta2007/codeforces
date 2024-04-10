#include<stdio.h>
#include<algorithm>
#include<set>
#define SZ 524288
using namespace std;
int n, ord1[501000], ord2[501000], SA[501000], LCP[501000], Rank[501000], C[501000], st[501000], IT[SZ+SZ+2];
int Next[501000][20];
set<int>Set;
struct AA{
    int a,b;
}w[501000];
char p[501000];
void Suffix_Array(){
    int i, MM = max(255,n), LL = 1, cc;
    for(i=0;i<n;i++){
        w[i].a=p[i],w[i].b=p[i+1];
    }
    while(1){
        for(i=0;i<=MM;i++)C[i]=0;
        for(i=0;i<n;i++)C[w[i].b]++;
        for(i=1;i<=MM;i++)C[i]+=C[i-1];
        for(i=0;i<n;i++)ord2[--C[w[i].b]] = i;
        for(i=0;i<=MM;i++)C[i]=0;
        for(i=0;i<n;i++)C[w[i].a]++;
        for(i=1;i<=MM;i++)C[i]+=C[i-1];
        for(i=n-1;i>=0;i--)ord1[--C[w[ord2[i]].a]] = ord2[i];
        cc = 0;
        for(i=0;i<n;i++){
            if(i==0||w[ord1[i]].a!=w[ord1[i-1]].a ||w[ord1[i]].b!=w[ord1[i-1]].b)cc++;
            Rank[ord1[i]] = cc;
        }
        LL*=2;
        if(LL>=n)break;
        for(i=0;i<n;i++){
            w[i].a = Rank[i];
            if(i+LL<n)w[i].b = Rank[i+LL];
            else w[i].b = 0;
        }
    }
}
void Ins(int a, int b){
    a+=SZ;
    IT[a] = b;
    while(a!=1){
        a>>=1;
        IT[a]=min(IT[a*2],IT[a*2+1]);
    }
}
void Make_LCP(){
    int i, x, t, y;
    for(i=0;i<n;i++)SA[Rank[i]] = i;
    t = 0;
    for(i=0;i<n;i++){
        x = Rank[i];
        t--;
        if(x==n)continue;
        y = SA[x+1];
        if(t<0)t=0;
        while(p[i+t]==p[y+t])t++;
        LCP[x] = t;
    }
    for(i=1;i<n;i++)Ins(i,LCP[i]);
}
void Pre(){
    int i, top = 0, j;
    for(i=0;i<=n;i++)Next[i][0] = -1;
    for(i=0;i<n;i++){
        if(p[i]=='('){
            st[++top] = i;
        }
        else{
            if(!top)continue;
            Next[st[top]][0] = i+1;
            top--;
        }
    }
    for(i=0;i<19;i++){
        for(j=0;j<=n;j++){
            if(Next[j][i]!=-1)Next[j][i+1]=Next[Next[j][i]][i];
            else Next[j][i+1] = -1;
        }
    }
}
int GetLCP(int b, int e){
    if(b>e)swap(b,e);
    e--;
    b+=SZ,e+=SZ;
    int r = n;
    while(b<=e){
        r = min(r, IT[b]);
        r = min(r, IT[e]);
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
long long Res;
int main(){
    int i, LL, tp, x, j;
    scanf("%d",&n);
    scanf("%s",p);
    Suffix_Array();
    Make_LCP();
    Pre();
    set<int>::iterator it;
    for(i=0;i<n;i++){
        LL = 0;
        if(!Set.empty()){
            it = Set.lower_bound(Rank[i]);
            if(it != Set.end()){
                tp = GetLCP(Rank[i], *it);
                LL = max(LL,tp);
            }
            if(it != Set.begin()){
                it--;
                tp = GetLCP(*it, Rank[i]);
                LL = max(LL, tp);
            }
        }
        Set.insert(Rank[i]);
        LL = i+LL+1;
        x = i;
        for(j=19;j>=0;j--){
            if(Next[x][j]!=-1 && Next[x][j] <LL)x = Next[x][j];
        }
        for(j=19;j>=0;j--){
            if(Next[x][j]!=-1){
                x = Next[x][j];
                Res += (1<<j);
            }
        }
    }
    printf("%lld\n",Res);
    return 0;
}