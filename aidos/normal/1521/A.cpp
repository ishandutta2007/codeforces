#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int k;
ll A, B;
void solve() {
    cin >> A >> B;
    if(B == 1) {
        cout << "NO\n";
        return;
    }
    if(B > 2) {
        cout << "YES\n";
        cout << A << " " << A * (B - 1) << " " << A * B << "\n";
        return;
    }

    cout << "YES\n";
    cout << A << " " << A * 2 << " " << A * 3 << "\n";
    return;
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}