#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<int> di = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> dj = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a;
    a.pb(string(m + 2, '.'));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s.insert(s.begin(), '.');
        s += '.';
        a.pb(s);
    }
    a.pb(string(m + 2, '.'));
    n += 2; m += 2;
    queue<pii> q;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int curi = q.front().fi, curj = q.front().se;
        q.pop();
        for (int k = 0; k < 8; k++) {
            if (curi + di[k] < 0 || curi + di[k] >= n || curj + dj[k] < 0 || curj + dj[k] >= m) continue;
            if (dist[curi + di[k]][curj + dj[k]] == INF) {
                dist[curi + di[k]][curj + dj[k]] = dist[curi][curj] + 1;
                q.push({curi + di[k], curj + dj[k]});
            }
        }
    }
    /*
    for (auto &c : a) cout << c << endl;
    for (auto &c : dist) {
        for (auto &l : c) {
            cout << l;
        }
        cout << endl;
    }
    return 0;
    */
    int left = -1, right = min(n, m);
    vector<pii> ans;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        queue<pii> q;
        vector<vector<int>> dist1(n, vector<int>(m, INF));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] > mid) {
                    dist1[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int curi = q.front().fi, curj = q.front().se;
            q.pop();
            for (int k = 0; k < 8; k++) {
                if (curi + di[k] < 0 || curi + di[k] >= n || curj + dj[k] < 0 || curj + dj[k] >= m) continue;
                if (dist1[curi + di[k]][curj + dj[k]] == INF) {
                    dist1[curi + di[k]][curj + dj[k]] = dist1[curi][curj] + 1;
                    q.push({curi + di[k], curj + dj[k]});
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'X' && dist1[i][j] > mid) ok = false;
            }
        }
        if (!ok) right = mid;
        else {
            left = mid;
            ans.clear();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dist[i][j] > mid) {
                        ans.pb(i, j);
                    }
                }
            }
        }
    }
    cout << left << "\n";
    vector<string> lol(n, string(m, '.'));
    for (auto &c : ans) lol[c.fi][c.se] = 'X';
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            cout << lol[i][j];
        }
        cout << "\n";
    }
    return 0;
}