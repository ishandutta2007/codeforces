#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int MOD = 1e9 + 7;

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) ret = (int64_t) ret * x % MOD;
        x = (int64_t) x * x % MOD;
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int cnt = 0;
    for (char c: S) {
        int x;
        if ('0' <= c && c <= '9') {
            x = c - '0';
        } else if ('A' <= c && c <= 'Z') {
            x = c - 'A' + 10;
        } else if ('a' <= c && c <= 'z') {
            x = c - 'a' + 36;
        } else if (c == '-') {
            x = 62;
        } else {
            x = 63;
        }
        for (int i = 0; i < 6; ++i) {
            if (x & (1 << i)) {

            } else {
                cnt++;
            }
        }
    }
    int ans = Pow(3, cnt);
    cout << ans << '\n';
}