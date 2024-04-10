#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.first << ", " << p.second << ")";
}
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int q; cin >> q;
    ll sum = 0;
    vector<ll> diff;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > 0) {
            sum += a[i + 1] - a[i];
        }
        diff.push_back(a[i + 1] - a[i]);
    }
    auto eval = [&](ll x) -> ll {
        if (x >= 0) return (x + 1) / 2;
        return -(-x / 2);
    };
    ll beg = a[0];
    cout << eval(beg + sum) << '\n';
    while (q--) {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        l--, r--;
        if (l > 0) {
            ll old = diff[l - 1];
            if (old > 0) sum -= old;
            diff[l - 1] += x;
            if (diff[l - 1] > 0) sum += diff[l - 1];
        }
        if (r + 1 != n) {
            ll old = diff[r];
            if (old > 0) sum -= old;
            diff[r] -= x;
            if (diff[r] > 0) sum += diff[r];
        }
        if (l == 0) beg += x;
        cout << eval(beg + sum) << '\n';
    }
    return 0;
}