#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

lli n;
int vis[100010];

lli power(lli a,lli p){
    lli res=1;
    while(p){
        if(p&1)res=res*a;
        a=a*a;
        p>>=1;
    }
    return res;
}
int main(){
    vector<int> prime;
    for(int i=2;i<=100000;i++)if(!vis[i]){
        for(lli j=1ll*i*i;j<=100000;j+=i)vis[j]=1;
        prime.push_back(i);
    }

    lli ans=0;
    scanf("%lld",&n);
    if(n%2==0){
        printf("%lld\n",n/2);
        return 0;
    }
    for(int i=0;i<sz(prime);i++){
        if(n%prime[i]==0){
            n-=prime[i];
            printf("%lld\n",n/2+1);
            return 0;
            
        }
    }
    printf("1\n");

    return 0;
}