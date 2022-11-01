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

    int a[27] = {0};
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < SZ(s1); ++i) {
        int x1 = s1[i] - 'a' + 1;
        int x2 = s2[i] - 'a' + 1;
        if (a[x1] != 0 && a[x1] != x2) {
            cout << "-1\n";
            return 0;
        }
        if (a[x2] != 0 && a[x2] != x1) {
            cout << "-1\n";
            return 0;
        }
        a[x1] = x2;
        a[x2] = x1;
    }
    int cnt = 0;
    for (int i = 1; i < 27; ++i) {
        if (a[i] != 0 && a[i] < i) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i < 27; ++i) {
        if (a[i] != 0 && a[i] < i) {
            cnt++;
            cout << (char) (i + 'a' - 1) << ' ' << (char) (a[i] + 'a' - 1) << '\n';
        }
    }
}