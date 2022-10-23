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
const int N=300005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i) {
        prime[i]=true;
        pf[i] = i;
    }
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

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n);
    const int N = 3e5;
    function<int(int)> reduce = [&](int x) {
    	int p = 1;
    	while(x > 1 && !prime[x]) {
    		int z = pf[x];
    		p *= z;
    		while(x % z == 0) {
    			x /= z;
    		}
    	}
    	if(x > 1) {
    		p *= x;
    	}
    	return p;
    };
    vector<int> cnt(N+1), f(N+1);
    for(int i=0;i<n;++i) {
    	cin >> a[i];
    	reduce(a[i]);
    	++cnt[a[i]];
    	++f[a[i]];
    }
    for(int i=1;i<=N;++i) {
    	for(int j=2*i;j<=N;j+=i) {
    		f[i] += f[j];
    	}
    }
    vector<int> dp(N+1,1e8);
    dp[1] = 0;
    int ans = 1e8;
    for(int i=1;i<=N;++i) {
    	vector<int> prs;
    	int cur = i;
    	while(cur > 1) {
    		if(pf[cur] == 0) {
    			debug(cur);
    		}
    		prs.push_back(pf[cur]);
    		cur /= pf[cur];
    	}
    	sort(all(prs));
    	prs.resize(unique(all(prs)) - prs.begin());
    	int n = sz(prs);
    	for(int mask=0;mask<(1 << n);++mask) {
    		int want = mask ^ ((1 << n) - 1);
    		int back = 1;
    		for(int j=0;j<n;++j) {
    			if((mask & (1 << j)) == 0) {
    				back *= prs[j];
    			}
    		}
    		int g = 0;
    		for(int j=mask;;j=(j-1)&mask) {
    			int x = 1;
    			for(int k=0;k<n;++k) {
    				if(j & (1 << k)) {
    					x *= prs[k];
    				}
    			}
    			g += popcount(j) & 1 ? -f[x]:f[x];
    			if(j == 0) {
    				break;
    			}
    		}
    		if(g > 0) {
				amin(dp[i], dp[back] + 1);
			}
    	}
    	if(cnt[i]) {
    		amin(ans, dp[i] + 1);
    	}
    }
    if(ans > 10) {
    	ans = -1;
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