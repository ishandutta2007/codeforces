#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500;
const ll inf = (1ll<<50);
int n, d;
int a[maxn];
void solve() {
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 2; i < n; i++) {
        if(min(a[i], a[0] + a[1]) > d) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}