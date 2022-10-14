#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<int> p;
vector<int> cnt0, cnt1;

int get_parent(int v) {
    if (p[v] == v) return v;
    return p[v] = get_parent(p[v]);
}

void merge(int v, int u) {
    v = get_parent(v);
    u = get_parent(u);
    if (v == u) return;
    cnt0[v] += cnt0[u];
    cnt1[v] += cnt1[u];
    p[u] = v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        cnt0.assign(n * m, 0), cnt1.assign(n * m, 0), p.assign(n * m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                p[i * m + j] = i * m + j;
                if (a[i][j] == 0) cnt0[i * m + j] = 1;
                else cnt1[i * m + j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int i1 = 0; i1 < n; i1++) {
                    int j1 = n + m - 2 - i - j - i1;
                    if (j1 < 0 || j1 >= m) continue;
                    if (i1 < i || j1 < j) continue;
                    merge(i * m + j, i1 * m + j1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (get_parent(i * m + j) == i * m + j) ans += cnt0[i * m + j] + cnt1[i * m + j] - max(cnt0[i * m + j], cnt1[i * m + j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}