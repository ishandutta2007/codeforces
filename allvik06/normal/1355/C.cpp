#include <bits/stdc++.h>

using namespace std;
#define int long long

int sum(int l, int r) {
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}
signed main() {
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int a, b, c, d;
     cin >> a >> b >> c >> d;
     int ans = 0;
     for (int i = a; i <= b; ++i) {
         int j = b;
         int z = i + j - 1;
         int f;
         if (z <= c) f = j + c - z;
         else f = j;
         int s = i + f - 1;
         int minn = max(0LL, min(c - f + 1, d - s + 1));
         ans += max(0LL, sum(s - c + 1, s - c + minn));
         ans += (d - c + 1) * ((c - f + 1) - minn);
     }
     cout << ans;
}