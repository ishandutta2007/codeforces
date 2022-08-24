#include<cstdio>
#include<algorithm>
#define SZ 262144
using namespace std;
int n, m;
int C[101000], chk[101000], RC[101000];
long long S[101000];
struct point{
    int a, b;
    bool operator<(const point &p)const{
        return a<p.a;
    }
}w[101000];
struct Tree{
    long long S, M;
}IT[SZ+SZ];
void Add(int a, long long b){
    a += SZ;
    IT[a].S += b;
    IT[a].M = min(IT[a].S, 0ll);
    while(a!=1){
        a>>=1;
        IT[a].S=IT[a*2].S+IT[a*2+1].S;
        IT[a].M=min(IT[a*2].M,IT[a*2].S+IT[a*2+1].M);
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&C[i]);
    }
    int Mx = 0;
    for(i=n;i>=1;i--){
        if(Mx < C[i])Mx=C[i],chk[i]=1;
    }
    long long ss = 0;
    int tn = 0;
    for(i=1;i<=n;i++){
        ss += C[i];
        if(chk[i]){
            C[++tn] = C[i];
            S[tn] = ss;
            ss = 0;
        }
    }
    n = tn;
    for(i=1;i<=n;i++)Add(i*2-1,S[i]);
    for(i=1;i<=n;i++)RC[n+1-i]=C[i];
    for(i=0;i<m;i++)scanf("%d",&w[i].b);
    for(i=0;i<m;i++)scanf("%d",&w[i].a);
    sort(w,w+m);
    int res = 0;
    for(i=0;i<m;i++){
        int t = lower_bound(RC+1,RC+n+1,w[i].b) - RC;
        t = n+1-t;
        if(!t)continue;
        Add(t*2, -w[i].a);
        res++;
        if(IT[1].M < 0){
            Add(t*2, w[i].a);
            res--;
        }
    }
    printf("%d\n",res);
}