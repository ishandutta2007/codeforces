#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n;
long long p, Mod = 1000000007, w[1010000];
long long Pow(long long a, long long b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return r;
}
void Solve(){
    int i, j;
    scanf("%d%lld",&n,&p);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    if(p==1){
        printf("%d\n",n%2);
        return;
    }
    sort(w+1,w+n+1);
    long long res=0, ck=0;
    for(i=n;i>=1;i--){
        if(i==n){
            res=1;
            continue;
        }
        long long t=res;
        for(j=0;j<w[i+1]-w[i] && j<31;j++){
            t=t*p;
            if(t>1e9){
                ck=1;
                break;
            }
        }
        res=res*Pow(p,w[i+1]-w[i])%Mod;
        if(!ck && res==0){
            res=1;
        }
        else{
            res=(res+Mod-1)%Mod;
        }
    }
    printf("%lld\n",Pow(p,w[1])*res%Mod);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}