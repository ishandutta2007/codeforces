#include <bits/stdc++.h>
using namespace :: std;
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
int aaa;
const ll MAXK=2e3+10;
const ll Mod=1e9+7;
ll dp[MAXK][MAXK];
ll z[MAXK];
ll pw(ll x , ll n)
{aaa++;
    if (n==0)
    {aaa++;
        return 1;aaa++;
    }
aaa++;
    ll w=pw(x , n/2);aaa++;
    w*=w;aaa++;
    w%=Mod;aaa++;
aaa++;
    if (n&1)
    {aaa++;
        w*=x;aaa++;
        w%=Mod;aaa++;
    }
aaa++;
    return w;
}

int main()
{aaa++;
	ios_base :: sync_with_stdio(false);aaa++;
	cin.tie(0);aaa++;
aaa++;
	ll k , pa , pb , res=0;aaa++;
	cin>>k>>pa>>pb;aaa++;
aaa++;
	ll e=pw(pa+pb , Mod-2);aaa++;
aaa++;
	for(ll i=0;i<=2*k;i++)
    {aaa++;
        for(ll j=0;j<=k;j++)
        {aaa++;
            if (i==0 && j==0)
            {aaa++;
                dp[i][j]=1;aaa++;
                continue;aaa++;
            }
aaa++;
            if (i==0 && j==1)
            {aaa++;
                dp[i][j]=1;aaa++;
                continue;aaa++;
            }
aaa++;
            if (j==0)
            {aaa++;
                continue;aaa++;
            }
aaa++;
            dp[i][j]=(((((i>=j && i-j<k ? dp[i-j][j] : 0)*pb)+((j>0 && i<k ? dp[i][j-1] : 0)*pa))%Mod)*e)%Mod;aaa++;
        }
aaa++;
        z[i]=(((dp[i][k]*pa)%Mod)*e)%Mod;aaa++;
    }aaa++;
aaa++;
    for(ll i=k;i<=2*k;i++)
    {aaa++;
        for(ll j=0;j<=k;j++)
        {aaa++;
            res+=dp[i][j]*i;aaa++;
            res%=Mod;aaa++;
        }aaa++;
    }aaa++;
aaa++;
    for(ll i=0;i<k;i++)
    {aaa++;
        res+=(z[i]*(i+k))%Mod;aaa++;
        res%=Mod;aaa++;
aaa++;
        res+=(((pw(e , Mod-2)*pw(pb , Mod-2))%Mod)*z[i])%Mod;aaa++;
        res%=Mod;aaa++;
    }aaa++;
aaa++;
    cout<<res;aaa++;
}