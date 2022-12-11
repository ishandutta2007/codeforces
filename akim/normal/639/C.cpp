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

ll a[maxn], b[maxn];

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

	int n, k;
	scanf("%d%d", &n, &k);
	n++;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		a[i + 1] += a[i] / 2;
		a[i] %= 2;
		if(a[i] == -1) {
			a[i] = 1;
			a[i + 1] += -1;
		}
	}

	if(a[n - 1] < 0) {
		for(int i = 0; i < n; i++) {
			b[i] = -b[i];
			a[i] = b[i];
		}
		for(int i = 0; i < n - 1; i++) {
			a[i + 1] += a[i] / 2;
			a[i] %= 2;
			if(a[i] == -1) {
				a[i] = 1;
				a[i + 1] += -1;
			}
		}
	}

//	for(int i = 0; i <= n; i++) {
//		cout << a[i] << " ";
//	}cout << endl;

	int st = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] != 0) {
			st = i;
			break;
		}
	}

	ll cnt = 0, q = 1, qq = 0;
	for(int i = st; cnt <= 2 * k && i < n; i++, q *= 2, qq++) {
		if(qq > 33 && a[i] != 0) {
			cnt = mod * 1ll * mod;
			break;
		}
		cnt += q * a[i];
	}

	ll ans = 0;
	while(abs(cnt) <= 5ll * mod && st >= 0) {
		if(cnt == b[st] && st == n - 1) {} else
		ans += (abs(b[st] - cnt) <= k);
		cnt *= 2;
		st--;
	}

//	for(int i = 0; i < n; i++) {
//		b[i] = -b[i];
//		a[i] = b[i];
//	}
//	for(int i = 0; i < n - 1; i++) {
//		a[i + 1] += a[i] / 2;
//		a[i] %= 2;
//		if(a[i] == -1) {
//			a[i] = 1;
//			a[i + 1] += -1;
//		}
//	}
//
//	st = 0;
//	for(int i = 0; i < n; i++) {
//		if(a[i] != 0) {
//			st = i;
//			break;
//		}
//	}
//
//	cnt = 0, q = 1, qq = 0;
//	for(int i = st; cnt <= 2 * k && i < n; i++, q *= 2, qq++) {
//		if(qq > 33 && a[i] != 0) {
//			cnt = mod * 1ll * mod;
//			break;
//		}
//		cnt += q * a[i];
//	}
//	ll ans2 = ans; ans = 0;
//	while(abs(cnt) <= 5ll * mod && st >= 0) {
//		if(cnt == b[st] && st == n - 1) {} else
//		ans += (abs(b[st] - cnt) <= k);
//		cnt *= 2;
//		st--;
//	}

	printf("%lld", max(ans, ans));

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