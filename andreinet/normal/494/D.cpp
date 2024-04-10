#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Mod = 1e9 + 7;

vector<pair<int, int>> G[Nmax];
int SumDown[Nmax], SumDownS[Nmax], SumUp[Nmax], SumUpS[Nmax], Total[Nmax];
int Subtree[Nmax], H[Nmax];
int Father[17][Nmax], Lvl[Nmax];
int firstE[Nmax], lastE[Nmax];
int N, E;

void dfs1(const int node, const int father) {
    firstE[node] = ++E;
    Subtree[node] = 1;
    for (auto& p: G[node]) {
        if (p.first == father) continue;
        Father[0][p.first] = node;
        Lvl[p.first] = Lvl[node] + 1;
        H[p.first] = (H[node] + p.second) % Mod;
        dfs1(p.first, node);
        int x = Subtree[p.first];
        Subtree[node] += x;
        SumDown[node] = (SumDown[node] + SumDown[p.first] + 1LL * p.second * x % Mod) % Mod;
        SumDownS[node] = (SumDownS[node] + SumDownS[p.first] + 1LL * p.second * p.second % Mod * x % Mod + 2LL * p.second * SumDown[p.first] % Mod) % Mod;
    }
    lastE[node] = ++E;
}

void dfs2(const int node, const int father, const int lastCost) {
    if (father != 0) {
        int x = Subtree[node];
        int sumf = (SumDown[father] + SumUp[father]) % Mod;
        sumf = (sumf + Mod - (SumDown[node] + 1LL * lastCost * x) % Mod) % Mod;
        int sumfs = (SumDownS[father] + SumUpS[father]) % Mod;
        sumfs = (sumfs + Mod - (SumDownS[node] + 1LL * lastCost * lastCost % Mod * x % Mod + 2LL * lastCost * SumDown[node] % Mod) % Mod) % Mod;
        SumUp[node] = (sumf + 1LL * lastCost * (N - x)) % Mod;
        SumUpS[node] = (sumfs + 1LL * lastCost * lastCost % Mod * (N - x) % Mod + 2LL * lastCost * sumf % Mod) % Mod;
    }
    for (auto& p: G[node])
        if (p.first != father)
            dfs2(p.first, node, p.second);
}

void buildAscensors() {
    for (int k = 1; k < 17; ++k)
        for (int i = 1; i <= N; ++i)
            Father[k][i] = Father[k - 1][Father[k - 1][i]];
}

inline bool isAscensor(int node, int asc) {
    return firstE[asc] <= firstE[node] &&lastE[node] <= lastE[asc];
}

int lca(int x, int y) {
    if (isAscensor(x, y)) return y;
    if (isAscensor(y, x)) return x;
    for (int k = 16; k >= 0; --k)
        if (!isAscensor(y, Father[k][x]))
            x = Father[k][x];
    return Father[0][x];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i < N; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        c %= Mod;
        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }

    dfs1(1, 0);
    Father[0][1] = 1;
    dfs2(1, 0, 0);
    buildAscensors();

    for (int i = 1; i <= N; ++i)
        Total[i] = (SumDownS[i] + SumUpS[i]) % Mod;

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;

        int ans = 0;
        if (!isAscensor(x, y)) {
            ans = (Mod - Total[x]) % Mod;
            int l = lca(x, y);
            int dist = ((H[x] - H[l] + Mod) % Mod + (H[y] - H[l] + Mod) % Mod) % Mod;
            int add = (SumDownS[y] + 1LL * dist * dist % Mod * Subtree[y] % Mod + 2LL * dist * SumDown[y] % Mod) % Mod;
            ans = (ans + add) % Mod;
            ans = (ans + add) % Mod;
        } else {
            ans = Total[x];
            int dist = (H[x] - H[y]) % Mod;
            int add = (SumUpS[y] + 1LL * dist * dist % Mod * (N - Subtree[y]) % Mod + 2LL * dist * SumUp[y] % Mod) % Mod;
            add = (Mod - add) % Mod;
            ans = (ans + add) % Mod;
            ans = (ans + add) % Mod;
        }
        cout << ans << '\n';
    }
}