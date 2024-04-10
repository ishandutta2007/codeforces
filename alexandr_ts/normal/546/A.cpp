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
    ll a, b, c;
    cin >> a >> b >> c;
    cout << max(0ll, (c * (c + 1) / 2 * a) - b);
}