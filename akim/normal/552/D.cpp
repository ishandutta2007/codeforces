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

int x[maxn], y[maxn];
map<pair<pair<int, int>, pair<int, int> >, int> ma;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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
		scanf("%d%d", &x[i], &y[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int f = i + 1; f < n; f++) {
			int vx = x[i] - x[f], vy = y[i] - y[f], dx, dy;
			if(vx < 0) {vx = -vx, vy = -vy;} else
			if(vx == 0 && vy < 0) {vx = -vx, vy = -vy;}
			if(vx == 0) {
				vy = 1;
				dx = x[i], dy = 0;
			} else
			if(vy == 0) {
				vx = 1;
				dx = 0, dy = y[i];
			} else {
				int c = __gcd(abs(x[i] - x[f]), abs(y[i] - y[f]));
				vx /= c;
				vy /= c;
				int cnt = x[i] / vx;
				dx = x[i] - cnt * vx;
				dy = y[i] - cnt * vy;
				if(x[i] < 0 && dx < 0) {dx += vx; dy += vy;}
			}
			ma[mp(mp(vx, vy), mp(dx, dy))]++;
		}
	}
	map<pair<pair<int, int>, pair<int, int> >, int> :: iterator it;
	ll ans = 0;
	for(it = ma.begin(); it != ma.end(); it++) {
		int cnt = it -> sc;
		int c = ((1 + (int)sqrt(1 + 8 * cnt + eps)) >> 1);
		ans += cnt * 1ll * (n - c);
	}
	ans /= 3;
	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey