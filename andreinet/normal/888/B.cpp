#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt[4] = {0};
    for (char c: s) {
        if (c == 'L') {
            cnt[0]++;
        } else if (c == 'R') {
            cnt[1]++;
        } else if (c == 'U') {
            cnt[2]++;
        } else if (c == 'D') {
            cnt[3]++;
        }
    }
    cout << 2 * (min(cnt[0], cnt[1]) + min(cnt[2], cnt[3])) << '\n';
}