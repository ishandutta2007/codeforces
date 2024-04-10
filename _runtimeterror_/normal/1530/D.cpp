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
    vector<int> a(n+1);
    set<int> s;
    vector<bool> vis(n+1,false);
    vector<int> in(n+1,0);
    for(int i=1;i<=n;++i)
    {
    	cin >> a[i];
    	s.insert(i);
    	++in[a[i]];
    }
    vector<int> z;
    for(int i=1;i<=n;++i)
    	if(in[i] == 0)
    		z.push_back(i);
    int ans = 0;
    vector<int> p(n+1);

    vector<vector<int>> chains;
    vector<vector<int>> single;
    vector<vector<int>> cmp;

    while(!s.empty())
    {
    	// debug(s,z);
    	auto u = *s.begin();
    	while(!z.empty() && vis[z.back()])
    		z.pop_back();
    	if(!z.empty())
    		u = z.back();
    	vector<int> t;
    	int st = u;
    	while(!vis[u])
    	{
    		vis[u] = true;
    		t.push_back(u);
    		s.erase(u);
    		u = a[u];
    	}
    	if(a[t.back()] == st)
    	{
    		cmp.push_back(t);
    	}
    	else if(sz(t) == 1)
    	{
    		single.push_back(t);
    	}
    	else
    		chains.push_back(t);
    	ans += sz(t) - 1;
    	if(a[t.back()] == st)
    		++ans;
    	// int n = sz(t);
    	// for(int i=0;i<n;++i)
    	// 	p[t[i]] = t[(i+1)%n];
    }
    if(sz(single) == 1)
    {
    	if(sz(chains) > 0)
    		chains.back().push_back(single[0][0]);
    	else
    	{
    		assert(false);
    	}
    }
    else
    {
    	vector<int> x;
    	for(auto &j:single)
    	{
    		assert(sz(j) == 1);
    		x.push_back(j[0]);
    	}
    	chains.push_back(x);
    }
    for(auto &j:chains)
    {
    	int n = sz(j);
    	for(int i=0;i<n;++i)
    		p[j[i]] = j[(i+1)%n];
    }
    for(auto &j:cmp)
    {
    	int n = sz(j);
    	for(int i=0;i<n;++i)
    		p[j[i]] = j[(i+1)%n];	
    }
    // make here
    cout << ans << "\n";
    for(int i=1;i<=n;++i)
    	cout << p[i] << " ";
    cout << "\n";
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