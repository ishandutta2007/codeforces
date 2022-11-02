#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)2e5 + 100;
int n, m;
void solve() {
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; ; i++) {
        sum += i;
        if(sum + n >= m && sum + m >= n) {
            if((sum + n) % 2 == m % 2) {
                cout << i << "\n";
                return;
            }
        }
    }
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}