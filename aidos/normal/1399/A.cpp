#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)100200;
const ll inf = (1ll<<50);

int n;
int a[maxn], b[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1] + 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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