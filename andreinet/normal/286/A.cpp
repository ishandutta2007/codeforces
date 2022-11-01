#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

int A[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    bool ok = true;
    if (n % 2 == 1) {
        if ((n - 1) % 4 == 0) {
            for (int i = 1; i <= n / 2; i += 2) {
                A[i] = i + 1;
                A[i + 1] = n - i + 1;
                A[n - i + 1] = n - i;
                A[n - i] = i;
            }
            A[n / 2 + 1] = n / 2 + 1;
        } else { 
            ok = false;
        }
    } else {
        if (n % 4 == 0) {
            for (int i = 1; i <= n / 2; i += 2) {
                A[i] = i + 1;
                A[i + 1] = n - i + 1;
                A[n - i + 1] = n - i;
                A[n - i] = i;
            }
        } else {
            ok = false;
        }
    }

    if (!ok) {
        cout << "-1\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << A[i] << ' ';
        }
        cout << '\n';
    }
}