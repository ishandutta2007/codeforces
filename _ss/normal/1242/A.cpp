#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    for (ll i=2;i*i<=n;i++)
        if (n%i==0)
        {
            while (n%i==0) n/=i;
            if (n>1) cout<<1;
            else cout<<i;
            return 0;
        }
    cout<<n;
    return 0;
}