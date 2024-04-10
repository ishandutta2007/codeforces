#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 105;
int a[N][N];

struct node
{
	int x[3],y[3];
};

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
    	for(int j=1;j<=m;++j)
    	{
    		char c;
    		cin>>c;
    		a[i][j] = c-'0';
    	}
    }
    vector<node> v;
    for(int i=1;i<n;++i)
    {
    	for(int j=1;j<=m;++j)
    	{
    		node u;
    		if(a[i][j]==0)
    			continue;
    		u.x[0] = i,u.y[0] = j;
    		if(j==m)
    		{
    			u.x[0]=i,u.y[0]=m,u.x[1]=i+1,u.y[1]=m,u.x[2]=i+1,u.y[2]=m-1;
    			a[i+1][j]^=1,a[i+1][j-1]^=1;
    		}
    		else if(a[i][j+1]==1)
    		{
    			u.x[1]=i,u.y[1]=j+1,u.x[2]=i+1,u.y[2]=j;
    			a[i+1][j]^=1;
    			a[i][j+1]^=1;
    		}
    		else
    		{
    			u.x[1]=i+1,u.y[1]=j,u.x[2]=i+1,u.y[2]=j+1;
    			a[i+1][j]^=1,a[i+1][j+1]^=1;
    		}
    		v.pb(u);
    	}
    }
    assert(ans<=(n-1)*m);
    for(int i=1;i<=m-1;i+=2)
    {
    	if(a[n][i]==1 && a[n][i+1]==1)
    	{
    		node u;
    		u.x[0] = n,u.y[0] = i,u.x[1] = u.x[2] = n-1,u.y[1] = i,u.y[2] = i+1;
    		v.pb(u);
    		u.y[0] = i+1;
    		v.pb(u);
    	}
    	else if(a[n][i]==0 && a[n][i+1]==1)
    	{
    		node u;
    		u.x[0] = n-1,u.y[0]=i,u.x[1]=n,u.y[1]=i,u.x[2]=n,u.y[2]=i+1;
    		v.pb(u);
    		u.x[0] = n-1,u.y[0] = i+1;
    		v.pb(u);
    		u.x[0] = n-1,u.y[0]=i,u.x[1]=n-1,u.y[1]=i+1,u.x[2]=n,u.y[2]=i+1;
    		v.pb(u);
    	}
    	else if(a[n][i]==1 && a[n][i+1]==0)
    	{
    		node u;
    		u.x[0] = n-1,u.y[0]=i,u.x[1]=n,u.y[1]=i,u.x[2]=n,u.y[2]=i+1;
    		v.pb(u);
    		u.x[0] = n-1,u.y[0] = i+1;
    		v.pb(u);
    		u.x[0] = n-1,u.y[0]=i,u.x[1]=n-1,u.y[1]=i+1,u.x[2]=n,u.y[2]=i;
    		v.pb(u);	
    	}
    }
    if(m&1)
    {
    	if(a[n][m]==1)
    	{
    		node u;
    		u.x[0] = n-1,u.y[0]=m-1,u.x[1]=n,u.y[1]=m-1,u.x[2]=n,u.y[2]=m;
    		v.pb(u);
    		u.x[0] = n-1,u.y[0] = m;
    		v.pb(u);
    		u.x[0] = n-1,u.y[0]=m-1,u.x[1]=n-1,u.y[1]=m,u.x[2]=n,u.y[2]=m;
    		v.pb(u);
    	}
    }
	ans = sz(v);
	cout<<ans<<"\n";
	assert(ans<=3*n*m);
	for(auto j:v)
	{
		for(int i=0;i<3;++i)
			cout<<j.x[i]<<" "<<j.y[i]<<" ";
		cout<<"\n";
	}
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}