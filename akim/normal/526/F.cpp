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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 3 * 100100;

int n, a[maxn], lmin[maxn], rmin[maxn], lmax[maxn], rmax[maxn], cnt[2 * maxn];
ll ans;

void solve(int l, int r) {
	if(l == r) {
		ans++;
		return;
	}

	int m = (l + r) >> 1;

	lmin[m] = lmax[m] = a[m];
	for(int i = m - 1; i >= l; i--) {
		lmin[i] = min(lmin[i + 1], a[i]);
		lmax[i] = max(lmax[i + 1], a[i]);
	}

	rmin[m + 1] = rmax[m + 1] = a[m + 1];
	for(int i = m + 2; i <= r; i++) {
		rmin[i] = min(rmin[i - 1], a[i]);
		rmax[i] = max(rmax[i - 1], a[i]);
	}

	for (int i = l; i <= m; i++) {
			int t = lmax[i] - lmin[i] - m + i;

			if (t <= r-m && t > 0 && lmin[i] < rmin[t+m] && rmax[t+m] < lmax[i])
				ans++;
		}

		for (int i = m+1; i <= r; i++) {
			int t = rmax[i] - rmin[i] + 1 - i + m;

			if (t <= m - l + 1 && t > 0 && rmin[i] < lmin[m-t+1] && lmax[m-t+1] < rmax[i])
				ans++;
		}

	{
		int f = r, g = r;

		for(int i = l; i <= m; i++) {
			for(; f > m && rmax[f] > lmax[i]; f--) {
				cnt[f - rmax[f] + maxn]++;
			}
			for(; g > f && rmin[g] < lmin[i]; g--) {
				cnt[g - rmax[g] + maxn]--;
			}
			ans += cnt[i - lmin[i] + maxn];
		}

		for(; g > f; g--) {
			cnt[g - rmax[g] + maxn]--;
		}
	}

	{
		int f = r, g = r;

		for(int i = l; i <= m; i++) {
			for(; f > m && rmin[f] < lmin[i]; f--) {
				cnt[f + rmin[f]]++;
			}
			for(; g > f && rmax[g] > lmax[i]; g--) {
				cnt[g + rmin[g]]--;
			}
			ans += cnt[i + lmax[i]];
		}

		for(; g > f; g--) {
			cnt[g + rmin[g]]--;
		}
	}

	solve(l, m);
	solve(m + 1, r);

}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		a[x] = y;
	}

	solve(0, n - 1);

	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey