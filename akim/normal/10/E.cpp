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

ll a[maxn], b[maxn], c[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
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

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	reverse(&a[0], &a[n]);
	ll ans = mod * 1ll * mod;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			{
				ll tar = a[j] - 1;
				for(int k = n - 1; k >= i; k--) {
					b[k] = tar / a[k];
					tar %= a[k];
				}
			}
			for(int k = 0; k < i; k++) {
				b[k] = 0;
			}
			b[i]++;
			ll s = 0;
			for(int k = 0; k < n; k++) {
				s += b[k] * a[k];
			}
			if(s < ans) {
				ll tar = s,bc = 0, cc = 0;
				for(int k = n - 1; k >= 0; k--) {
					bc += b[k];
					cc += tar / a[k];
					tar %= a[k];
				}
				if(bc < cc) {
					ans = s;
				}
			}

		}
	}

	cout << (ans == mod * 1ll * mod ? -1 : ans);

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