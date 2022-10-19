#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    int ans = 0;
    int last = -1;
    map<int, int> lastm;
    for (int i = 0; i <= n; i++) {
        if (lastm.count(pref[i])) {
            if (last >= lastm[pref[i]]) {
                
            } else {
                ans++;
                last = i - 2;
            }
        }
        lastm[pref[i]] = i;
    }
    cout << ans << endl;
}