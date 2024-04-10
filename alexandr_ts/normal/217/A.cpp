#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;

vector <int> g[N];
int x[N], y[N];
bool used[N];

void dfs(int v) {
    used[v] = true;
    fr(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

int main() {
    int n, v, u;
    cin >> n;
    fr(i, n) {
        cin >> x[i] >> y[i];
    }
    fr(i, n)
        fr(j, n)
            if (i != j)
                if (x[i] == x[j] || y[i] == y[j]) {
                    g[i].pb(j);
                    g[j].pb(i);
                }
    int ans = 0;
    fr(i, n)
        if (!used[i])
            dfs(i), ans++;
    cout << ans - 1;
}