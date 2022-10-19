#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    vector<int> basis;
    int n;
    cin >> n;
    int sr = 0;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        sr ^= u;
        for (int b : basis) {
            if ((b ^ u) < u) u ^= b;
        }
        if (u > 0) {
            for (int &b : basis) {
                if ((b ^ u) < b) b ^= u;
            }
            basis.pb(u);
        }
    }
    if (sr == 0) return cout << -1, 0;
    cout << basis.size();
    return 0;
}