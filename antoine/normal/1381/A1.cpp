#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    vector<int> res;
    bool flipped = false;

    int n;
    string a, b;
    cin >> n >> a >> b;
    int l = 0, r = n - 1;
    while (l <= r) {
        const int sz = r - l + 1;
        const char c = flipped ?  '1' - a[r]  + '0' : a[l];
        if(c == b[sz - 1])
            res.push_back(1);
        res.push_back(sz);
        flipped ? --r : ++l;
        flipped = !flipped;
    }
    cout << res.size() << ' ';
    for(int x:  res)
        cout << x << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        f();
    }
    return 0;
}