#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);*/
    int n;
    cin >> n;
    vector <int> a(n), b(n), v(n);
    vector <int> all;
    vector <int> ans, end;
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] != -1) { b[i]--; v[b[i]]++; }
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) all.push_back(i);
    }
    while (!all.empty()) {
        int in = all.back();
        all.pop_back();
        sum += a[in];
        if (a[in] <= 0) {
            end.push_back(in);
            if (b[in] != -1) {
                v[b[in]]--;
                if (v[b[in]] == 0) all.push_back(b[in]);
            }
        }
        else {
            ans.push_back(in);
            if (b[in] != -1) {
                a[b[in]] += a[in];
                v[b[in]]--;
                if (v[b[in]] == 0) all.push_back(b[in]);
            }
        }
    }
    cout << sum << "\n";
    for (int i : ans) cout << i + 1 << " ";
    reverse(end.begin(), end.end());
    for (int i : end) cout << i + 1 << " ";
}