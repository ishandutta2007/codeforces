#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;


signed main() {
    int a, b;
    cin >> a >> b;
    int now = 0;
    while (a > 0 && b > 0) {
        if (a == 1 && b == 1) break;
        ++now;
        if (a > b) {
            ++b;
            a -= 2;
        }
        else {
            ++a;
            b -= 2;
        }
    }
    cout << now;
    return 0;
}