#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        x = abs(x);
        y = abs(y);
        cout << 2 * (x % 2) + (y % 2) + 1 << '\n';
    }
    return 0;
}