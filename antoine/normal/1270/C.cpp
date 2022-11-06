#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
int a[MxN + 9];

void f() {
    int n;
    cin >> n;

    ll xo  = 0, sum = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        xo ^= x;
    }
    cout << "2\n" << xo << ' ' << sum + xo << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int _t;
    cin >> _t;
    while (_t--)
        f();
    return 0;
}