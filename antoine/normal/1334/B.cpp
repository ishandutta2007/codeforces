#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll &x:a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;

    int cnt = 0;
    ll sum = 0;
    for(int i = n - 1; i >= 0; --i) {
        sum += a[i];
        cnt++;
        if(sum >= x * cnt)
            ans = cnt;
    }

    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
        cout << f() << '\n';
    return 0;
}