#include<cstdio>
#include<algorithm>
#define N_ 1010000
#define MM 1000000
using namespace std;
long long C[N_], S[N_], S2[N_], Mod = 1000000007, P[N_], SS[N_], po[N_], ss;
int w[N_], n, cnt;
struct point{
    int a, c;
}E[64];
void Do(){
    int i, t = 1, j;
    for(i=0;i<6;i++){
        for(j=MM-1;j>=t;j--){
            if((j/t)%10==0)continue;
            C[j-t]=(C[j-t]+C[j])%Mod;
            S[j-t]=(S[j-t]+S[j])%Mod;
            S2[j-t]=(S2[j-t]+S2[j])%Mod;
        }
        t*=10;
    }
}
void DFS(int a, int pv, int s, int ck){
    if(pv==MM){
        if(ck==1)ss += SS[a+s];
        else ss += Mod - SS[a+s];
        return;
    }
    DFS(a,pv*10,s,ck);
    if((a/pv)%10!=9)DFS(a,pv*10,s+pv,-ck);
}
int main(){
    int i;
    scanf("%d",&n);
    po[0]=1;
    for(i=1;i<=n;i++)po[i]=po[i-1]*2%Mod;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        C[w[i]]++;
        S[w[i]]=(S[w[i]]+w[i])%Mod;
        S2[w[i]]=(S2[w[i]]+1ll*w[i]*w[i])%Mod;
    }
    Do();
    for(i=0;i<MM;i++){
        if(!C[i])continue;
        long long t = (S[i]*S[i]-S2[i]+Mod)%Mod;
        P[i] = po[C[i]-1] * S2[i]%Mod;
        if(C[i]!=1)P[i]=(P[i]+po[C[i]-2] * t)%Mod;
    }
    long long res = 0;
    for(i=MM-1;i>=0;i--){
        ss = 0;
        DFS(i,1,0,-1);
        ss %= Mod;
        SS[i] = P[i];
        P[i] = (P[i]-ss+Mod)%Mod;
        res ^= (P[i]*i);
    }
    printf("%lld\n",res);
}