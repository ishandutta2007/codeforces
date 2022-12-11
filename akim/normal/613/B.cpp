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
const int maxn = 100100;

pair<ll, ll> b[maxn];
ll suf[maxn], mas[maxn];

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

	ll n, a, cf, cm, m;
	scanf("%lld%lld%lld%lld%lld", &n, &a, &cf, &cm, &m);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &b[i].fs);
		mas[i] = b[i].fs;
		b[i].sc = i;
	}
	sort(&b[0], &b[n], greater<pair<ll, ll> >());

	for(int i = n - 1; i >= 0; i--) {
		suf[i] = (i + 1 < n ? suf[i + 1] : 0) + b[i].fs;
	}

	ll lostn = 0;
	ll ans = 0, ansid = 0;
	for(int i = 0; i <= n && lostn <= m; lostn += a - b[i++].fs) {
		{
			ll mm = m - lostn;
			ll l = i - 1, r = n - 1;
			while(l + 1 < r) {
				ll mid = (l + r) >> 1;
				if(((n - mid) * b[mid].fs) - suf[mid] > mm) {
					l = mid;
				} else {
					r = mid;
				}
			}
			ll level = min(b[r].fs + (mm - (((n - r) * b[r].fs) - suf[r])) / (n - r), a);
			if(i == n) level = a;
//			ans = max(ans, level * cm + i * cf);
			if(ans < level * cm + i * cf) {
				ans = level * cm + i * cf;
				ansid = i;
			}
		}
	}

	printf("%lld\n", ans);

	lostn = 0;
	for(int i = 0; i < ansid; lostn += a - b[i++].fs);
	{
		ll mm = m - lostn;
		ll l = ansid -1, r = n - 1;
		while(l + 1 < r) {
			ll mid = (l + r) >> 1;
			if(((n - mid) * b[mid].fs) - suf[mid] > mm) {
				l = mid;
			} else {
				r = mid;
			}
		}
		l = r;
		ll level = min(b[r].fs + (mm - (((n - r) * b[r].fs) - suf[r])) / (n - r), a);
		if(ansid == n) level = a;
		for(int i = 0; i < ansid; i++) {
			mas[b[i].sc] = a;
		}
		for(int i = r; i < n; i++) {
			mas[b[i].sc] = level;
		}
	}

	for(int i = 0; i < n; i++) {
		printf("%lld ", mas[i]);
	}

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