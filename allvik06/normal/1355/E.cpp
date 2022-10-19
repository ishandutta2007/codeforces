#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 1;

int kol(vector <int> &h, vector <int> &p, int n, int a, int r, int m, int z) {
    int f = -1;
    for (int i = 0; i < n; ++i) {
        if (h[i] >= z) {
            f = i;
        }
    }
    int vv = min(m, a + r), sum = p[n - 1], ans = 0;
    if (f != -1) sum -= p[f];
    for (int i = 0; i <= f; ++i) {
        int kol = h[i] - z;
        if (kol <= z * (n - f - 1) - sum) {
            ans += vv * kol;
            sum += kol;
        }
        else {
            ans += vv * (z * (n - f - 1) - sum);
            ans += (h[i] - (z * (n - f - 1) - sum) - z) * r;
            sum = z * (n - f - 1);
        }
    }
    ans += (z * (n - f - 1) - sum) * a;
    return ans;
}

signed main() {
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int n, a, r, m;
     cin >> n >> a >> r >> m;
     vector <int> h(n);
     for (int i = 0; i < n; ++i) cin >> h[i];
     sort(h.rbegin(), h.rend());
     vector <int> p(n);
     p[0] = h[0];
     for (int i = 1; i < n; ++i) {
         p[i] = p[i - 1] + h[i];
     }
     int left = -1, right = INF;
     while (right - left > 1) {
         int mf = left + max((right - left) / 3, 1LL);
         int ms = right - max((right - left) / 3, 1LL);
         if (mf == 1 || ms == 1) {
             int flex = 0;
         }
         if (kol(h, p, n, a, r, m, mf) < kol(h, p, n, a, r, m, ms)) {
             right = ms;
         }
         else {
             left = mf;
         }
     }
     cout << min(kol(h, p, n, a, r, m, left), kol(h, p, n, a, r, m, right));
}