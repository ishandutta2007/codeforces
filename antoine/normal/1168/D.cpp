#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 15e4 + 9;
int n, Q;
int parent[MxN + 9];
vector<int> adj[MxN + 9];
int height[MxN + 9];
char label[MxN + 9];
const string YES = "Shi";
const string NO = "Fou";
int parent2[MxN + 9];
vector<int> adj2[MxN + 9];
array<int, 26> label2[MxN + 9];
array<int, 26> dp[MxN + 9];
int dpSum[MxN + 9];
bool valid[MxN + 9];

void noAll() {
    for (int i = 0; i < Q; ++i)
        cout << NO << '\n';
    exit(0);
}

bool spe(const int u) {
    return u == 1 || 0 == (adj[u].size() & 1);
}

inline void update(const int u, const int j) {
    assert(0 <= j && j < 26);
    assert(spe(u));

    valid[u] = true;
    if (adj[u].empty())
        return;

    dpSum[u] -= dp[u][j];

    dp[u][j] = 0;
    for (const int v : adj2[u]) {
        valid[u] &= valid[v];
        dp[u][j] = max(dp[u][j], dp[v][j] + label2[v][j]);
    }

    dpSum[u] += dp[u][j];

    valid[u] &= dpSum[u] <= height[u];
}
/*

void checkInvariants() {
    for (int i = 1; i <= n; ++i) {
        assert(dpSum[i] == accumulate(dp[i].begin(), dp[i].end(), 0));
        if (valid[1] && spe(i)) {
            assert(dpSum[i] <= height[i]);
            assert(valid[i]);
        }
    }
}
*/

inline void chainUpdate(int u, const int j) {
    do {
        update(u, j);
        u = parent2[u];
    } while (u);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> Q;
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i] >> label[i];
        adj[parent[i]].push_back(i);
        assert(adj[parent[i]].size() <= 2);
    }

    for (int i = n; i >= 1; --i) {
        if (adj[i].empty())
            continue;
        const int u = adj[i][0];
        if (adj[i].size() == 2) {
            const int v = adj[i][1];
            if (height[u] != height[v])
                noAll();
        }
        height[i] = height[u] + 1;
    }

    for (int i = 2; i <= n; ++i) {
        if (spe(parent[i])) {
            parent2[i] = parent[i];
        } else {
            parent2[i] = parent2[parent[i]];
            label2[i] = label2[parent[i]];
        }
        if (label[i] != '?')
            label2[i][label[i] - 'a']++;
    }

    for (int i = n; i >= 1; --i) {
        for (int x : adj[i]) {
            const int y = spe(x) ? x : adj2[x][0];
            adj2[i].push_back(y);
        }
    }

    for (int i = n; i >= 1; --i)
        if (spe(i))
            for (int j = 0; j < 26; ++j)
                update(i, j);

    for (int rep = 0;; ++rep) {

        ostream &out = rep == 0 ? cerr : cout;
        if (!valid[1])
            out << NO << '\n';
        else {
            ll ans = 0;
            for (int j = 0; j < 26; ++j)
                ans += (j + 1LL) * (dp[1][j] + (height[1] - dpSum[1]));
            out << YES << ' ' << ans << '\n';
        }


        if (rep == Q)
            break;

        // =========

        int u;
        char ch;
        cin >> u >> ch;

        // label[u] -> ch

        const int v = spe(u) ? u : adj2[u][0];

        if (label[u] != '?') {
            const int j = label[u] - 'a';
            label2[v][j]--;
            chainUpdate(v, j);
        }
        if (ch != '?') {
            const int j = ch - 'a';
            label2[v][j]++;
            chainUpdate(v, j);
        }
        label[u] = ch;
    }
    return 0;
}