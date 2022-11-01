#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string S;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        for (int j = i; j < n; ++j) {
            if (S[j] == 'U') {
                x--;
            } else if (S[j] == 'D') {
                x++;
            } else if (S[j] == 'L') {
                y--;
            } else if (S[j] == 'R') {
                y++;
            } else {
                throw 3;
            }
            ans += (x == 0 && y == 0);
        }
    }
    cout << ans << '\n';
}