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
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> pos;
        vector<ll> neg;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                pos.push_back(a[i]);
            } else {
                neg.push_back(a[i]);
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        if (pos.size() + neg.size() < 5) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = -1e18;
        auto get = [&](int t, vector<ll>& v, int num) -> ll {
            ll res = 1;
            if (t == 0) {
                for (int i = 0; i < num; i++) {
                    res *= v[i];
                }
                return res;
            } else {
                for (int i = (int) v.size() - 1; i >= (int) v.size() - num; i--) {
                    res *= v[i];
                }
                return res;
            }
        };
        for (int i = 0; i <= 5; i++) {
            int j = 5 - i;
            if (i > pos.size() || j > neg.size()) continue;
            for (int t1 = 0; t1 < 2; t1++) {
                for (int t2 = 0; t2 < 2; t2++) {
                    ans = max(ans, get(t1, pos, i) * get(t2, neg, j));
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}