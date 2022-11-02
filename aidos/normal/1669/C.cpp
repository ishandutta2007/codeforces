
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e4 + 10;
int n, m;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 2; i < n; i++) {
        if(a[i] % 2 != a[i % 2] % 2) {
            cout << "NO\n";
            return;
        }
    }
    cout <<"YES\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}