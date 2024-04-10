#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    while (a.size() && a.back() <= k) {
        cnt++;
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    while (a.size() && a.back() <= k) {
        cnt++;
        a.pop_back();
    }
    cout << cnt;

    return 0;    
}