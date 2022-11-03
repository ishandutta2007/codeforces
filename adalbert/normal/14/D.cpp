#include <bits/stdc++.h>
#define int ll
#define fir first
#define sec second
#define pb push_back
using namespace std;

typedef long long ll;

const int MAX_N = 201;
int answer;

int dp[MAX_N], dpDown[MAX_N], deep[MAX_N], pred[MAX_N];
bool use[MAX_N];
vector<int> vec[MAX_N];

void dfs(int u, int pr) {
    for (auto i:vec[u])
    if (i != pr) {
        deep[i] = deep[u] + 1;
        pred[i] = u;
        dfs(i, u);
    }
}

void mark(int a, int b, int val) {
    while (a != b) {
        use[a] = val;
        use[b] = val;
        if (deep[a] > deep[b])
            a = pred[a]; else
            b = pred[b];
    }

    use[a] = val;
    use[b] = val;
}

void solve(int u, int pr) {
    for (auto i:vec[u])
        if (i != pr)
        solve(i, u);

    if (use[u])
        return;

    vector<int> sonsDown;
    for (auto i:vec[u])
        if (i != pr && !use[i]) {
            sonsDown.pb(dpDown[i]);
        }
    sort(sonsDown.begin(), sonsDown.end());
    reverse(sonsDown.begin(), sonsDown.end());

    if (sonsDown.empty()) {
        dpDown[u] = 0;
        dp[u] = 0;
    } else if (sonsDown.size() == 1) {
        dpDown[u] = 1 + sonsDown[0];
        dp[u] = 1 + sonsDown[0];
    } else {
        dpDown[u] = 1 + sonsDown[0];
        dp[u] = 2 + sonsDown[0] + sonsDown[1];
    }
}

main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
        mark(i, j, 1);
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if (use[i])
                len++;
            dp[i] = 0;
        }
        len--;

        solve(1, -1);

        for (int i = 1; i <= n; i++)
            answer = max(answer, dp[i] * len);
        mark(i, j, 0);
    }

    cout << answer;
}