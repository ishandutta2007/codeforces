#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;

int n, m, x;
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> x;
            if((i + j) % 2 != x % 2) x++;
            cout << x << " ";
        }
        cout << "\n";
    }
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}