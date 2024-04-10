#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int min_ans = n;
        for (int c = 1; c <= 100; c++) {
            int cur = 0;
            int cur_ans = 0;
            while (cur < n) {
                if (arr[cur] == c)
                    cur++;
                else
                    cur_ans++, cur += k;
            }
            min_ans = min(min_ans, cur_ans);
        }
        cout << min_ans << '\n';
    }
}