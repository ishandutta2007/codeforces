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
const int maxn = 1000100;

vector<int> a[maxn];
vector<int> b[maxn];

map<int, pair<int, int> > resx, resy;
vector<pair<int, pair<int, int> > > vc;
map<int, int> fillx, filly;
int snm[maxn], answ[maxn];

int getroot(int u) {
	return(snm[u] == u ? u : snm[u] = getroot(snm[u]));
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

	for(int i = 0; i < maxn; i++) {
		snm[i] = i;
	}

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		a[i].resize(m);
		b[i].resize(m);
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			vc.pb(mp(a[i][j], mp(i, j)));
		}
	}

	sort(vc.begin(), vc.end());
	int j = 0;
	for(int i = 0; i < (int) vc.size();) {
		while(j < (int)vc.size() && vc[j].fs == vc[i].fs) {
			j++;
		}
		fillx.clear(), filly.clear();
		int k = i;
		while(k < j) {
			int ans = 1, val = vc[k].fs, x = vc[k].sc.fs, y = vc[k].sc.sc;

			if(resx.count(x)) {
				if(resx[x].sc == val) {
					ans = max(ans, resx[x].fs);
				} else {
					ans = max(ans, resx[x].fs + 1);
				}
			}
			if(resy.count(y)) {
				if(resy[y].sc == val) {
					ans = max(ans, resy[y].fs);
				} else {
					ans = max(ans, resy[y].fs + 1);
				}
			}
			int u = k;
			answ[u] = ans;
			if(fillx.count(x)) {
				snm[u] = getroot(fillx[x]);
				answ[snm[u]] = max(answ[snm[u]], answ[u]);
			}
			u = snm[u];
			if(filly.count(y)) {
				snm[u] = getroot(filly[y]);
				answ[snm[u]] = max(answ[snm[u]], answ[u]);
			}
			fillx[x] = u;
			filly[y] = u;
			k++;
		}
		while(i < j) {
			int val = vc[i].fs, x = vc[i].sc.fs, y = vc[i].sc.sc;
			k = getroot(i);
			b[x][y] = answ[k];
			resx[x] = mp(answ[k], val);
			resy[y] = mp(answ[k], val);
			i++;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
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