#include <bits/stdc++.h>
#define maxn 400400
#define pb insert
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
 
ll fat[maxn];

int main() {
    int n,mod;
    scanf("%d%d",&n,&mod);
    fat[0] =1;
    for(int i=1;i<maxn;i++){
        fat[i] = (fat[i-1]*i) % mod;
    }
    ll ans = 0;
    for(int t=1;t<=n;t++){
        ll ini = n-t+1;
        ini *= ini;
        ini %= mod;
        ini *= fat[t];
        ini %= mod;
        ini *= fat[n-t];
        ini %= mod;
        ans = (ans+ini) % mod;
    }
    printf("%lld\n",ans);
}