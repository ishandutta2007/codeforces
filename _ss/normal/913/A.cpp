#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    if (n>30) cout<<m; else cout<<(m&((1<<n)-1));
    return 0;
}