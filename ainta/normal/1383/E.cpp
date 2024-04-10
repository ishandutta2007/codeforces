#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1100000
using namespace std;
char p[N_];
int C[N_], n, V[N_], Nxt[N_], D[N_], Mod = 1000000007, U[2];
int NN[N_][2];
void Solve(){
    int i;
    scanf("%s",p+1);
    for(i=1;p[i];i++){
        if(p[i]=='0')C[i]=C[i-1]+1;
        else C[i]=0;
    }
    n=i-1;
    if(C[n]==n){
        printf("%d\n",n);
        return;
    }
    int bb=0,ee=0;
    for(i=1;i<=n;i++){
        if(p[i]=='1'){
            if(!bb)bb=i;
            ee=i;
        }
    }
    for(i=ee;i>=bb;i--){
        if(p[i]=='0'){
            Nxt[i] = V[C[i]+1];
        }
        NN[i][0]=U[0],NN[i][1]=U[1];
        V[C[i]]=i;
        if(p[i]=='0')U[0]=i;
        else U[1]=i;
    }
    D[bb] = 1;
    for(i=bb;i<=ee;i++){
        if(p[i]=='0'){
            if(Nxt[i]){
                D[Nxt[i]]=(D[Nxt[i]]+D[i])%Mod;
            }
            if(NN[i][1]){
                D[NN[i][1]]=(D[NN[i][1]]+D[i])%Mod;
            }
        }
        else{
            if(NN[i][0]){
                D[NN[i][0]]=(D[NN[i][0]]+D[i])%Mod;
            }
            if(NN[i][1]){
                D[NN[i][1]]=(D[NN[i][1]]+D[i])%Mod;
            }
        }
    }
    long long res=0;
    for(i=bb;i<=ee;i++){
        if(p[i]=='1')res+=D[i];
    }
    res%=Mod;
    res=res*bb%Mod*(n-ee+1)%Mod;
    printf("%lld\n",res);

}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}