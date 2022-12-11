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

int a[maxn];
vector<int> vc;

map<int, int> ma;

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

	{
		int x = 1, y = 0;
		while(x < 16 * maxn) {
			ma[x] = y++;
			x <<= 1;
		}
	}

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int c = a[0];
	for(int i = 1; i < n; i++) {
		int xx = a[i];
		while(xx != c) {
			if(c > xx) {
				c >>= 1;
			} else {
				xx >>= 1;
			}
		}
	}
	{
		while(c < 4 * maxn) {
			c <<= 1;
		}
		while(c) {
			vc.pb(c);
			c >>= 1;
		}
	}
	int ans = mod;
	for(int i = 0; i < (int)vc.size(); i++) {
		int cnt = 0;
		for(int f = 0; f < n; f++) {
			int xx = a[f];
			while((vc[i] < a[f]) || ((vc[i] % a[f]) != 0) || (ma.count(vc[i] / a[f]) == 0)) {
				a[f] >>= 1;
				cnt++;
			}
			cnt += ma[vc[i] / a[f]];
			a[f] = xx;
		}
		ans = min(ans, cnt);
	}
	printf("%d", ans);

	return(0);
}