#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector < vector <int> > g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] != 1) {
        cout << "No";
        return 0;
    }
    set <int> s;
    int last = -1;
    int ok = 1;
    for (int i = 0; i < g[0].size(); i++) {
        s.insert(g[0][i]);
    }
    for (int i = 1; i < n; i++) {
        if (s.find(a[i] - 1) == s.end()) {
            last++;
            if (last == i) {
                cout << "No";
                return 0;
            }
            s.clear();
            for (int j = 0; j < g[a[last] - 1].size(); j++) {
                s.insert(g[a[last] - 1][j]);
            }
            i--;
            continue;
        }
        else {
            ok++;
        }
    }
    if (ok == n) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}