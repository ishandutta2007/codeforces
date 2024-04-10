#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
int a[maxn];
void solve() {
    cin >> n >> x;
    int s = 0, f = -1, l = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        if(a[i] % x != 0) {
            if(f == -1) f = i;
            l = i;
        }
    }
    if(f == -1) {
        cout << -1 << "\n";
    } else {
        if(s % x == 0) cout << max(l, n - 1 - f) << "\n";
        else cout << n << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}