#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back(make_tuple(u, v, i));
    }
    sort(a.begin(), a.end());
    bool passed = false;
    long long ans = 0;
    int cur = 0;
    // cout << a.size() << endl;
    for (auto e : a) {
        int u = get<0>(e);
        int c = get<1>(e);
        int id = get<2>(e);
        ans += c;
        // cout << u << ' ' << cur << endl;
        if (passed && u > cur) {
            ans += u - cur;
            // cout << u << ' ' << cur << endl;
        }
        cur = max(cur, u + c);
        passed = true;
    }

    cout << ans << '\n';

    return 0;
}