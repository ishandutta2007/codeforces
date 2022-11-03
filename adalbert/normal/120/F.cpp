#include <bits/stdc++.h>
#define int ll
#define fir first
#define sec second
#define pb push_back
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 100;
int answer;

int deep[MAX_N];
vector<int> vec[MAX_N];

void dfs(int u, int pred = -1) {
    if (pred == -1)
        deep[u] = 0;
    for (auto i:vec[u])
        if (i != pred) {
            deep[i] = deep[u] + 1;
            dfs(i, u);
        }
}

int solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    dfs(1);

    int imx = 1;
    for (int i = 1; i <= n; i++)
        if (deep[i] > deep[imx])
        imx = i;

    dfs(imx);

    for (int i = 1; i <= n; i++)
        if (deep[i] > deep[imx])
        imx = i;
    for (int i = 1; i <= n; i++)
        vec[i].clear();
    return deep[imx];
}

main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += solve();
    }

    cout << ans;
}