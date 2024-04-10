#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

mt19937 rnd(228);

const int inf = 1e9;

typedef long long ll;

set <int> q[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto f = [&] (int val, int cnt) {
        return (val + cnt - 1) / cnt;
    };
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        int lk = 0, rk = n;
        for (int i = 1; i <= n; i++) {
            if (b[i] > i) {
               lk = max(lk, i);
               rk = min(rk, b[i] - 1);
            } else {
                lk = max(lk, b[i]);
                rk = min(rk, i - 1);
            }
        }
        cout << lk << '\n';
        vector <vector <int> > g(n + 2);
        for (int i = 1; i <= n; i++) {
            g[b[i]].push_back(i);
        }
        vector <int> q;
        q.push_back(0);
        q.push_back(n + 1);
        for (int i = 0; i < (int) q.size(); i++) {
            int v = q[i];
            sort(g[v].begin(), g[v].end(), [&] (int x, int y) {
                return g[x].size() < g[y].size();
            });
            for (int to : g[v]) {
                cout << to << ' ';
                q.push_back(to);
            }
        }
        cout << '\n';
    }
}