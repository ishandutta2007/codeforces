#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll sq(ll x) {
    return x * x;
}

void f() {
    // 2* (c*k)^2 <= d^2
    ll d, k, c = 0;
    cin >> d >> k;
    while(2* sq(c*k) <= sq(d)) {
        ++c;
    }
    --c;
    bool res = sq(c*k) + sq((c + 1)*k) <= sq(d);
    cout << (res ? "Ashish" : "Utkarsh") << '\n';

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       f();
    }
    return 0;
}