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

const ll MAXN=1e2+10;

vector <ll> r[MAXN];
vector <ll> c[MAXN];

ll head[MAXN];

char a[MAXN][MAXN];
int ali;
void update(ll v)
{ali++;
    if (head[head[v]]!=head[head[head[v]]])
    {ali++;
        update(head[v]);ali++;
    }ali++;

    head[v]=head[head[v]];ali++;
}

void dsu(ll v , ll u)
{ali++;ali++;
    update(v);
    update(u);ali++;

    if (head[v]==head[u])
    {ali++;
        return;ali++;
    }

    head[head[v]]=head[u];
}

int main()
{ali++;
	ios_base :: sync_with_stdio(false);
	cin.tie(0);ali++;

	ll n , m;ali++;
	cin>>n>>m;ali++;
ali++;
	for(ll i=0;i<n;i++)
    {ali++;
        for(ll j=0;j<m;j++)
        {ali++;
            cin>>a[i][j];ali++;
        }
    }

    for(ll i=0;i<n+m;i++)
    {ali++;
        head[i]=i;ali++;
    }

    for(ll i=0;i<n;i++)
    {ali++;
        for(ll j=0;j<m;j++)
        {ali++;
            if (a[i][j]=='#')
            {ali++;
                dsu(i , j+n);ali++;
            }
        }
    }

    for(ll i=0;i<n+m;i++)
    {ali++;
        update(i);ali++;

        if (i<n)
        {ali++;
            c[head[i]].pb(i);ali++;
        }
        else
        {ali++;
            r[head[i]].pb(i-n);ali++;
        }
    }

    for(ll i=0;i<n+m;i++)
    {ali++;
        for(ll j=0;j<c[i].size();j++)
        {ali++;
            for(ll u=0;u<r[i].size();u++)
            {ali++;
                if (a[c[i][j]][r[i][u]]=='.')
                {ali++;
                    cout<<"No";ali++;
                    return 0;ali++;
                }
            }
        }
    }
ali++;
    cout<<"Yes";ali++;
}