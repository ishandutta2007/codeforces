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
vector<pair<int, int> > vc;
int snm[maxn];

int getroot(int u) {
	return(snm[u] == u ? u : snm[u] = getroot(snm[u]));
}

bool merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	if(u == v) return(0);
	snm[u] = v;
	return(1);
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

	for(int i = 0; i < maxn; i++) snm[i] = i;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		rb[u].pb(v);
		rb[v].pb(u);
		merge(u, v);
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(rb[i].size() != 2 && rb[j].size() != 2 && merge(i, j)) {
				rb[i].pb(j);
				rb[j].pb(i);
				vc.pb(mp(i, j));
			}
		}
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(rb[i].size() == 2) continue;
		for(int j = i + 1; j <= n; j++) {
			if(rb[j].size() == 2) continue;
			if(rb[i].size() + rb[j].size() <= 2) {
				rb[i].pb(j);
				rb[j].pb(i);
				vc.pb(mp(i, j));
				cnt++;
			}
		}
		if(rb[i].size() + rb[i].size() == 0) {
			rb[i].pb(i);
			rb[i].pb(i);
			vc.pb(mp(i, i));
			cnt++;
		}
	}

	bool ok = 1;
	for(int i = 1; i <= n; i++) {
		if(rb[i].size() != 2) {
//			cout << i << " " << rb[i].size() << endl;
			ok = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(merge(i, j)) ok = 0;
		}
	}
//	cout << ok << " " << cnt;
	if(!ok || cnt > 1) {
		cout << "NO";
		return(0);
	}
	sort(vc.begin(), vc.end());
	cout << "YES\n" << vc.size() << endl;
	for(int i = 0; i < vc.size(); i++) {
		cout << vc[i].fs << " " << vc[i].sc << endl;;
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