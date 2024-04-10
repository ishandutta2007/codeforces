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

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if (n+m-2<k) cout<<-1;
    else
    {
        ll t1,t2;
        if (n<k+1) t1=m/(k-n+2);
        else t1=n/(k+1)*m;
        if (m<k+1) t2=n/(k-m+2);
        else t2=m/(k+1)*n;
        cout<<max(t1,t2);
    }
    return 0;
}