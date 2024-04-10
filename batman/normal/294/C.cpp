#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,m,a[N],fact[N],ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
    ans=fact[n-m];  
    for(int i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1);    
    a[m+1]=n+1;
    for(int i=1;i<=m+1;i++)
    {
        ll x=a[i]-a[i-1]-1;
        if(!x)
            continue;
        ans*=tavan(fact[x],MOD-2,MOD);
        ans%=MOD;
        if(i!=1 && i!=m+1)
            ans*=tavan(2,x-1,MOD),ans%=MOD;
    }   
    cout<<ans;
    return 0;
}