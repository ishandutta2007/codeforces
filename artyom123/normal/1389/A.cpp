#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define fi first
#define se second
#define ll long long

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (r % 2 != 0) r--;
        if (r / 2 < l) cout << -1 << " " << -1 << "\n";
        else cout << r / 2 << " " << r << "\n";
    }
    return 0;
}