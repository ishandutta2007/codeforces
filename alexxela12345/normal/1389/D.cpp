#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18 + 228;

int calc(pair<int, int> aa, pair<int, int> bb) {
    return max(0LL, min(aa.second, bb.second) - max(aa.first, bb.first));
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        pair<int, int> aa;
        cin >> aa.first >> aa.second;
        pair<int, int> bb;
        cin >> bb.first >> bb.second;
        if (bb.first < aa.first) {
            swap(aa, bb);
        }
        int cur_int_len = n * calc(aa, bb);
        if (cur_int_len >= k) {
            cout << 0 << endl;
            continue;
        }
        int best_ans = INF;
        for (int i = 1; i <= n; i++) {
            pair<int, int> aaa = aa;
            pair<int, int> bbb = bb;
            int rem = k - cur_int_len;
            int cnt1 = max(0LL, bb.first - aa.second);
            bb.first -= cnt1;
            int cntMoves = cnt1 * i;
            int can1 = 2 * (max(aa.second, bb.second) - min(aa.first, bb.first)) - (aa.second - aa.first) - (bb.second - bb.first);
            can1 *= i;
            cntMoves += min(rem, can1);
            rem -= can1;
            if (rem < 0) {
                rem = 0;
            }
            cntMoves += 2 * rem;
            best_ans = min(best_ans, cntMoves);
            aa = aaa;
            bb = bbb;
        }
        cout << best_ans << endl;
    }
}