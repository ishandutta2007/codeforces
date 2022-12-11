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

int rb[330][330];

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
		for(int f = 0; f < n; f++) {
			scanf("%d", &rb[i][f]);
		}
	}

	int m;
	scanf("%d", &m);
	for(; m > 0; m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		ll ans = 0;
		rb[a][b] = min(rb[a][b], c);
		rb[b][a] = min(rb[b][a], c);
		for(int i = 0; i < n; i++) {
			for(int f = 0; f < n; f++) {
				rb[i][f] = min(rb[i][f], min(rb[i][a] + rb[a][b] + rb[b][f], rb[i][b] + rb[b][a] + rb[a][f]));
			}
		}
		for(int i = 0; i < n; i++) {
			for(int f = 0; f < n; f++) {
				ans += (ll)rb[i][f];
			}
		}
		ans >>= 1ll;
		printf("%I64d ", ans);
	}

	return(0);
}

// by Kim Andrey