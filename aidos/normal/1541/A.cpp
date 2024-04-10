#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
void solve() {
    cin >> n;
    if(n % 2 == 0) {
        cout << 2 << " " << 1;
    } else {
        cout << 3 << " " << 1 << " " << 2;
    }
    for(int i = 3 + n % 2;  i <= n; i += 2) {
        cout <<" " << i + 1 << " " << i;
    }
    cout << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}