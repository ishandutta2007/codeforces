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

vector<pair<int, string> > vc[maxn];

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
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		string name;
		char c = getchar();
		while(c != ' ') {
			name.pb(c);
			c = getchar();
		}
		int id, b;
		scanf("%d%d", &id, &b);
		vc[id].pb(mp(b, name));
	}
	for(int i = 1; i <= m; i++) {
		sort(vc[i].begin(), vc[i].end());
		int sz = (int)vc[i].size();
		bool bad = 0;
		if(sz > 2 && vc[i][sz - 2].fs == vc[i][sz - 3].fs) {
			bad = 1;
		}
		if(bad) {
			printf("?\n");
		} else {
			printf("%s %s\n", vc[i][sz - 1].sc.c_str(), vc[i][sz - 2].sc.c_str());
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