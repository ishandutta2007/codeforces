#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int XMAX = 370;

int cnt1[XMAX], cnt2[XMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        int l, r;
        cin >> s >> l >> r;

        if (s == "M") {
            cnt1[l]++;
            cnt1[r + 1]--;
        } else {
            cnt2[l]++;
            cnt2[r + 1]--;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 366; ++i) {
        cnt1[i] += cnt1[i - 1];
        cnt2[i] += cnt2[i - 1];

        ans = max(ans, min(cnt1[i], cnt2[i]) * 2);
    }
    cout << ans << '\n';
}