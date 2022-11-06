#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = (int)1e5+ 9;
ll a[MxN + 9];

void f() {
    int n, mx = -(int)1e9, res = 0;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x > mx)
            mx = x;
        else
            res = max(res, mx - x);
    }
    int ans = 0;
    for(; res; res >>= 1)
        ++ans;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        f();
    return 0;
}