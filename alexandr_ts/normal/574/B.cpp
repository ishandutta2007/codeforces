#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

bool used[N];
unordered_set <int> g[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].insert(u);
        g[u].insert(v);
    }
    int ans = INF;
    fr(i, n)
        for (auto it = g[i].begin(); it != g[i].end(); it++)
            for (auto it2 = it; it2 != g[i].end(); it2++)
                if (g[*it].count(*it2))
                    ans = min(ans, (int)g[i].size() + (int)g[*it].size() + (int)g[*it2].size() - 6);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}