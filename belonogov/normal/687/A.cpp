#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6;
const long long INF = 1e9 + 19;

vector < int > e[N];
int n, m;
int color[N];
bool fail;

void read() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		e[v].pb(u);
		e[u].pb(v);
	}
}


void dfs(int v, int c) {
	color[v] = c;
	for (auto u: e[v]) {
		if (color[u] == -1) {
			dfs(u, c ^ 1);
		}
		else {
			if (color[u] != (c ^ 1))
				fail = 1;
		}
	}
}

void solve() {
	memset(color, -1, sizeof(color));
	for (int i = 0; i < n; i++)
		if (color[i] == -1)
			dfs(i, 0);

	if (fail)
		cout << "-1" << endl;
	else {
		vector < int > r[2];
		for (int i = 0; i < n; i++)
			r[color[i]].pb(i);
		for (int tt = 0; tt < 2; tt++) {
			printf("%d\n", (int)r[tt].size());
			for (auto x: r[tt])
				printf("%d ", x + 1);
			puts("");
		}

	}

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}