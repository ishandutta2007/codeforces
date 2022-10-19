#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>

using namespace std;
#define int long long
int MAXW = 2000;

inline int ask(int x) {
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

signed main() {
    int n;
    cin >> n;
    int l = 0, r = n * MAXW + n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(m) == 1) r = m;
        else l = m;
    }
    int ans = r;
    for (int h = 1; h <= n; ++h) {
        int res = ask(r / h);
        if (res) ans = min(ans, res * (r / h));
    }
    cout << "! " << ans << endl;
    return 0;
}