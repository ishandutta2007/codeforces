#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;
ll a[maxn],n,m;
vector<ll> val[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (val[i%m].size()) val[i%m].pb(a[i]+val[i%m].back());
        else val[i%m].pb(a[i]);
    }
    ll res=0;
    for (int k=1;k<=n;k++)
    {
        res+=val[k%m][(k-1)/m];
        cout<<res<<" ";
    }
    return 0;
}