#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<int> di = {0, 0, -1, 1};
vector<int> dj = {-1, 1, 0, 0};

vector<vector<int>> usd;
vector<string> a;

int n, m;

void dfs(int i, int j) {
    usd[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int nowi = i + di[k], nowj = j + dj[k];
        if (nowi < 0 || nowi >= n || nowj < 0 || nowj >= m) continue;
        if (usd[nowi][nowj]) continue;
        if (a[nowi][nowj] == '#') continue;
        dfs(nowi, nowj);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.clear();
        a.resize(n);
        for (auto &c : a) cin >> c;
        bool f = false;
        int cntg = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'G') cntg++;
                if (a[i][j] != 'B') continue;
                for (int k = 0; k < 4; k++) {
                    int nowi = i + di[k], nowj = j + dj[k];
                    if (nowi < 0 || nowi >= n || nowj < 0 || nowj >= m) continue;
                    if (a[nowi][nowj] == 'G') {
                        f = true;
                        continue;
                    }
                    if (a[nowi][nowj] == 'B') continue;
                    else a[nowi][nowj] = '#';
                }
            }
        }
        if (cntg == 0) {
            cout << "Yes\n";
            continue;
        }
        if (f) {
            cout << "No\n";
            continue;
        }
        usd.assign(n, vector<int>(m));
        dfs(n - 1, m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (usd[i][j] == 0 && a[i][j] == 'G') f = true;
                if (usd[i][j] == 1 && a[i][j] == 'B') f = true;
            }
        }
        if (f) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}