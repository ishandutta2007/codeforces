#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x : a)cin >> x;
    sort(a.begin(), a.end());
    for(int i = n- 2; i >= 0; --i)
        a[i] = min(a[i], a[i+1]-1);

    ll ans = 0;
    for(ll &x : a)
        ans += max(0LL, x);
    cout << ans;
    return 0;
}