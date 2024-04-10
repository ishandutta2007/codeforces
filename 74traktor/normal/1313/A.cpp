#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, c;
    cin >> t;
    vector < vector < int > > T;
    for (int mask = 1; mask < 8; ++mask) {
        vector < int > f;
        for (int j = 0; j < 3; ++j) {
            if ((mask&(1 << j)) > 0) f.push_back(1);
            else f.push_back(0);
        }
        T.push_back(f);
    }
    while (t--) {
        cin >> a >> b >> c;
        int ans = 0;
        for (int mask = 0; mask < (1 << (int)T.size()); ++mask) {
            int sum_a = 0, sum_b = 0, sum_c = 0, cnt = 0;
            for (int j = 0; j < (int)T.size(); ++j) {
                if ((mask&(1 << j)) > 0) {
                    sum_a += T[j][0], sum_b += T[j][1], sum_c += T[j][2], cnt++;
                }
            }
            if (sum_a <= a && sum_b <= b && sum_c <= c) ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}