#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second

const int MAXN = 3e5 + 7;
int N, M;
int D[MAXN], U[MAXN], V[MAXN];
int to[MAXN];
bool vis[MAXN];
vector<int> ids;
vector<int> G[MAXN];

int dfs(int u)
{
	vis[u] = 1;
	int use = (D[u] == 1);
	for (int id : G[u]) {
		int v = U[id] ^ V[id] ^ u;
		if (vis[v]) continue;
		to[v] = id;
        use ^= dfs(v);
	}
	if (use) ids.push_back(to[u]);
	return use;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
    FOR(i, 1, N) cin >> D[i];
    FOR(i, 1, M) {
    	cin >> U[i] >> V[i];
    	G[U[i]].push_back(i);
    	G[V[i]].push_back(i);
    }

    if (count(D + 1, D + 1 + N, -1) == 0 && count(D + 1, D + 1 + N, 1) % 2 == 1) {
		return cout << -1 << endl, 0;
    }

    if (count(D + 1, D + 1 + N, 1) % 2 == 1) {
        FOR(u, 1, N) {
        	if (D[u] == -1) {
				D[u] = 1;
				break;
        	}
        }
    }

    assert(!dfs(1));
	sort(ALL(ids));
	cout << SZ(ids) << '\n';
	FORA(i, ids) cout << i << ' '; cout << '\n';
}