#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 3000005;

int a[N], dep[N];

int dfs(int u) {
    if (a[2 * u] == 0 && a[2 * u + 1] == 0) return u;
    if (a[2 * u] > a[2 * u + 1]) return dfs(2 * u);
    else dfs(2 * u + 1);
}

void dodfs(int u) {
    if (a[2 * u] == 0 && a[2 * u + 1] == 0) {
        a[u] = 0;
        return;
    }
    if (a[2 * u] > a[2 * u + 1]) {
        a[u] = a[2 * u];
        dodfs(2 * u);
    } else {
        a[u] = a[2 * u + 1];
        dodfs(2 * u + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    for (int i = 1; i < N; i++) {
        dep[i] = dep[i / 2] + 1;
    }
    while (ntest--) {
        int h, g;
        cin >> h >> g;
        for (int i = (1 << h); i < (1 << (h + 1)); i++) a[i] = 0;
        vector<int> res;
        priority_queue<ii> pq;
        for (int i = 1; i < (1 << h); i++) {
            cin >> a[i];
            pq.push({a[i], i});
        }
        bool ok = 0;
        vector<int> check((1 << h) + 1);
        while (1) {
            auto u = pq.top();
            pq.pop();
            if (check[u.y] == 1) continue;
            if (dep[u.y] > g) continue;
            while (dep[dfs(u.y)] > g) {
                // cout << u.y << endl;
                // cout << dfs(u.y) << ' ' << dep[dfs(u.y)] << endl;
                res.pb(u.y);
                dodfs(u.y);
            }
            int t = dfs(u.y);
            while (t != 0) {
                check[t] = 1;
                t /= 2;
            }
            if (res.size() == (1 << h) - (1 << g)) break;
        }
        long long sum = 0;
        for (int i = 1; i < (1 << g); i++) sum += a[i];
        cout << sum << '\n';
        for (int e : res) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}