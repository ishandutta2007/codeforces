#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[n];
    vector<int> sk[2];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
        sk[a[i]].push_back(b[i]);
    }
    ranges::sort(sk[0]);
    ranges::sort(sk[1]);
    ranges::reverse(sk[0]);
    ranges::reverse(sk[1]);
    if(sk[0].size() < sk[1].size()) {
        swap(sk[0], sk[1]);
    }
    if(sk[0].size() == sk[1].size()) {
        sum += sum - *min_element(b, b + n);
    } else {
        sum += accumulate(all(sk[1]), (int)0);
        sum += accumulate(begin(sk[0]), begin(sk[0]) + sk[1].size(), (int)0);
    }
    cout << sum << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}