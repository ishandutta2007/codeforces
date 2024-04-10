#include <bits/stdc++.h>

using namespace std;
#define int long long


signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int now = 3;
        bool flag = false;
        while (now <= n) {
            if (n % now == 0)  {
                cout << n / now << "\n";
                flag = true;
            }
            if (flag) break;
            now <<= 1;
            ++now;
        }
    }
}