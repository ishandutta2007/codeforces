#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1) cout << "-1\n";
        else cout << "0 0 " << n / 2 << "\n";
    }
}

/*

 */