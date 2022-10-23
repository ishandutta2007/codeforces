#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
pii a[maxn];
int n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi;
    for (int i=1;i<=n;i++) cin>>a[i].se;
    sort(a+1,a+n+1);
    ll res=0;
    vector<ll> vl;
    for (int i=1;i<n;i++)
        if (a[i].fi==a[i+1].fi) vl.pb(a[i].fi);
    for (int i=1;i<=n;i++)
    {
        int check=0;
        for (int j=0;j<vl.size();j++)
            if ((a[i].fi & vl[j])==a[i].fi) check=1;
        if (check) res+=a[i].se;
    }
    cout<<res;
    return 0;
}