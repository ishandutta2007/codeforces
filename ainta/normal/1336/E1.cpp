#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
long long P[36];
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
int C[36][1<<15];
int CC[1<<15];
long long Res[38];
int main(){
    int i, j, k;
    scanf("%d%d",&n,&m);
    long long a;
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        Put(a);
    }
    vector<long long>V,VV;
    for(i=m-1;i>=0;i--){
        if(P[i]){
            V.push_back(P[i]);
            VV.push_back(i);
        }
    }
    int sz = V.size();
    int AA = min(sz,23);
    int BB = sz-AA;
    int LB = 0;
    if(BB) LB = VV[AA] + 1;
    for(i=0;i< (1<<AA);i++){
        long long t=0;
        for(j=0;j<AA;j++){
            if((i>>j)&1)t^=V[j];
        }
        int cc=0;
        for(j=LB;j<m;j++){
            if((t>>j)&1)cc++;
        }
        C[cc][t&((1<<LB)-1)]++;
    }
    for(i=0;i<(1<<15);i++)for(j=0;j<15;j++)CC[i]+=(i>>j)&1;
    for(i=0;i<(1<<BB);i++){
        int t=0;
        for(j=0;j<BB;j++){
            if((i>>j)&1)t^=V[AA+j];
        }
        for(k=0;k<=m-LB;k++){
            for(j=0;j<(1<<(LB));j++){
                Res[k+CC[j^t]]+=C[k][j];
            }
        }
    }
    long long t=1, Mod = 998244353;
    for(i=0;i<n-sz;i++){
        t=t*2%Mod;
    }
    for(i=0;i<=m;i++){
        printf("%lld ",Res[i]*t%Mod);
    }
}