#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

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

    int ans = 0, last = -1, cnt = 0, mx = 1;
    int pcnt = 0;
    bool ok2 = false;
    for (char c: S) {
        int x = c - '0';
        if (x == last) {
            cnt++;
            mx = max(mx, cnt);
        } else {
            if (cnt >= 2) pcnt++;
            last = x;
            cnt =  1;
            ans++;
        }
    }
    if (cnt >= 2) pcnt++;
    if (pcnt >= 2) ok2 = true;
    for (int i = 0; i < SZ(S) - 3; ++i) {
        if (S[i] == S[i + 1] && S[i] != S[i + 2] && S[i] != S[i + 3]) {
            ok2 = true;
        }
    }

    if (mx == 2 && !ok2) ans++;
    else if (mx > 2 || ok2) ans += 2;

    cout << ans << '\n';
}