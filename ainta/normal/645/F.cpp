#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010000];
int n, K, Q, C[1010000];
long long Mod = 1000000007, F[310000], InvF[310000], Res, D[1010000];
long long Pow(long long a, long long b){
    long long r = 1;
    while(b){
        if(b%2)r=r*a%Mod;
        a=a*a%Mod;b/=2;
    }
    return r;
}
long long Comb(int a, int b){
    if(a<b)return 0;
    return F[a]*InvF[b]%Mod*InvF[a-b]%Mod;
}
void Ins(int a){
    int i, x, j, y, t;
    for(i=E[a].size()-1;i>=0;i--){
        x = E[a][i];
        D[x] = Comb(C[x], K-1);
        y = a/x;
        for(j=1;j<E[y].size();j++){
            t = E[y][j];
            D[x] = D[x] - D[t*x]+ Mod;
        }
        D[x]%=Mod;
        Res = (Res + D[x]*x)%Mod;
    }
    for(i=0;i<E[a].size();i++)C[E[a][i]]++;
}
int main(){
    int i, j, a, x;
    for(i=1;i<=1000000;i++){
        for(j=i;j<=1000000;j+=i)E[j].push_back(i);
    }
    F[0]=InvF[0]=1;
    for(i=1;i<=200000;i++){
        F[i]=F[i-1]*i%Mod;
        InvF[i]=Pow(F[i],Mod-2);
    }
    scanf("%d%d%d",&n,&K,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        Ins(a);
    }
    for(i=1;i<=Q;i++){
        scanf("%d",&a);
        Ins(a);
        printf("%lld\n",Res);
    }
}