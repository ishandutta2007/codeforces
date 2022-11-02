#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;

int a[N];
vector <int> g[N];
bool used[N];

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        g[i].pb(i + a[i]);
    }
    dfs(0);
    if (used[k - 1])
        cout << "YES";
    else
        cout << "NO";
}