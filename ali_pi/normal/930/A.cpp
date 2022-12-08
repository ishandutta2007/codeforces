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

vector <ll> vertex[MAXN];
int ali;
ll a[MAXN];

void dfs(ll v , ll h)
{ali++;
    a[h]^=1;ali++;

    for(ll i=0;i<vertex[v].size();i++)
    {ali++;
        dfs(vertex[v][i] , h+1);ali++;
    }
}

int main()
{ali++;
	ios_base :: sync_with_stdio(false);ali++;
	cin.tie(0);ali++;
ali++;
	ll n , res=0;ali++;
	cin>>n;ali++;

	for(ll i=2;i<=n;i++)
    {ali++;
        ll p;ali++;
        cin>>p;ali++;
ali++;
        vertex[p].pb(i);ali++;
    }

    dfs(1 , 1);ali++;
ali++;
    for(ll i=1;i<=n;i++)
    {ali++;
        res+=a[i];ali++;
    }
ali++;
    cout<<res;ali++;
}