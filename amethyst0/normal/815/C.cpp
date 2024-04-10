/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>

using namespace std;

const int maxn = (int)5010, inf = (int)1e9 + 10;

int dp[maxn][maxn];
int c[maxn], d[maxn];
vector <int> ed[maxn];
int sz[maxn];
vector <int> sumsz[maxn];
vector <vector <int> > dd[maxn];
multiset <int> s[maxn];
int posit = 0;

vector <int> ver;

int make(int v) {
	int it = posit++;
	s[it].insert(c[v]);
	sz[v] = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int nit = make(ed[v][i]);
		sz[v] += sz[ed[v][i]];
		sumsz[v].push_back(sz[v] - 1);

        if (s[it].size() < s[nit].size()) {
            swap(it, nit);
        }
        
        for (auto j = s[nit].begin(); j != s[nit].end(); j++) {
            s[it].insert(*j);
        }
        
        s[nit].clear();
	}
	
	dd[v].resize(sz[v]);

	ll sum = 0;

    auto itt = s[it].begin();

	for (int i = 0; i <= (int)s[it].size(); i++) {
		dp[v][i] = (int)min(sum, (ll)inf);

		if (i != (int)s[it].size()) {
			sum += (*itt);
			itt++;
		}
	}
	
	ver.push_back(v);

	return it;
}

inline int go(int v, int cnt);

inline int god(int v, int pos, int cnt) {
	if (dd[v][cnt].empty()) {
		dd[v][cnt].assign(ed[v].size() + 1, -1);
	}

	if (dd[v][cnt][pos] != -1) {
		return dd[v][cnt][pos];
	}

	if (pos == (int)ed[v].size()) {
		return dd[v][cnt][pos] = 0;
	}

	int last = sz[v] - 1 - sumsz[v][pos];

	int u = ed[v][pos];

	int ans = inf;

	for (int i = max(0, cnt - last); i <= min(cnt, sz[u]); i++) {
		ans = min(ans, go(u, i) + god(v, pos + 1, cnt - i));
	}

	return dd[v][cnt][pos] = ans;
}

inline int go(int v, int cnt) {
	if (cnt != 0) {
		dp[v][cnt] = min(dp[v][cnt], c[v] - d[v] + god(v, 0, cnt - 1));
	}

	return dp[v][cnt];
}

int main() {
	int n, b;

	cin >> n >> b;

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &c[i], &d[i]);

		if (i != 1) {
			int x;

			scanf("%d", &x);

			ed[x].push_back(i);
		}
	}

	memset(dp, -1, sizeof dp);

	make(1);

    //if (n == 5000 && c[1] == 2399867) {
        //return 0;
    //}

	int ans = 0;
	
	for (int i = 0; i < (int)ver.size(); i++) {
	    int v = ver[i];
	    for (int j = 0; j <= sz[v]; j++) {
	        go(v, j);
	    }
	}

	for (int i = 1; i <= n; i++) {
		if (dp[1][i] <= b) {
			ans = i;
		}
	}

	cout << ans << endl;

	return 0;
}