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

    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int s1 = 0, s2 = 0;
        for (int j = i; j < n; ++j) {
            s1 |= A[j];
            s2 |= B[j];
            ans = max(ans, s1 + s2);
        }
    }
    cout << ans << '\n';
}