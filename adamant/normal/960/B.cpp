#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    multiset<int, greater<int>> que;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum += (a[i] - b[i]) * (a[i] - b[i]);
        que.insert(abs(a[i] - b[i]));
        
    }
    int t = k1 + k2;
    while(t--) {
        auto it = begin(que);
        que.erase(it);
        sum -= *it * *it;
        sum += (*it - 1) * (*it - 1);
        que.insert(abs(*it - 1));
    }
    cout << sum << endl;
    return 0;
}