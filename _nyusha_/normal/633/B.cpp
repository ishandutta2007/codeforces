#include<bits/stdc++.h>

using namespace std;

#define int long long
int inf = 1e6 + 5;

inline int get(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x / 5;
        x = x / 5;
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    vector < int > ans;
    for (int i = 1; i <= inf; ++i) {
        if (get(i) == x) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key << " ";
    return 0;
}