// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;

template <typename T>
void read(vector<T>& vec) {
    for (auto& elem : vec) {
        cin >> elem;
    }
}

template <typename T>
void write(vector<T>& vec, char delim = ' ', char last = '\n') {
    bool first = true;
    for (auto& elem : vec) {
        if (!first) {
            cout << delim;
        }
        cout << elem;
        first = false;
    }
    cout << last;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> s(n);
    read(s);
    sort(all(s));
    vector<ll> diff(n - 1);
    for (int i = 0; i + 1 < n; i++) {
        diff[i] = s[i + 1] - s[i];
    }
    sort(all(diff));
    vector<ll> pref(n);
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + diff[i - 1];
    }

    int q;
    cin >> q;
    for (int query = 0; query < q; query++) {
        ll l, r;
        cin >> l >> r;
        ll len = r - l + 1;
        int pos = upper_bound(all(diff), len) - begin(diff);
        cout << pref[pos] + (n - pos) * len << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}