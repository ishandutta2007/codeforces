#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e7 + 1;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, ct[N], p[N];
ll dp[N];

template <int N>
struct spf_sieve {
	std::vector<int> primes;
	std::array<int, N + 1> spf;
 
	spf_sieve() : spf() {
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
				primes.push_back(i);
			}
			for (int j = 0; j < (int) primes.size() && i * primes[j] <= N; j++) {
				spf[i * primes[j]] = primes[j];
				if (i % primes[j] == 0) {
					break;
				}
			}
		}
	}
 
	bool is_prime(int x) const {
		return spf[x] == x;
	}
 
	std::vector<std::pair<int, int>> prime_factors(int x) const {
		std::vector<std::pair<int, int>> factors;
		while (x != 1) {
			if (factors.empty() || factors.back().first != spf[x]) {
				factors.emplace_back(spf[x], 0);
			}
			factors.back().second++;
			x /= spf[x];
		}
		return factors;
	}
 
	std::vector<int> divisors(int x) const {
		std::vector<int> divisors = {1};
		while (x > 1) {
			int p = spf[x], c = 0;
			while (x % p == 0) {
				x /= p, c += 1;
			}
			int sz = (int) divisors.size();
			for (int i = 1, pw = p; i <= c; i++, pw *= p) {
				for (int j = 0; j < sz; j++) {
					divisors.push_back(divisors[j] * pw);
				}
			}
		}
		return divisors;
	}
 
	template <typename T, typename F>
	T compute_multiplicative_function(int x, F &&f) const {
		T result = T(1);
		while (x > 1) {
			int p = spf[x], c = 0;
			while (spf[x] == p) {
				x /= p, c += 1;
			}
			result *= f(p, c);
		}
		return result;
	}
};

spf_sieve<N> s;

ll mem(int x) {
	if (x == 1) return 0;
	if (dp[x] != -1) return dp[x];
	dp[x] = 0;
	for (auto it : s.divisors(x)) {
		dp[x] = max(dp[x], (ll) (ct[it] - ct[x]) * it + mem(it));
	}
	return dp[x];
}

void solve() {
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (auto it : s.divisors(a[i])) ct[it]++;
	}
	mset(dp, -1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, mem(a[i]) + (ll) ct[a[i]] * a[i]);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}