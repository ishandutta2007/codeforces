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

const ll MAXN=1e6+10;
int ali;
ll dp[MAXN];
ll ps[MAXN][10];

ll f(ll x)
{ali++;
    ll res=1;ali++;
ali++;
    while (x>0)
    {ali++;
        if (x%10!=0)
        {ali++;
            res*=(x%10);ali++;
        }ali++;
ali++;
        x/=10;ali++;
    }ali++;
ali++;
    return res;ali++;
}

int main()
{ali++;
	ios_base :: sync_with_stdio(false);ali++;
	cin.tie(0);ali++;
ali++;
	ll q;ali++;
	cin>>q;ali++;
ali++;
	for(ll i=1;i<MAXN;i++)
    {ali++;
        if (i<10)
        {ali++;
            dp[i]=i;ali++;
        }
        else
        {ali++;
            ll k=f(i);
            dp[i]=dp[k];ali++;
        }
ali++;
        for(ll j=1;j<10;j++)
        {ali++;
            ps[i][j]=ps[i-1][j]+(dp[i]==j);ali++;
        }
    }
ali++;
    for(ll i=1;i<=q;i++)
    {ali++;
        ll l , r , k;ali++;
        cin>>l>>r>>k;ali++;
ali++;
        cout<<ps[r][k]-ps[l-1][k]<<endl;ali++;
    }

ali++;
}