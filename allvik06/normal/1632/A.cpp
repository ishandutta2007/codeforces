#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <random>
#include <array>

using namespace std;

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
        string s;
        cin >> n >> s;
        if (n > 2 || (n == 2 && s[0] == s[1])) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

/*
3 4
0 0 0
+ 1
+ 2
+ 2
- 1
 */