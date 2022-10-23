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
#define debug(...) 2401
#endif

#define runSieve
const int N = 2e7 + 5;
bool prime[N];
int pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

int f[N];
ll dp[N];

void dfs(vector<vector<int>> &g, int i, int el) {
	if(i == g.size()) {
		++f[el];
		return ;
	}
	for(auto &j:g[i]) {
		dfs(g, i + 1, el * j);
	}
}

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=0;i<n;++i) {
    	int x;
    	cin >> x;
    	vector<vector<int>> prs;
    	while(x > 1 and !prime[x]) {
    		int z = pf[x];
    		vector<int> t;
    		t.push_back(1);
    		int u = z;
    		while(x % z == 0) {
    			t.push_back(u);
    			x /= z;
    			u *= z;
    		}
    		prs.push_back(t);
    	}
    	if(x > 1) {
    		prs.push_back({1, x});
    	}
    	// debug(prs);
    	dfs(prs, 0, 1);
    }
    n = N - 5;
    // for(int i=1;i<=n;++i) {
    // 	int cnt = 0;
    // 	for(int j=i;j<=n;j+=i) {
    // 		cnt += f[j];
    // 	}
    // 	f[i] = cnt;
    // }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
    	amax(dp[i], f[i] * 1ll * i);
    	int cur = i;
    	while(cur != 1 and !prime[cur]) {
    		int z = pf[cur];
    		int u = i / z;
    		amax(dp[i], dp[u] + f[i] * 1ll * (i - u));
    		while(cur % z == 0) {
    			cur /= z;
    		}
    	}
    	if(cur != 1) {
    		amax(dp[i], dp[i/cur] + f[i] * 1ll * (i - i/cur));
    	}
    	amax(ans, dp[i]);
    }
    cout << ans << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}