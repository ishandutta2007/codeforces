#include <bits/stdc++.h>
using namespace std;

//#define int long long
//#define endl "\n"

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (m >= n && k >= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}