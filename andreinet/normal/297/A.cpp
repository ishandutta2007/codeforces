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

    string A, B;
    cin >> A >> B;

    int parity = 0;
    for (char c: A) {
        parity ^= (c == '1');
    }
    
    if (parity == 1) {
        parity = 0;
        A += '1';
    }
    for (int len = 0; len <= SZ(B) && len <= SZ(A); ++len) {
        int cnt = 0;
        int lim = SZ(A) - len;
        int trlen = len;
        if (A.substr(SZ(A) - len, len) != B.substr(0, len)) {
            continue;
        }
        parity = 0;
        bool can = true;
        while (trlen < SZ(B)) {
            if (parity == B[trlen] - '0') {
                parity ^= B[trlen++] - '0';
            } else if (cnt == lim) {
                can = false;
                break;
            } else {
                parity ^= (A[cnt++] - '0');
            }
        }
        if (can) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}