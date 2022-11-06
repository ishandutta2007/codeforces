#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> ns(n), fs(n);
    for (int i = 0; i < n; i++) {
        cin >> ns[i] >> fs[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    string last = min(ns[p[0]], fs[p[0]]);
    for (int i = 1; i < n; i++) {
        int x = p[i];
        if (min(ns[x], fs[x]) > last) {
            last = min(ns[x], fs[x]);
        } else if (max(ns[x], fs[x]) > last) {
            last = max(ns[x], fs[x]);
        } else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}