#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)2e5 + 9;
int cnt[20];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for(int j = 0; j < 20; ++j)
            if(x&(1 << j))
                ++cnt[j];
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll x = 0;
        for(int j = 0; j < 20; ++j)
            if(i < cnt[j])
                x |= 1 << j;
            ans += x* x;
    }
    cout << ans;

    return 0;
}