#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    vector<set<int>> gap(m);
    vector<bool> pushed(m);
    vector<int> empty_sets;
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (b[i][j] < b[i - 1][j]) gap[j].insert(i);
        }
        if (gap[j].empty()) empty_sets.push_back(j), pushed[j] = true;
    }

    vector<bool> check(n);
    vector<int> order;
    while (!empty_sets.empty()) {
        int u = empty_sets.back();
        order.push_back(u);
        empty_sets.pop_back();
        for (int i = 1; i < n; i++) {
            if (b[i][u] != b[i - 1][u] && !check[i]) {
                for (int j = 0; j < m; j++) {
                    gap[j].erase(i);
                    if (gap[j].empty() && !pushed[j]) empty_sets.push_back(j), pushed[j] = true;
                }
                check[i] = 1;
            }
        }
    }
    
    stable_sort(a.begin(), a.end(), [&](const vector<int> &lhs, const vector<int> &rhs) {
        for (auto e : order) {
            if (lhs[e] != rhs[e]) return lhs[e] < rhs[e];
        }
        return false;
    });

    // cout << order.size() << '\n';
    //     for (int e : order) cout << e + 1 << ' ';
    //     cout << '\n';

    if (a == b) {
        cout << order.size() << '\n';
        for (int i = (int) order.size() - 1; i >= 0; i--) cout << order[i] + 1 << ' ';
        cout << '\n';
    } else cout << "-1\n";

    return 0;
}