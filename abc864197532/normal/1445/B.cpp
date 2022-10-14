#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 1e5, mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << max(a + b, c + d) << endl;
    }
}