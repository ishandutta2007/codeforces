#include<bits/stdc++.h>

using namespace std;

vector < int > solve(int n, int i) {
    if (i == -1) return {0};
    if ((1 << i) > n) return solve(n, i - 1);
    vector < int > ans = solve(n - (1 << i), i - 1);
    int c = ans.back();
    for (int j = 0; j < (int)ans.size(); ++j) ans[j] += (1 << i);
    ans.push_back(c);
    for (int j = 0; j < (1 << i); ++j) {
        if (j != c) ans.push_back(j);
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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int i = 0;
        while ((1 << i) <= n - 1) i++;
        i--;
        vector < int > ans = solve(n - 1, i);
        for (auto key : ans) cout << key << " ";
        cout << '\n';
    }
    return 0;
}