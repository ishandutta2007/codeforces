#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
int n, m;
int a[505][505];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if((i + j) % 2) {
                cout << 720720 + x * x * x *x << " ";
            } else {
                cout << 720720 << " ";
            }
        }
        cout << "\n";
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}