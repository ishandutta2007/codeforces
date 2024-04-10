#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<array<int, 3>> segs(n);
        int minL = 1e9+1, maxR = 0;
        int bestL = 1e9+1, bestR = 1e9+1, bestAll = 2e9+1;
        int bestPrice = 2e9+1;
        for (int i = 0; i < n; i++) {
            cin >> segs[i][0] >> segs[i][1] >> segs[i][2];
            if (minL > segs[i][0]) {
                minL = segs[i][0];
                bestL = segs[i][2];
                bestAll = 2e9+1;
            } else if (minL == segs[i][0]) bestL = min(bestL, segs[i][2]);
            if (maxR < segs[i][1]) {
                maxR = segs[i][1];
                bestR = segs[i][2];
                bestAll = 2e9+1;
            } else if (maxR == segs[i][1]) bestR = min(bestR, segs[i][2]);
            if (minL == segs[i][0] && maxR == segs[i][1]) bestAll = min(bestAll, segs[i][2]);
            bestPrice = min({bestL + bestR, bestAll});
            cout << bestPrice << '\n';
        }
    }
    return 0;
}