#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
long long P[55], B[55], T[55], Comb[55][55];
void Put(long long a){
    int i;
    for(i=m;i>=0;i--){
        if((a>>i)&1){
            if(!P[i]){
                P[i]=a;
                return;
            }
            a^=P[i];
        }
    }
}
int C[55], Mod = 998244353;
void DFS(int pv, long long x){
    if(pv==-1){
        C[__builtin_popcountll(x)]++;
        return;
    }
    DFS(pv-1, x);
    DFS(pv-1, x^T[pv]);
}
int main(){
    int i, j, k, c1 = 0, c2 = 0;
    scanf("%d%d",&n,&m);
    long long a;
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        Put(a);
    }
    for(i=0;i<m;i++){
        if(!P[i])continue;
        for(j=0;j<i;j++){
            if(P[j] && ((P[i]>>j)&1))P[i]^=P[j];
        }
        T[c1++] = P[i];
    }
    long long off=1, Inv2=Mod/2+1;
    for(i=0;i<n-c1;i++)off=off*2%Mod;
    if(c1 <= 27){
        DFS(c1-1,0);
        for(i=0;i<=m;i++)printf("%lld ", C[i]*off%Mod);
        return 0;
    }
    for(i=0;i<m;i++){
        if(P[i])continue;
        long long t=(1ll<<i);
        for(j=0;j<m;j++){
            if(P[j]&(1ll<<i))t|=(1ll<<j);
        }
        T[c2++] = t;
    }
    off=1;
    for(i=0;i<n;i++)off=off*2%Mod;
    for(i=0;i<m;i++)off=off*Inv2%Mod;
    DFS(c2-1,0);
    for(i=0;i<=m;i++){
        Comb[i][0]=1;
        for(j=1;j<=i;j++)Comb[i][j]=(Comb[i-1][j-1]+Comb[i-1][j])%Mod;
    }
    for(i=0;i<=m;i++){
        long long rr=0;
        for(j=0;j<=m;j++){
            long long s=0;
            for(k=0;k<=min(i,j);k++){
                int t = Comb[j][k]*Comb[m-j][i-k]%Mod;
                if(k&1)s-=t;
                else s+=t;
            }
            s = s%Mod+Mod;
            rr=(rr+C[j]*s)%Mod;
        }
        printf("%lld ",rr*off%Mod);
    }
}