/*input
3 0


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
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>

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

const int MAXN = 100007;
int N, M;
int prv[MAXN], nxt[MAXN];
bool vis[MAXN];
vi G[MAXN];

void rem(int x)
{
	vis[x] = 1;
	nxt[prv[x]] = nxt[x];
	prv[nxt[x]] = prv[x];
}
queue<int> qu;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	FOR(i, 0, N) {
		prv[i + 1] = i;
		nxt[i] = i + 1;
	}

	FOR(ei, 0, M - 1) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int ans = -1;
	FOR(u, 1, N) if (!vis[u]) {
		++ans;

		while (!qu.empty()) qu.pop();
		rem(u);
		qu.push(u);

		while (!qu.empty()) {
			int v = qu.front();
			qu.pop();
			
			sort(ALL(G[v]));
			for (int i = nxt[0], id = 0; i <= N; i = nxt[i]) {
				for (; id < SZ(G[v]) && G[v][id] < i; ++id);
				if (id >= SZ(G[v]) || G[v][id] != i) {
					// cout << v << " -> " << i << endl;
					if (!vis[i]) {
						rem(i);
						qu.push(i);
					}
				}
			}
		}
	}


	cout << ans << endl;
	return 0;
}