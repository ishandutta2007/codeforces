#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1,mod=998244353;

int main()
{
    ll w,h,ans=1;
    cin>>w>>h;
    for (ll i=1;i<=w+h;i++) ans=(ans*2)%mod;
    cout<<ans;
    return 0;
}