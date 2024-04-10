#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

int value(char c) {
    if (c == 'N') return 0;
    if (c == 'S') return 1;
    if (c == 'E') return 2;
    if (c == 'W') return 3;
    return -1;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    n--;

    string S1, S2;
    cin >> S1 >> S2;

    for (char &c: S2) {
        if (c == 'N') c = 'S';
        else if (c == 'S') c = 'N';
        else if (c == 'E') c = 'W';
        else c = 'E';
    }
    int h11 = 0, h12 = 0;
    int h21 = 0, h22 = 0;
    int pw1 = 1, pw2 = 1;
    
    for (int i = n - 1; i >= 0; --i) {
        int v1 = value(S1[i]), v2 = value(S2[i]);
        h11 = ((int64_t) h11 * 4 + v1) % MOD1;
        h12 = ((int64_t) h12 * 4 + v1) % MOD2;
        h21 = (h21 + (int64_t) pw1 * v2) % MOD1;
        h22 = (h22 + (int64_t) pw2 * v2) % MOD2;

        if (h11 == h21 && h12 == h22) {
            cout << "NO" << endl;
            return 0;
        }

        pw1 = (int64_t) pw1 * 4 % MOD1;
        pw2 = (int64_t) pw2 * 4 % MOD2;
    }

    cout << "YES" << endl;
}