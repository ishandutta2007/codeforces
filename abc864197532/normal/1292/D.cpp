#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 5001, logN = 17;

map <vector <int>, int> node;
vector <vector <int>> vec;
int P = 0;
vector <int> lp, id;

int dis(int u, int v) {
    return accumulate(all(vec[u]), 0) - accumulate(all(vec[v]), 0);
}

int get(vector <int> &a) {
    if (node.count(a)) return node[a];
    vec.pb(a);
    return node[a] = vec.size() - 1;
}

int lca (int u, int v) {
    vector <int> now(P, 0);
    for (int i = P - 1; ~i; --i) {
        if (vec[u][i] != vec[v][i]) {
            now[i] = min(vec[u][i], vec[v][i]);
            break;
        }
        now[i] = vec[u][i];
    }
    return get(now);
}

vector <pii> adj[N * 2];
lli depth[N * 2], sz[N * 2], sz2[N * 2];
lli ans;

void dfs1(int v, int pa, int w) {
    for (pii A : adj[v]) if (A.X != pa) {
        dfs1(A.X, v, A.Y);
        sz[v] += sz[A.X];
    }
}

int dfs2(int v, int pa) {
    for (pii A : adj[v]) if (A.X != pa && sz[A.X] > sz[0] / 2) {
        return dfs2(A.X, v);
    }
    return v;
}

void dfs3(int v, int pa, int w) {
    depth[v] = ~pa ? depth[pa] + w : 0;
    ans += depth[v] * sz2[v];
    for (pii A : adj[v]) if (A.X != pa) {
        dfs3(A.X, v, A.Y);
    }
}

void build() {
    lp.assign(N, 0);
    id.assign(N, 0);
    lp[1] = 1;
    for (int i = 2; i < N; ++i) if (!lp[i]) {
        for (int j = i; j < N; j += i) if (!lp[j]) {
            lp[j] = i;
        }
        id[i] = P++;
    }
    vector <int> now(P, 0);
    vector <int> cur;
    for (int i = 1; i < N; ++i) {
        int tmp = i;
        while (tmp > 1) {
            now[id[lp[tmp]]]++;
            tmp /= lp[tmp];
        }
        cur.pb(get(now));
    }
    for (int i = 0; i + 2 < N; ++i) {
        cur.pb(lca(i, i + 1));
    }
    sort(all(cur));
    cur.resize(unique(all(cur)) - cur.begin());
    sort(all(cur), [&](int u, int v) {
        for (int i = P - 1; ~i; --i) {
            if (vec[u][i] != vec[v][i]) return vec[u][i] < vec[v][i];
        }
    });
    for (int i = 1; i < cur.size(); ++i) {
        int u = cur[i], v = lca(cur[i - 1], cur[i]), w = dis(u, v);
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int n;
    cin >> n;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp, tmp = max(tmp - 1, 0);
        sz[tmp]++;
        sz2[tmp]++;
    }
    dfs1(0, -1, 0);
    int c = dfs2(0, -1);
    dfs3(c, -1, 0);
    cout << ans << endl;
}