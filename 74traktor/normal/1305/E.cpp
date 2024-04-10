#include<bits/stdc++.h>

using namespace std;

unordered_map < int, int > cnt;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ptr = 1;
    cin >> n >> m;
    vector < int > ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = ptr;;++j) {
            if (cnt[j] <= m) {
                m -= cnt[j];
                ans.push_back(j);
                ptr = j + 1;
                break;
            }
        }
        for (int j = 0; j < (int)ans.size() - 1; ++j) cnt[ans[j] + ans.back()]++;
    }
    if (m != 0) cout << -1 << '\n';
    else {
        for (auto key : ans) cout << key << " ";
    }
    return 0;
}