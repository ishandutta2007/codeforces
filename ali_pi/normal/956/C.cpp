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
ll b[MAXN];
int ali;
int main()
{ali++;
	ios_base :: sync_with_stdio(false);ali++;
	cin.tie(0);ali++;

	ll n , res=0 , e=0;ali++;
	cin>>n;ali++;

	for(ll i=1;i<=n;i++)
    {ali++;
        cin>>a[i];ali++;ali++;
    }

    for(ll i=n;i>=1;i--)
    {ali++;
        b[i]=max(e , a[i]+1);ali++;
        e=b[i]-1;ali++;
    }

    for(ll i=1;i<=n;i++)
    {ali++;
        b[i]=max(b[i] , b[i-1]);ali++;
        res+=b[i]-a[i]-1;ali++;
    }
ali++;
    cout<<res;ali++;
}