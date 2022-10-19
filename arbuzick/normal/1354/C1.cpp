#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[30][30];
long double pi = 3.1415926535;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long double ans = 1.0/(tan(pi/(2.0*n)));
        cout << ans << '\n';
    }
    return 0;
}