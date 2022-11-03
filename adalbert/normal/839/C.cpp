#include <bits/stdc++.h>
#define int ll
#define fir first
#define sec second
#define pb push_back
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 100;
int answer;

double dp[MAX_N], deep[MAX_N];
vector<int> vec[MAX_N];


void solve(int u, int pr = -1) {
    double cnt = vec[u].size();
    if (pr != -1)
        cnt--;
    for (auto i:vec[u])
    if (i != pr) {
        deep[i] = deep[u] + 1;
        dp[i] = dp[u]  / cnt;
        solve(i, u);
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

    dp[1] = 1;
    solve(1);

    double ans = 0;

    for (int i = 2; i <= n; i++)
        if (vec[i].size() == 1)
        ans += dp[i] * deep[i];

    cout << fixed << setprecision(10) << ans;
}