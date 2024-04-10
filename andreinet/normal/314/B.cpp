#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 105;

int jump[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string S1, S2;
    cin >> S1 >> S2;

    string S3 = "";
    while (SZ(S3) < SZ(S1)) {
        S3 += S2;
    }
    S3 += S2;

    for (int i = 0; i < SZ(S2); ++i) {
        int pos = i, cnt = 0;
        for (int j = 0; j < SZ(S1); ++j) {
            if (S1[j] == S3[pos]) {
                ++pos;
                cnt++;
            }
        }
        jump[i] = cnt;
    }

    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += jump[ans % SZ(S2)];
    }

    ans = ans / SZ(S2) / m;

    cout << ans << '\n';
}