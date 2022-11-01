#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 1e3 + 5;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;

int c[N];
vector <int> g[N];
bool used[N];
int cnt[N];

bool check2(int v) {
    used[v] = true;
    bool ok = true;
    fr(i, g[v].size()) {
        if (!used[g[v][i]])
            if (c[v] != c[g[v][i]]) {
                ok = false;
                return false;
            }
        if (c[v] == c[g[v][i]] && !used[g[v][i]])
            ok &= check2(g[v][i]);
    }
    return ok;
}

bool check(int v,int n) {
    fill(used, used + n, false);
    used[v] = true;
    fr(i, g[v].size())
        if (!check2(g[v][i]))
            return false;
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    fr(i, n)
        cin >> c[i];

    fr(i, n)
        fr(j, g[i].size())
            if (c[i] != c[g[i][j]]) {
                bool ok = check(i, n);
                if (ok) {
                    cout << "YES" << endl;
                    cout << i + 1;
                    return 0;
                }
                ok = check(g[i][j], n);
                if (ok) {
                    cout << "YES" << endl;
                    cout << g[i][j] + 1;
                    return 0;
                }
                cout << "NO";
                return 0;
            }
    cout << "YES" << endl << 1;
}