#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 205;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    string A;
    cin >> n >> A;

    int cnt[3] = {0};
    for (char c: A) {
        if (c == 'B') cnt[0]++;
        else if (c == 'G') cnt[1]++;
        else cnt[2]++;
    }

    string ans;
    for (int i = 0; i < 3; ++i) {
        bool ok = true;
        for (int j = 0; j < 3; ++j) {
            if (j != i && cnt[j] == 0) {
                ok = false;
            }
        }
        if (cnt[i] >= 1) {
            for (int j = 0; j < 3; ++j) {
                if (j != i && cnt[j] >= 2) {
                    ok = true;
                }
            }
        }

        if (ok) {
            if (i == 0) ans += 'B';
            else if (i == 1) ans += 'G';
            else ans += 'R';
        }

        if (cnt[i] == cnt[0] + cnt[1] + cnt[2]) {
            ans.clear();
            if (i == 0) ans += 'B';
            else if (i == 1) ans += 'G';
            else ans += 'R';
            break;
        }
    }

    cout << ans << '\n';
}