#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
	int n,m;
	cin>>n>>m;
	if(n>3 && m>3)
	{
		cout<<"-1\n";return 0;
	}
	if(n<2 || m<2)
	{
		cout<<0<<"\n";return 0;
	}
	vector<vector<char>> v(n,vector<char>(m));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>v[i][j];
	vector<vector<char>> a=v;
	if(n>3)
	{
		a.resize(m);
		for(int i=0;i<m;++i)
			a[i].resize(n);
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				a[i][j]=v[j][i];
			}
		}
		swap(n,m);
		/*for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				cout<<a[i][j];
			cout<<"\n";
		}*/
	}
	if(n==2)
	{
		vector<vector<ll>> dp(m,vector<ll>(2));
		int x=a[0][0]-'0'+a[1][0]-'0';
		dp[0][0]=(x%2)!=0;
		dp[0][1]=(x%2)!=1;
		for(int i=1;i<m;++i)
		{
			int y=a[0][i]-'0'+a[1][i]-'0';
			if(y&1)
				dp[i][1]=dp[i-1][0],dp[i][0]=dp[i-1][1]+1;
			else
				dp[i][0]=dp[i-1][1],dp[i][1]=dp[i-1][0]+1;
		}
		cout<<min(dp[m-1][0],dp[m-1][1])<<"\n";
		return 0;
	}
	ll dp[m][2][2];
	for(int i=0;i<m;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				dp[i][j][k]=INF;
	int x=a[0][0]+a[1][0]+a[2][0]-'0'-'0'-'0';
	assert(n==3);
	for(int i=0;i<(1<<3);++i)
	{
		int x=a[0][0]+a[1][0]-'0'-'0';
		x%=2;
		int y=a[2][0]+a[1][0]-'0'-'0';
		y%=2;
		if(i&1)
			x^=1;
		if(i&(1<<1))
			x^=1,y^=1;
		if(i&(1<<2))
			y^=1;
		amin(dp[0][x][y],popcount(i));
	}
	//cout<<dp[1][1][1]<<"\n";
	for(int ix=1;ix<m;++ix)
	{
		for(int i=0;i<(1<<3);++i)
		{
		int x=a[0][ix]+a[1][ix]-'0'-'0';
		x%=2;
		int y=a[2][ix]+a[1][ix]-'0'-'0';
		y%=2;
		if(i&1)
			x^=1;
		if(i&(1<<1))
			x^=1,y^=1;
		if(i&(1<<2))
			y^=1;
		amin(dp[ix][x][y],popcount(i)+dp[ix-1][x^1][y^1]);
		}
	}
	ll ans=min({dp[m-1][0][1],dp[m-1][0][0],dp[m-1][1][1],dp[m-1][1][0]});
	if(ans==INF)
		cout<<-1;
	else
		cout<<ans;
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
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}