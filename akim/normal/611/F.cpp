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

vector<pair<int, int> > vc;

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

	int n, w, h;
	scanf("%d%d%d\n", &n, &w, &h);
	string s;
	s.reserve(n);
	for(int i = 0; i < n; i++) {
		s.pb(getchar());
	}
	int toL = 0, toR = 0, toU = 0, toD = 0, x = 0, y = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'R') {
			x++;
		}
		if(s[i] == 'L') {
			x--;
		}
		if(s[i] == 'U') {
			y++;
		}
		if(s[i] == 'D') {
			y--;
		}
		if(x > toR) {
			toR = x;
			h--;
			ans += w * 1ll * (i + 1);
			ans %= mod;
		}
		if(x < toL) {
			toL = x;
			h--;
			ans += w * 1ll * (i + 1);
			ans %= mod;
		}
		if(y > toU) {
			toU = y;
			w--;
			ans += h * 1ll * (i + 1);
			ans %= mod;
		}
		if(y < toD) {
			toD = y;
			w--;
			ans += h * 1ll * (i + 1);
			ans %= mod;
		}
		if(w == 0 || h == 0) break;
	}

	if(x == 0 && y == 0) {
		cout << "-1";
		return(0);
	}

	for(int i = 0; i < n; i++) {
		if(s[i] == 'R') {
			x++;
		}
		if(s[i] == 'L') {
			x--;
		}
		if(s[i] == 'U') {
			y++;
		}
		if(s[i] == 'D') {
			y--;
		}
		if(x > toR) {
			toR = x;
			vc.pb(mp(1, i + 1));
		}
		if(x < toL) {
			toL = x;
			vc.pb(mp(1, i + 1));
		}
		if(y > toU) {
			toU = y;
			vc.pb(mp(2, i + 1));
		}
		if(y < toD) {
			toD = y;
			vc.pb(mp(2, i + 1));
		}
		if(w == 0 || h == 0) break;
	}

	int i = 0, clc = 1;
	while(w != 0 && h != 0) {
		if(vc[i].fs == 1) {
			ans += w * 1ll * (vc[i].sc + clc * 1ll * n % mod);
			ans %= mod;
			h--;
		} else {
			ans += h * 1ll * (vc[i].sc + clc * 1ll * n % mod);
			ans %= mod;
			w--;
		}

		i++, clc += i == vc.size(), i = i == vc.size() ? 0 : i;
	}

	cout << ans;

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