#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Nmax = 1005;

struct Circle {
    int x, y, r;
};

Circle A[Nmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int XA, YA, XB, YB;
    cin >> XA >> YA >> XB >> YB;

    if (XA > XB) swap(XA, XB);
    if (YA > YB) swap(YA, YB);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> A[i].x >> A[i].y >> A[i].r;

    int ans = 0;
    for (int i = XA; i <= XB; ++i) {
        for (int j = YA; j <= YB; ++j) {
            if (!(i == XA || i == XB || j == YA || j == YB)) continue;
            bool ok = true;
            for (int k = 1; k <= N; ++k) {
                int d = (A[k].x - i) * (A[k].x - i) + (A[k].y - j) * (A[k].y - j);
                if (d <= A[k].r * A[k].r) {
                    ok = false;
                    break;
                }
            }
            if (ok) ++ans;
        }
    }
    cout << ans << '\n';
}