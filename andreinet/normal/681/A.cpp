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
    cin.tie(0);

    int n;
    cin >> n;

    while (n-- > 0) {
        string s;
        int oldScore, newScore;
        cin >> s >> oldScore >> newScore;

        if (oldScore >= 2400 && newScore > oldScore) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}