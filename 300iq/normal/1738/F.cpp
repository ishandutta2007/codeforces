#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

mt19937 rnd(228);

const int inf = 1e9;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> d(n);
        for (int i = 0; i < n; i++) cin >> d[i];
        vector <pair <int, int> > e;
        for (int i = 0; i < n; i++)  e.push_back({d[i], i});
        sort(e.begin(), e.end());
        vector <int> id(n);
        for (int i = 0; i < n; i++) {
            id[e[i].second] = i;
        }
        vector <char> used(n);
        auto ask = [&] (int v) {
            cout << "? " << v + 1 << endl;
            int x;
            cin >> x;
            x--;
            return x;
        };
        vector <vector <int> > g(n);
        auto add_edge = [&] (int u, int v) {
            g[u].push_back(v);
            g[v].push_back(u);
        };

        for (int i = n - 1; i >= 0; i--) {
            int v = e[i].second;
            if (!used[v]) {
                for (int it = 0; it < d[v]; it++) {
                    int u = ask(v);
                    add_edge(u, v);
                    if (used[u]) break;
                    used[u] = true;
                }
                used[v] = true;
            }
        }
        for (int i = 0; i < n; i++) used[i] = false;
        vector <int> ans(n);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                vector <int> q;
                q.push_back(i);
                used[i] = true;
                for (int j = 0; j < (int) q.size(); j++) {
                    int v = q[j];
                    ans[v] = comp;
                    for (int to : g[v]) {
                        if (!used[to]) {
                            used[to] = true;
                            q.push_back(to);
                        }
                    }
                }
                comp++;
            }
        }
        cout << "! ";
        for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
        cout << endl;
    }
}