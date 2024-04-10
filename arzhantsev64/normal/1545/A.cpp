#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return (p.first * 1791791791 + p.second * 17) % (int)(1e9 + 7);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    unordered_map<pair<int, int>, int, hash_pair> cnt1;
    for (int i = 0; i < n; ++i)
        cnt1[{v[i], i % 2}]++;
    sort(v.begin(), v.end());
    unordered_map<pair<int, int>, int, hash_pair> cnt2;
    for (int i = 0; i < n; ++i)
        cnt2[{v[i], i % 2}]++;
    for (auto i : cnt2)
        if (cnt1[i.first] != i.second) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
	return 0;
}