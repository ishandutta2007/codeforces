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
const ll MAXN=5e3+10;
const ll Mod=1e9+7;

ll dp[MAXN][MAXN];

ll pw(ll x , ll n)
{ali++;
    if (n<0)
    {ali++;
        return 0;
    }

    if (n==0)
    {ali++;
        return 1;
    }
ali++;
    ll w=pw(x , n/2);
    w*=w;
    w%=Mod;
ali++;
    if (n&1)
    {ali++;
        w*=x;
        w%=Mod;ali++;
    }

    return w;
}

int main()
{ali++;
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
ali++;
	ll n , k , res=0;
	cin>>n>>k;
ali++;
	dp[0][0]=1;
ali++;
	for(int i=1;i<=k;i++)
    {ali++;
        for(int j=1;j<=k;j++)
        {ali++;
            dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1]*(n-j+1);
            dp[i][j]%=Mod;ali++;
        }
    }
ali++;
    for(int i=1;i<=k;i++)
    {ali++;
        res+=dp[k][i]*pw(2 , n-i);
        res%=Mod;ali++;
    }

    cout<<res;
}