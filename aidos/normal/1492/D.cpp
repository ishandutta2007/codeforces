#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
int n, m, k;

void solve() {
    cin >> n >> m >> k;
    if(k == 0) {
        cout << "Yes\n";
        cout << string(m, '1') + string(n, '0') << "\n";
        cout << string(m, '1') + string(n, '0') << "\n";
        return;
    }
    if(n + m - 2 < k || n == 0 || m <= 1) {
        cout << "No\n";
        return;
    }

    string x = "11";
    string y = "10";
    m-=2;
    n--;
    k--;
    while(k > 0 && m > 0) {
        k--;
        m--;
        x += '1';
        y += '1';
    }
    while(k > 0 && n > 0) {
        k--;
        n--;
        x += '0';
        y += '0';
    }
    x += '0';
    y += '1';
    x += string(m, '1');
    y += string(m, '1');
    x += string(n, '0');
    y += string(n, '0');
    cout << "Yes\n";
    cout << x << "\n" << y << "\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}