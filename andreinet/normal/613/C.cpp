#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 26, MMAX = 100005;

char fans[MMAX];
int A[NMAX], Cnt[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        m += A[i];
    }

    int ans = 0, ansi = 0, ansr = 0;
    for (int i = 1; i <= m; ++i) {
        if (m % i != 0) continue;
        int s = 0;
        for (int j = 0; j < n; ++j) {
            s += (A[j] % (2 * i) != 0);
        }
        int c = m / i;
        if (c % 2 == 0 && s == 0) {
            int r = i * 2;
            if (r > ans) {
                ans = r;
                ansi = i;
                ansr = -1;
            }
        } else if (c % 2 == 1) {
            for (int j = 0; j < n; ++j) {
                int ss = s - (A[j] % (2 * i) != 0) + ((A[j] - i) % (2 * i) != 0);
                if (ss == 0 && A[j] >= i) {
                    int r = i;
                    if (r > ans) {
                        ans = r;
                        ansi = i;
                        ansr = j;
                    }
                    break;
                }
            }
        }
    }

    if (ans == 0) {
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            while (A[i]-- > 0) { 
                fans[pos++] = i + 'a';
            }
        }
    } else {
        int len = m / ansi;
        if (ansr != -1) {
            for (int i = 0; i < m; i += len) {
                fans[i] = ansr + 'a';
                A[ansr]--;
            }
            len--;
        }
        for (int i = 0; i < n; ++i) {
            Cnt[i] = A[i] / (ansi * 2);
        }
        for (int i = 0; i < m; i += len) {
            if (fans[i]) ++i;
            int pos = i;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < Cnt[j]; ++k) {
                    fans[pos++] = j + 'a';
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                for (int k = 0; k < Cnt[j]; ++k) {
                    fans[pos++] = j + 'a';
                }
            }
        }
    }
    cout << ans << '\n' << fans << '\n';
}