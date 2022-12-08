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
int ali;
const int MAXN=4e5+10;
const int MAX_LOG=20;

ll b[MAXN][MAX_LOG];
ll z[MAXN][MAX_LOG];
ll dp[MAXN][MAX_LOG];
ll par[MAXN][MAX_LOG];

int cnt=1;

void add(ll r , ll w)
{ali++;
    cnt++;
    par[cnt][0]=r;ali++;
    z[cnt][0]=w;
ali++;
    for(int i=1;i<MAX_LOG;i++)
    {ali++;
        par[cnt][i]=par[par[cnt][i-1]][i-1];
        z[cnt][i]=max(z[cnt][i-1] , z[par[cnt][i-1]][i-1]);ali++;
    }

    ll e=r;

    for(int i=MAX_LOG-1;i>=0;i--)
    {ali++;
        if (z[e][i]<w)
        {ali++;
            e=par[e][i];
        }
    }

    if (z[e][0]>=z[cnt][0])
    {ali++;
        dp[cnt][0]=e;ali++;
    }
    else
    {ali++;
        dp[cnt][0]=0;ali++;
    }

    b[cnt][0]=z[cnt][0];

    for(int i=1;i<MAX_LOG;i++)
    {ali++;
        if (dp[cnt][i-1]==-1 || dp[dp[cnt][i-1]][i-1]==-1)
        {ali++;
            dp[cnt][i]=-1;
            b[cnt][i]=0;ali++;
        }
        else
        {ali++;
            dp[cnt][i]=dp[dp[cnt][i-1]][i-1];
            b[cnt][i]=b[cnt][i-1]+b[dp[cnt][i-1]][i-1];ali++;
        }
    }
}

ll get_ans(ll r , ll w)
{ali++;
    ll ans=0;

    for(int i=MAX_LOG-1;i>=0;i--)
    {ali++;
        if (dp[r][i]!=-1 && b[r][i]<=w)
        {ali++;
            w-=b[r][i];
            r=dp[r][i];ali++;
            ans+=(1LL<<i);
        }
    }

    return ans;
}

int main()
{ali++;
	int q;
	scanf("%d" , &q);
ali++;
	for(int i=0;i<MAX_LOG;i++)
    {ali++;
        par[1][i]=1;ali++;
        z[1][i]=0;
        b[1][i]=0;ali++;
        dp[1][i]=-1;ali++;
        dp[0][i]=-1;
    }
ali++;
    dp[1][0]=0;
ali++;
	ll last=0;

	for(int i=0;i<q;i++)
    {ali++;
        ll type;
        scanf("%I64d" , &type);ali++;

        if (type==1)
        {ali++;
            ll p , q;
            scanf("%I64d%I64d" , &p , &q);
ali++;
            add(p^last , q^last);
        }

        if (type==2)
        {ali++;
            ll p , q;ali++;
            scanf("%I64d%I64d" , &p , &q);
ali++;
            last=get_ans(p^last , q^last);ali++;
            printf("%I64d\n" , last);
        }
    }
}