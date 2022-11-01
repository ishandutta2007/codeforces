#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int MOD = (int) 1e9 + 21;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    string S;
    cin >> m >> S;
    int n = SZ(S);

    string ans;
    vector<bool> taken(n, false);
    for (char c = 'a'; c <= 'z'; ++c) {
        int last = -1;
        int cpos = -1;
        bool respects = true;
        for (int i = 0; i < n; ++i) {
            if (S[i] == c) {
                cpos = i;
            }
            if (taken[i]) {
                last = i;
            }
            if (i - last >= m) {
                if (cpos == -1 || i - cpos > m) {
                    respects = false;
                    break;
                } else {
                    taken[cpos] = true;
                    last = cpos;
                    cpos = -1;
                }
            }
        }
        if (!respects) {
            for (int i = 0; i < n; ++i) {
                if (S[i] == c) {
                    taken[i] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (taken[i]) {
            ans += S[i];
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans << '\n';
}