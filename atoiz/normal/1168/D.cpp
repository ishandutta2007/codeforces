/*input
5 5
1 ?
2 w
3 ?
3 w
4 q
4 ?
5 ?
3 v
5 g

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 150007, MAXC = 26;
int P[MAXN], h[MAXN];
vector<int> child[MAXN];
char C[MAXN];
int sim[MAXN];
int cnt[MAXC][MAXN], cont[MAXC][MAXN];
int nodeTotal[MAXN], invalid = 0;
int N, Q;

void maximize(int &a, int b) { if (a < b) a = b; }

signed main()
{
	scanf("%d %d", &N, &Q);
	for (int u = 2; u <= N; ++u) {
		scanf("%d %c", &P[u], &C[u]);
		child[P[u]].push_back(u);
		h[u] = h[P[u]] + 1;
	}

	int leafH = -1;
	for (int u = 2; u <= N; ++u) {
		if (child[u].empty()) {
			if (leafH < 0) leafH = h[u];
			if (h[u] != leafH) {
				for (int i = 0; i < Q; ++i) puts("Fou");
				return 0;
			}
		}
	}

	sim[1] = 1;
	for (int u = 2; u <= N; ++u) {
		sim[u] = (child[P[u]].size() <= 1 ? sim[P[u]] : u);
		if (C[u] != '?') ++ cont[(int) C[u] - 'a'][sim[u]];
	}

	for (int u = N; u >= 2; --u) if (u == sim[u]) {
		for (int c = 0; c < MAXC; ++c) maximize(cnt[c][sim[P[u]]], cnt[c][u] + cont[c][u]);
	}


	for (int u = 2; u <= N; ++u) if (u == sim[u] && child[P[u]][0] == u) {
		int p = sim[P[u]];
		for (int c = 0; c < MAXC; ++c) nodeTotal[p] += cnt[c][p];
		invalid += nodeTotal[p] > leafH - h[u] + 1;
	}

	for (int _ = 0; _ < Q; ++_) {
		int u;
		scanf("%d ", &u);
		char c = C[u]; 

		if (c != '?') {
			int i = c - 'a';
			--cont[i][sim[u]];
			for (int v = sim[u]; v != 1; v = sim[P[v]]) {
				int p = sim[P[v]];
				invalid -= (nodeTotal[p] > leafH - h[v] + 1);
				nodeTotal[p] -= cnt[i][p];
				cnt[i][p] = -1;

				for (int w : child[P[v]]) {
					maximize(cnt[i][p], cnt[i][w] + cont[i][w]);
				}

				nodeTotal[p] += cnt[i][p];
				invalid += (nodeTotal[p] > leafH - h[v] + 1);
			}
		}

		scanf("%c", &c);
		C[u] = c;

		// cout << c << endl;
		if (c != '?') {
			int i = c - 'a';			
			++cont[i][sim[u]];
			for (int v = sim[u]; v != 1; v = sim[P[v]]) {
				int p = sim[P[v]];
				invalid -= (nodeTotal[p] > leafH - h[v] + 1);
				nodeTotal[p] -= cnt[i][p];
				cnt[i][p] = -1;

				for (int w : child[P[v]]) {
					maximize(cnt[i][p], cnt[i][w] + cont[i][w]);
				}

				nodeTotal[p] += cnt[i][p];
				// cout << p << ":" << nodeTotal[p] << endl;
				invalid += (nodeTotal[p] > leafH - h[v] + 1);
			}
		}

		// cout << cnt['w' - 'a'][1] + cont['w' - 'a'][1] << ' ';
		if (invalid) puts("Fou");
		else {
			int ans = 0, total = 0;
			for (int i = 0; i < MAXC; ++i) total += cnt[i][1] + cont[i][1];
			for (int i = 0; i < MAXC; ++i) ans += (i + 1) * (cnt[i][1] + cont[i][1] + leafH - total);
			printf("Shi %d\n", ans);
		}
	}

	return 0;
}