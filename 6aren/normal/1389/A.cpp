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
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int l, r;
        cin >> l >> r;
        if (l > r / 2) cout << -1 << ' ' << -1 << '\n';
        else cout << r / 2 << ' ' << r / 2 * 2 << '\n';
    }
    return 0;
}