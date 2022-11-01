#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 105;

int A[Nmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int maxv = -Nmax, minv = Nmax;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        maxv = max(maxv, A[i]);
        minv = min(minv, A[i]);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (A[i] == maxv) {
            ans += i - 1;
            break;
        }
    }
    for (int i = N; i > 0; --i) {
        if (A[i] == minv) {
            if (i <= ans) --ans;
            ans += N - i;
            break;
        }
    }
    cout << ans << '\n';
}