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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n, q;
vector < int > e[N];
int sz[N];
int p[N];
int answer[N];
vector < int > who[N];
//int mxCh[N];

void read() {
	scanf("%d%d", &n, &q);
	p[0] = -1;
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		e[p[i]].pb(i);
	}
	for (int i = 0; i < q; i++) {
		int x;
		scanf("%d", &x); x--;
		who[x].pb(i);
	}
}

int dfs(int v) {
	sz[v] = 1;
	//mxCh[v] = 0;
	int root = v;
	for (auto u: e[v]) {
		int g = dfs(u);
		//mxCh[v] = max(mxCh[v], sz[u]);
		if (sz[u] > sz[v]) {
			root = g;
		}
		sz[v] += sz[u];
		for (; (sz[v] - sz[root]) * 2 > sz[v];)
			root = p[root];
	}
	//db2(v, root);
	for (auto u: who[v])
		answer[u] = root;

	return root;
}

void solve() {
	dfs(0);
	for (int i = 0; i < q; i++)
		printf("%d\n", answer[i] + 1);

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