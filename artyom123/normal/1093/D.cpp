#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void dfs(int v, vector <int> &col, vector<pair<int, int>> &comp, int now, vector <vector<int>> &g) {
    col[v] = now;
    comp.push_back({v, now});
    for (auto &to : g[v]) {
        if (col[to] == 0 && now == 1) {
            dfs(to, col, comp, 2, g);
        }
        if (col[to] == 0 && now == 2) {
            dfs(to, col, comp, 1, g);
        }
    }
}

const long long mod = 998244353;

long long mpow(long long n, long long m) {
    if (m == 0) {
        return 1;
    }
    long long now = mpow(n, m / 2);
    now *= now;
    now %= mod;
    if (m % 2 == 0) {
        return now;
    }
    return (now * n) % mod;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        int n, m;
        cin >> n >> m;
        vector <vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        vector <long long> ans;
        vector <int> col(n);
        for (int i = 0; i < n; i++) {
            if (col[i] == 0) {
                vector <pair<int, int>> comp;
                dfs(i, col, comp, 1, g);
                long long ans1 = 0, ans2 = 0;
                for (int j = 0; j < comp.size(); j++) {
                    if (comp[j].second == 1) {
                        ans1++;
                    }
                    else {
                        ans2++;
                    }
                }
                long long ansn = 0;
                ansn += mpow(2, ans1);
                ansn += mpow(2, ans2);
                ansn %= mod;
                ans.push_back(ansn);
            }
        }
        bool f = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (col[i] == col[g[i][j]]) {
                    f = false;
                }
            }
        }
        if (f) {
            long long k = 1;
            for (auto &c : ans) {
                k *= c;
                k %= mod;
            }
            cout << k << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    return 0;
}