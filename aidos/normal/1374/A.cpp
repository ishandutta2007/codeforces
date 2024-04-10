#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)1000200;
const ll inf = (1ll<<50);
int n;
int x, y;
void solve() {
    cin >> x >> y >> n;
    int k = n % x;
    n -= k;
    if(k < y) n -= x;
    
    cout << n + y << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}