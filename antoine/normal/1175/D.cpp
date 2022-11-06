#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x: a)
        cin >> x;
    partial_sum(a.begin(), a.end(), a.begin());
    sort(a.begin(), a.end() - 1);

    ll ans = a.back() * k - accumulate(a.begin(), a.begin() + k - 1, 0LL);
    cout << ans;

    return 0;
}