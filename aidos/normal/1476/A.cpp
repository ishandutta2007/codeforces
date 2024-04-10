#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)1000200;
const ll inf = (1ll<<50);
int n;
int k;
void solve() {
    cin >> n >> k;
    if(n % k == 0) {
        cout << 1 << "\n";
        return;
    }
    if(k < n) {
        cout << 2 << "\n";
        return;
    }
    cout <<(k+n-1)/n << "\n";
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