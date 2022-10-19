#include <bits/stdc++.h>
#define maxn 200200
#define mod 998244353
#define pii pair<int,int>
#define pb push_back
#define ll long long
using namespace std;

ll ans[maxn];
ll ss[maxn];
int x[maxn];
int y[maxn];
int st[maxn];

int main(){
    
    int n;
    scanf("%d",&n);
    
    ll sum = 0, tot = 0 ;
    
    for(int i=0;i<n;i++){
        
        scanf("%d%d%d",x+i,y+i,st+i);
        
        int p = lower_bound(x,x+i,y[i]) - x;
        
        ans[i] = x[i] - y[i] + sum;
        if(p) ans[i] -= ss[p-1];
        ans[i] = (ans[i]%mod+mod)%mod;
        
        ss[i] = ans[i];
        if(i) ss[i] += ss[i-1];
        ss[i] %= mod;
        
        if(st[i]) tot += ans[i];
        if(i == n-1) tot += x[i] + 1;
        tot %= mod;
        
        sum = (sum+ans[i]) % mod;
        
    }
    
    printf("%lld\n",tot);
    
}