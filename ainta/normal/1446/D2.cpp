#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
int n, w[201000], C[201000], U[401000];
int S[201000];
vector<int>G[201000];
struct Tree{
    int Mx[SZ+SZ], K[SZ+SZ], Mn[SZ+SZ];
    void Add2(int nd, int x){
        Mn[nd]+=x,Mx[nd]+=x,K[nd]+=x;
    }
    void Spread(int nd){
        Add2(nd*2,K[nd]);
        Add2(nd*2+1,K[nd]);
        K[nd]=0;
    }
    void UDT(int nd){
        Mx[nd] = max(Mx[nd*2],Mx[nd*2+1]);
        Mn[nd] = min(Mn[nd*2],Mn[nd*2+1]);
    }
    void Add(int nd, int b, int e, int s, int l, int x){
        if(s>l)return;
        if(s<=b && e<=l){
            Add2(nd,x);
            return;
        }
        Spread(nd);
        int m = (b+e)>>1;
        if(s<=m)Add(nd*2,b,m,s,l,x);
        if(l>m)Add(nd*2+1,m+1,e,s,l,x);
        UDT(nd);
    }
    int Max(int nd, int b, int e, int s, int l){
        if(s>l)return -9999999;
        if(s<=b&&e<=l)return Mx[nd];
        Spread(nd);
        int m = (b+e)>>1;
        int r = -99999999;
        if(s<=m)r=max(r,Max(nd*2,b,m,s,l));
        if(l>m)r=max(r,Max(nd*2+1,m+1,e,s,l));
        UDT(nd);
        return r;
    }
    int Right(int nd, int b, int e, int x){
        if(Mn[nd]>x || Mx[nd]<x)return -1;
        if(b==e)return b;
        Spread(nd);
        int m = (b+e)>>1;
        int r = Right(nd*2+1,m+1,e,x);
        if(r==-1)r = Right(nd*2,b,m,x);
        return r;
    }
    int Left(int nd, int b, int e, int x){
        if(Mn[nd]>x || Mx[nd]<x)return n+1;
        if(b==e)return b;
        Spread(nd);
        int m = (b+e)>>1;
        int r = Left(nd*2,b,m,x);
        if(r==n+1)r = Left(nd*2+1,m+1,e,x);
        return r;
    }
}T;
void Solve(){
    int i, j;
    scanf("%d",&n);
    int pv, M=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        G[w[i]].push_back(i);
        C[w[i]]++;
    }
    for(i=1;i<=n;i++){
        if(M<C[i]){
            M=C[i];
            pv = i;
        }
    }
    for(i=1;i<=n;i++){
        if(w[i]==pv){
            T.Add(1,0,n,i,n,1);
        }
    }
    int res = 0;
    for(i=1;i<=n;i++){
        if(i==pv || G[i].empty())continue;
        for(auto &x : G[i]){
            T.Add(1,0,n,x,n,-1);
        }
        int c = G[i].size();
        int LL = 1e9;
        for(j=c-1;j>=0;j--){
            int x = G[i][j];
            int t = T.Max(1,0,n,x,x);
            int MM = T.Max(1,0,n,0,x);
            MM = min(MM,LL);
            if(MM>=t){
                for(int k=MM;k>=t;k--){
                    int rr = T.Right(1,0,n,k), ll = T.Left(1,0,n,k);
                    res=max(res,rr-ll);
                }
                LL=t;
            }
        }
        for(auto &x : G[i]){
            T.Add(1,0,n,x,n,1);
        }
    }
    printf("%d\n",res);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}