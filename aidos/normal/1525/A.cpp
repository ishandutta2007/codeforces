#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int k;
void solve() {
    cin >> k;
    for(int i = 1; i <= 100; i++) {
        int cur = i * k;
        if (cur % 100 == 0) {
            cout << i << "\n";
            return;
        }
    }
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}