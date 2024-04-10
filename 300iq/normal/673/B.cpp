#include <bits/stdc++.h>

#define fc first
#define sc second
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

int color[100000];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, u, v;
    cin >> n >> m;
    if (m == 0) {
        cout << n - 1 << endl;
        return 0;
    }
    bool bad = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;   
        if (u > v) {
            swap(u, v);
        }
        bad |= (color[u] == 2);
        color[u] = 1;
        bad |= (color[v] == 1);
        color[v] = 2;
    }
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            continue;
        }
        if (color[i] == 1) {
            l = i;
        } else if (r == -1) {
            r = i;
        }
    }
    cout << (bad || l > r ? 0 : r - l) << endl;
}