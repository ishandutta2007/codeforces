#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> a;
vector <int> kol;
vector <bool> used;
vector <int> cha;
vector <int> res;
int n1, n3;

bool dfs(int v) {
    cha[kol[v]]++;
    used[v] = true;
    for (int i : a[v]) {
        if (!used[i]) {
            kol[i] = (kol[v]^1);
            if (!dfs(i)) return false;
        }
        else if (kol[i] == kol[v]) return false;
    }
    return true;
}

void paint(int v) {
    used[v] = true;
    for (int i : a[v]) {
        if (!used[i]) {
            if (res[v] == 2) {
                if (n1 > 0) {
                    --n1;
                    res[i] = 1;
                }
                else {
                    --n3;
                    res[i] = 3;
                }
            }
            else {
                res[i] = 2;
            }
            paint(i);
        }
    }
}

signed main() {
    int n, m, n2;
    cin >> n >> m >> n1 >> n2 >> n3;
    a.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    used.resize(n);
    kol.resize(n);
    vector <vector <int>> ans;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            kol[i] = 0;
            cha = {0, 0};
            if (!dfs(i)) {
                cout << "NO";
                return 0;
            }
            ans.push_back(cha);
        }
    }
    vector <vector <bool>> dp(n, vector <bool> (n + 1));
    dp[0][ans[0][0]] = true;
    dp[0][ans[0][1]] = true;
    res.resize(n);
    for (int i = 1; i < ans.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            if (!dp[i - 1][j]) continue;
            dp[i][j + ans[i][0]] = true;
            dp[i][j + ans[i][1]] = true;
        }
    }
    if (!dp[ans.size() - 1][n2]) {
        cout << "NO";
        return 0;
    }
    vector <bool> two(n);
    int now = n2;
    for (int i = ans.size() - 1; i >= 0; --i) {
        if (i == 0) {
            if (now == ans[0][0]) two[i] = false;
            else two[i] = true;
        }
        else {
            if (now - ans[i][0] >= 0 && dp[i - 1][now - ans[i][0]]) {
                two[i] = false;
                now -= ans[i][0];
            }
            else {
                two[i] = true;
                now -= ans[i][1];
            }
        }
    }
    used.assign(n, false);
    int ghg = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (!two[ghg]) res[i] = 2;
            else {
                if (n1 > 0) {
                    --n1;
                    res[i] = 1;
                }
                else {
                    --n3;
                    res[i] = 3;
                }
            }
            ++ghg;
            paint(i);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << res[i];
    }
}