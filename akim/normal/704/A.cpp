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
const int maxn = 300100;

int pos = 0;
vector<int> vc[maxn];
bool deleted[maxn];

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

	int n, q;
	scanf("%d%d", &n, &q);
	int ans = 0, lfg = 0;
	for(int i = 0; i < q; i++) {
		int tp, c;
		scanf("%d%d", &tp, &c);
		if(tp == 1) {
			vc[c].pb(pos);
			pos++;
			ans++;
		}
		if(tp == 2) {
			while(!vc[c].empty()) {
				if(!deleted[vc[c].back()]) {
					ans--;
					deleted[vc[c].back()] = 1;
				}
				vc[c].ppb();
			}
		}
		if(tp == 3) {
			while(lfg < c) {
				if(!deleted[lfg]) {
					ans--;
					deleted[lfg] = 1;
				}
				lfg++;
			}
		}
		printf("%d\n", ans);
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