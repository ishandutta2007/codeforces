#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        map < int, int > cnt;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            for (int j = 0; j < 30; ++j) {
                if ((x>>j)&1) cnt[j]++;
            }
        }
            int answer = 0;
            for (auto key : cnt) {
                answer = __gcd(answer, key.second);
            }
            vector < int > ans;
            for (int i = 1; i <= n; ++i) {
                if (answer % i == 0) cout << i << " ";
            }
            cout << '\n';
        }
    return 0;
}