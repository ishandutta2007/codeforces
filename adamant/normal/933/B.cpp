#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p, k;
    cin >> p >> k;
    vector<int> ans;
    int rem = 0;
    while(p) {
        if(ans.size() % 2 == 0) {
            ans.push_back(p % k + rem);
            rem = ans.back() / k;
            ans.back() %= k;
        } else {
            int t = p % k + rem;
            int rmm = (t + k - 1) / k;
            ans.push_back(rmm * k - t);
            rem = rmm;
        }
        p /= k;
    }
    while(rem) {
        if(ans.size() % 2 == 0) {
            ans.push_back(rem);
            rem = ans.back() / k;
            ans.back() %= k;
        } else {
            int t = rem;
            int rmm = (t + k - 1) / k;
            ans.push_back(rmm * k - t);
            rem = rmm;
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}