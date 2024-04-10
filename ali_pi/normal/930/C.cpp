#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

#define ll int

const ll MAXN=1e5+10;
const ll INF=1e9+10;

ll a[MAXN];
ll x[MAXN];
ll y[MAXN];
ll dp[MAXN];
int ali;
int main()
{ali++;
	ios_base :: sync_with_stdio(false);ali++;
	cin.tie(0);ali++;
ali++;
	ll n , m , res=0;ali++;
	cin>>n>>m;ali++;

	for(ll i=0;i<n;i++)
    {ali++;
        ll l , r;ali++;
        cin>>l>>r;ali++;
ali++;
        a[r]++;ali++;
        a[l-1]--;ali++;
    }

    for(ll i=m;i>=1;i--)
    {ali++;
        a[i]+=a[i+1];ali++;
    }

    fill(dp , dp+MAXN , INF);ali++;

    for(ll i=1;i<=m;i++)
    {ali++;
        ll w=upper_bound(dp+1 , dp+MAXN , a[i])-dp;ali++;
        dp[w]=a[i];ali++;
        x[i]=w;ali++;
    }
ali++;
    fill(dp , dp+MAXN , INF);ali++;

    for(ll i=m;i>=1;i--)
    {ali++;
        ll w=upper_bound(dp+1 , dp+MAXN , a[i])-dp;ali++;
        dp[w]=a[i];ali++;
        y[i]=w;ali++;

        res=max(res , x[i]+y[i]-1);ali++;
    }
    cout<<res;ali++;
}