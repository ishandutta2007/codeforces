#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> parent;
vector<int> s;
vector<int> a;
vector<vector<int>> children;


signed main() {
    cin >> n;
    parent.resize(n, -1);
    children.resize(n);
    s.resize(n);
    a.resize(n, - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> parent[i + 1];
        parent[i + 1]--;
    }
    for (int i = 1; i < n; i++) {
        children[parent[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    a[0] = s[0];
    for (int i = 0; i < n; i++) {
        if (s[i] == -1) {
            if (children[i].size() == 0) {
                a[i] = 0;
            } else {
                a[i] = s[children[i][0]] - s[parent[i]];
                for (int j = 1; j < children[i].size(); j++) {
                    a[i] = min(a[i], s[children[i][j]] - s[parent[i]]);
                }
            }
            s[i] = s[parent[i]] + a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = s[i] - s[parent[i]];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}