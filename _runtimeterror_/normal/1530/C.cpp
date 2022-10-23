// Har Har Mahadev
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    ll x = 0,y = 0;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i)
    {
    	cin >> a[i];
    }
    for(int i=0;i<n;++i)
    {
    	cin >> b[i];
    }
    // at max 4n stages
    sort(all(a)),sort(all(b));
    reverse(all(b));
    for(int i=0;i<n-n/4;++i)
    	x += a[n-1-i], y += b[i];
    if(x >= y)
    {
    	cout << "0\n";
    	return 0;
    }
    int tmp = n;
    int l = n/4,r = n - n/4;
    while(true)
    {
    	++n;
    	a.push_back(100);
    	b.push_back(0);
    	if(n % 4 == 0)
    	{
    		x += 100 - a[l];
    		++l;
    	}	
    	else
    	{
    		x += 100;
    		y += b[r];
    		++r;
    	}
    	// cout << x << " " << y << "\n";
    	if(x >= y)
    	{
    		cout << n - tmp << "\n";
    		return 0;
    	}
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