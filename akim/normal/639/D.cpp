#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

pair<ll, ll> a[maxn];
ll b, c, ost;

struct cmp {
	bool operator()(const pair<ll, ll> &x, const pair<ll, ll> &y) {
		ll tar = 3ll * mod;
		tar += (ost + 10 - (tar % 5)) % 5;
		return((tar - (x.fs + x.sc)) / 5 * b + x.sc * c > (tar - (y.fs + y.sc)) / 5 * b + y.sc * c);
	}
};

multiset<pair<ll, ll>, cmp> st;

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll n, k, mn = 0;
	scanf("%lld%lld%lld%lld", &n, &k, &b, &c);

	b = min(c * 5, b);

	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i].fs);
		mn = min(mn, a[i].fs);
	}
	for(int i = 0; i < n; i++) {
		a[i].fs -= mn;
	}
	sort(&a[0], &a[n]);

	ll ans = mod * 1ll * mod;
	for(ost = 0; ost < 5; ost++) {
		for(int i = 0; i < n; i++) {
			a[i].sc = (ost + 10 - (a[i].fs % 5)) % 5;
		}

		st.clear();
		ll t = 0, prev = ost;
		for(int i = 0; i < n; i++) {
			ll to = a[i].fs + a[i].sc;
			t += (to - prev) / 5 * st.size() * b;
			t += a[i].sc * c;
			st.insert(a[i]);
			if((int)st.size() > k) {
				pair<ll, ll> p = *st.begin();
				st.erase(st.begin());
				t -= (to - (p.fs + p.sc)) / 5 * b + p.sc * c;
			}
			if((int)st.size() == k) {
				ans = min(ans, t);
			}
			prev = to;
		}

	}

	printf("%lld", ans);

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim