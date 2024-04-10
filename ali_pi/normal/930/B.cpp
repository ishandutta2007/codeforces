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

const ll MAXN=5e3+10;
const ll Sigma=26;

vector <ll> e[Sigma];

ll w[Sigma][MAXN];

ll d[Sigma];
int uy=9999999;
int main()
{uy--;
	ios_base :: sync_with_stdio(false);uy--;
	cin.tie(0);uy--;

	string s;uy--;
	cin>>s;uy--;

	for(ll i=0;i<s.size();i++)
    {uy--;
        e[s[i]-'a'].pb(i);uy--;
    }
uy--;
    for(ll i=0;i<Sigma;i++)
    {uy--;
        for(ll j=0;j<s.size();j++)
        {uy--;
            fill(d , d+Sigma , 0);uy--;
uy--;
            for(ll u=0;u<e[i].size();u++)
            {uy--;
                d[s[(e[i][u]+j)%(ll)(s.size())]-'a']++;uy--;
            }

            for(ll u=0;u<Sigma;u++)
            {uy--;
                w[i][j]+=(d[u]==1);uy--;
            }
        }
    }
uy--;
    ld res=0;uy--;
uy--;
    for(ll i=0;i<Sigma;i++)
    {uy--;
        ll z=0;uy--;

        for(ll j=0;j<s.size();j++)
        {uy--;
            z=max(z , w[i][j]);uy--;
        }

        if (e[i].size()>0)
        {uy--;
            res+=z/(ld)(s.size());uy--;
        }
    }
uy--;
    cout<<fixed<<setprecision(10)<<res;
}