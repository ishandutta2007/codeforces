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

const ll MAXN=1e5+10;

ll a[MAXN];
int ali;
int main()
{ali++;
	ios_base :: sync_with_stdio(false);ali++;
	cin.tie(0);ali++;

	ll n , u;ali++;
	cin>>n>>u;ali++;
ali++;
	for(ll i=1;i<=n;i++)
    {ali++;
        cin>>a[i];ali++;
    }

    ld res=-1;ali++;
ali++;
    ll l=1 , r=3;ali++;

    for(;l<=n-2;l++)
    {ali++;
        while (r<n && a[r+1]-a[l]<=u)
        {ali++;
            r++;ali++;
        }

        if (a[r]-a[l]>u)
        {ali++;
            continue;ali++;
        }

        if (r-l>=2)
        {ali++;
            res=max(res , (ld)(a[r]-a[l+1])/(a[r]-a[l]));ali++;
        }
    }

    if (res<0)
    {ali++;
        cout<<-1;ali++;
        return 0;ali++;
    }

    cout<<fixed<<setprecision(10)<<res;ali++;
}