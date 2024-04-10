#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
#define double long double
using namespace std;

typedef long long i64;

double getAns(int n, int l, int v1, int v2, int k, double off) {
    double ans = 0;
    double dist = 0;
    bool step = false;
    while (n > 0) {
        double time = (l - dist - off) / (v2 - v1);
        if (time * v1 > off) {
            time = (l - dist) / v2;
        }
        n -= k;
        ans += time;
        dist += time * v1;
        off -= time * v1;
        off = max(off, (double) 0);
        if (n > 0) {
            double time1 = (l - dist - off) / (v1 + v2);
            dist += time1 * v1;
            ans += time1;
            off -= time1 * v1;
            off = max(off, (double) 0.0);
        }
        step = true;
    }
    ans += off / v1;
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    double ans;
    if (v1 >= v2) {
        ans = (double) l / v1;
    } else {
        double left = 0, right = l;
        for (int i = 0; i < 200; ++i) {
            double l1 = (2 * left + right) / 3;
            double l2 = (left + 2 * right) / 3;
            
            double a1 = getAns(n, l, v1, v2, k, l1);
            double a2 = getAns(n, l, v1, v2, k, l2);
            if (a1 + 1e-9 < a2) {
                right = l2;
            } else {
                left = l1;
            }
        }
        ans = getAns(n, l, v1, v2, k, left);
        //ans = getAns(n, l, v1, v2, k, left + 96);
    }
    cout << setprecision(10) << fixed;
    cout << ans << '\n';
}