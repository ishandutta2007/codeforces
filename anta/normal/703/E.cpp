#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
	if((int)isprime.size() >= n + 1) return;
	isprime.assign(n + 1, true);
	isprime[0] = isprime[1] = false;
	int sqrtn = (int)(sqrt(n * 1.) + .5);
	for(int i = 2; i <= sqrtn; i ++) if(isprime[i]) {
		for(int j = i * i; j <= n; j += i)
			isprime[j] = false;
	}
	primes.clear();
	for(int i = 2; i <= n; i ++) if(isprime[i])
		primes.push_back(i);
}

typedef long long FactorsInt;
typedef vector<pair<FactorsInt, int> > Factors;
void primeFactors(FactorsInt x, Factors &out_v) {
	out_v.clear();
	int sqrtx = (int)(sqrt(x*1.) + 10.5);
	sieve(sqrtx);
	for(vector<int>::const_iterator p = primes.begin(); p != primes.end(); ++ p) {
		if(*p > sqrtx) break;
		if(x % *p == 0) {
			int t = 1;
			x /= *p;
			while(x % *p == 0) {
				t ++;
				x /= *p;
			}
			out_v.push_back(make_pair(*p, t));
		}
	}
	if(x != 1) out_v.push_back(make_pair(x, 1));
}
void getDivisors(FactorsInt x, vector<FactorsInt> &out_v) {
	Factors fs;
	primeFactors(x, fs);
	out_v.assign(1, 1);
	rep(i, fs.size()) {
		for(int j = (int)out_v.size() - 1; j >= 0; j --) {
			FactorsInt x = out_v[j];
			rep(k, fs[i].second) {
				x *= fs[i].first;
				out_v.push_back(x);
			}
		}
	}
	sort(out_v.begin(), out_v.end());
}

template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }

inline long long mulmodll(long long a, long long b, long long m, long double invm) {
	long long quot = (long long)((long double)a * b * invm + 0.5);
	long long res = a * b - m * quot;
	res = a * b - m * quot;
	if(res < 0) res += m;
	return res;
}

int main() {
	int n; long long k;
	while(~scanf("%d%lld", &n, &k)) {
		vector<ll> as(n);
		vector<long long> divs;
		getDivisors(k, divs);
		for(int i = 0; i < n; ++ i)
			scanf("%lld", &as[i]);
		if(k == 1) {
			int i = (int)(min_element(as.begin(), as.end()) - as.begin());
			printf("1\n%d\n", i + 1);
			continue;
		}
		int SqrtK = (int)sqrt(k * 1.0) + 10;
		vector<int> index(SqrtK * 2, -1);
		rep(i, divs.size()) {
			ll d = divs[i];
			if(d < SqrtK)
				index[(int)d] = i;
			else
				index[SqrtK + (int)(k / d)] = i;
		}
		auto getindex = [&](ll d) {
			if(d < SqrtK)
				return index[(int)d];
			else
				return index[SqrtK + (int)(k / d)];
		};
		long double invk = 1.L / k;
		typedef tuple<int, ll, int> T;
		vector<vector<T>> dp(n + 1, vector<T>(divs.size(), make_tuple(INF, INFL, -1)));
		dp[0][0] = make_tuple(0, 0LL, -1);
		rep(i, n) {
			ll a = as[i];
			ll g = gcd(a, k);
			rep(j, divs.size()) {
				int x = get<0>(dp[i][j]);
				if(x == INF) continue;
				ll y = get<1>(dp[i][j]);
				dp[i + 1][j] = make_tuple(x, y, j);
			}
			if(g == 1) continue;
			for(int j = (int)divs.size() - 1; j >= 0; -- j) {
				int x = get<0>(dp[i][j]);
				if(x == INF) continue;
				ll y = get<1>(dp[i][j]);
				ll nd = gcd(mulmodll(divs[j], g, k, invk), k);
				int nj = getindex(nd);
				if(j < nj)
					amin(dp[i + 1][nj], make_tuple(x + 1, y + a, j));
			}
		}
		if(get<0>(dp[n].back()) == INF) {
			puts("-1");
		} else {
			vi ans;
			int i = n, j = (int)divs.size() - 1;
			while(j != 0) {
				if(get<2>(dp[i][j]) < j)
					ans.push_back(i - 1);
				j = get<2>(dp[i][j]);
				-- i;
			}
			reverse(ans.begin(), ans.end());
			assert(unique(ans.begin(), ans.end()) == ans.end());
			printf("%d\n", (int)ans.size());
			for(int i = 0; i < (int)ans.size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", ans[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}