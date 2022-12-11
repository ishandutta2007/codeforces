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
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

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

int rw[maxn];
bool used[maxn];
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


	for(int i = 2; i < maxn; i++) {
		if(!rw[i]) {
			for(int j = i + i; j < maxn; j += i) {
				rw[j] = 1;
			}
		}
	}

	int n;
	scanf("%d", &n);
	for(int i = n; i >= 2; i--) {
		if(rw[i]) continue;
		if(i * 2 > n) {
			continue;
		}
		int cnt = 1;
		for(int j = i + i; j <= n; j += i) {
			if(used[j]) continue;
			cnt++;
		}

		if(cnt & 1) {
			used[i] = 1;
			int cur = i;
			for(int j = i + i + i; j <= n; j += i) {
				if(used[j]) continue;
				used[j] = 1;
				if(cur == -1) {
					cur = j;
				} else {
					vc.pb(mp(j, cur));
					cur = -1;
				}
			}
		} else {
			used[i] = 1;
			int cur = i;
			for(int j = i + i; j <= n; j += i) {
				if(used[j]) continue;
				used[j] = 1;
				if(cur == -1) {
					cur = j;
				} else {
					vc.pb(mp(j, cur));
					cur = -1;
				}
			}
		}
	}

	printf("%d\n", (int)vc.size());
	for(int i = 0; i < (int)vc.size(); i++) {
		printf("%d %d\n", vc[i].fs, vc[i].sc);
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