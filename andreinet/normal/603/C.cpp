#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 100005;

int A[NMAX];

int f(int x) {
    if (x % 2 == 1) {
        if (x <= 3) return 1;
        else return 0;
    } else {
        if (x == 2) return 0;
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }
        if (x == 3) cnt++;
        if (cnt % 2 == 0) return 2;
        else return 1;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    if (k & 1) {
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            s ^= f(A[i]);
            //cerr << f(A[i]) << endl;
        }
        if (s) cout << "Kevin\n";
        else cout << "Nicky\n";
    } else {
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            s ^= A[i] <= 2 ? A[i]: (A[i] & 1 ^ 1);
        }
        if (s) {
            cout << "Kevin\n";
        } else {
            cout << "Nicky\n";
        }
    }
}