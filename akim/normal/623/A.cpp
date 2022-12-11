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

vector<int> rb[maxn];
bool a[maxn], b[maxn], c[maxn];
int all, cnta = 0, cntb = 0, cntc = 0;

void dfsa(int u) {
	all--;
	a[u] = 1;
	cnta++;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(b[v]) continue;
		if(a[v]) continue;
		dfsa(v);
	}
}

void dfsc(int u) {
	all--;
	c[u] = 1;
	cntc++;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(b[v]) continue;
		if(c[v]) continue;
		dfsc(v);
	}
}

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

	int n, m;
	scanf("%d%d", &n, &m); all = n;
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	for(int i = 0; i < n; i++) {
		if((int)rb[i].size() == n - 1) {
			all--;
			b[i] = 1;
			cntb++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(!b[i]) {
			dfsa(i);
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(!b[i] && !a[i]) {
			dfsc(i);
			break;
		}
	}

	bool ok = 1;

	for(int i = 0; i < n; i++) {
		if(a[i]) {
			int reb = rb[i].size() - cntb;
			if(reb + 1 != cnta) {
				ok = 0;
			}
		}
		if(c[i]) {
			int reb = rb[i].size() - cntb;
			if(reb + 1 != cntc) {
				ok = 0;
			}
		}
	}

	if(all || !ok) {
		printf("No\n");
	} else {
		printf("Yes\n");
		for(int i = 0; i < n; i++) {
			if(a[i]) {
				printf("a");
			}
			if(b[i]) {
							printf("b");
						}
			if(c[i]) {
							printf("c");
						}
		}
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