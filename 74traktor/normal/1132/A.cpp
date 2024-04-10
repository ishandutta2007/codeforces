#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt1,  cnt2,  cnt3,  cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if (cnt1 == 0 && cnt3 != 0) cout << 0;
    else if (2 * cnt1 - 2 * cnt4 == 0) cout << 1;
    else cout << 0;
    return 0;
}