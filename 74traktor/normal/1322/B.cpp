#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 4e5 + 5;
int a[maxn], b[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll ans = 0;
    int out = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= n; ++j) b[j] = (a[j] % (1 << (i + 1)));
        sort(b + 1, b + n + 1);
        ans = 0;
        for (int j = 1; j <= n; ++j) {
            int lef = 0, righ = n + 1;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                if (b[mid] + b[j] >= (1 << (i + 1)) + (1 << i)) righ = mid;
                else lef = mid;
            }
            ans += (ll)(n - righ + 1);
            lef = 0, righ = n + 1;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                if (b[mid] + b[j] < (1 << i)) lef = mid;
                else righ = mid;
            }
            ans -= (ll)lef;
            lef = 0, righ = n + 1;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                if (b[mid] + b[j] < (1 << (i + 1))) lef = mid;
                else righ = mid;
            }
            ans += (ll)lef;
        }
        for (int j = 1; j <= n; ++j) {
            if (((2 * a[j])&(1 << i)) > 0) ans--;
        }
        if (ans % 4 != 0) out += (1 << i);
    }
    cout << out << '\n';
    return 0;
}