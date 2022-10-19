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
    int t; cin >> t;
    while (t--) {
        int a, b, c;
        int x, y, z;
        cin >> c >> b >> a;
        cin >> z >> y >> x;
        int ans = 2 * min(a, y);
        int rem_a = a - min(a, y);
        int rem_b = 
        ans -= 2 * min(max(x - rem_a - c, 0), b);
        cout << ans << '\n'; 
    }
    return 0;
}