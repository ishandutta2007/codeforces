#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 1e3 + 10;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e9 - 6;

int c[N];
vector <int> g[N];
int used[N];

void dfs(int v, int cnt) {
    used[v] = cnt;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i], cnt);
}

int num[N];

int main() {
    //freopen("a.in", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
        cin >> c[i];
        c[i]--;
	}
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    for (int i = 0; i < k; i++)
        dfs(c[i], i + 1);

    for (int i = 0; i < n; i++)
        num[used[i]]++;
    sort(num + 1, num + k + 1);
    int cnt0 = 0;
    fr(i, n)
        if (!used[i])
            cnt0++;
    num[k] += cnt0;
    ll ans = 0;
    frab(i, 1, k + 1)
        ans += (num[i] * (num[i] - 1)) / 2;
    cout << ans - m;
}