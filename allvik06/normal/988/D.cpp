#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<long long> a(n);
    set <long long> s;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<long long> two(32);
    two[0] = 1;
    for (long long i = 1; i < 32; ++i) {
        two[i] = two[i - 1] * 2;
    }
    //cout << two[29];
    long long ans = 1;
    pair <long long, long long> res;
    for (long long i = 0; i < 32; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (s.find(a[j] + two[i]) != s.end() && s.find(a[j] - two[i]) != s.end()) {
                cout << 3 << "\n";
                cout << a[j] + two[i] << " " << a[j] << " " << a[j] - two[i];
                return 0;
            }
            if (s.find(a[j] + two[i]) != s.end()) {
                ans = 2;
                res.first = a[j] + two[i];
                res.second = a[j];
            }
            if (s.find(a[j] - two[i]) != s.end()) {
                ans = 2;
                res.first = a[j] - two[i];
                res.second = a[j];
            }
        }
    }
    if (ans == 2) {
        cout << 2 << "\n";
        cout << res.first << " " << res.second;
    }
    else {
        cout << 1 << "\n" << a[0];
    }
}