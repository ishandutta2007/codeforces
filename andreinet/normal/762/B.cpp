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

    int a, b, c;
    cin >> a >> b >> c;

    int m;
    cin >> m;

    vector<pair<int, int>> A(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i].first;
        string s;
        cin >> s;
        if (s == "USB") {
            A[i].second = 0;
        } else {
            A[i].second = 1;
        }
    }
    sort(A.begin(), A.end());
    vector<bool> used(m, false);
    int cnt = 0;
    int64_t cost = 0;
    for (int i = 0; i < m && a > 0; ++i) {
        if (A[i].second == 0) {
            cnt++;
            cost += A[i].first;
            used[i] = true;
            a--;
        }
    }
    for (int i = 0; i < m && b > 0; ++i) {
        if (A[i].second == 1) {
            cnt++;
            cost += A[i].first;
            used[i] = true;
            b--;
        }
    }
    for (int i = 0; i < m && c > 0; ++i) {
        if (!used[i]) {
            cnt++;
            cost += A[i].first;
            used[i] = true;
            c--;
        }
    }
    cout << cnt << ' ' << cost << '\n';
}