#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int te; cin >> te;
    while(te--) {
        ll n, m, i1, j1, i2, j2;
        cin >> n >> m >> i1 >> j1 >> i2 >> j2;
        ll l = min(j1 - 1, j2 - 1);
        ll r = min(m - j1, m - j2);
        ll u = min(i1 - 1, i2 - 1);
        ll d = min(n - i1, n - i2);

        ll j11 = j1 - l;
        ll j12 = j1 + r;
        ll i11 = i1 - u;
        ll i12 = i1 + d;

        ll j21 = j2 - l;
        ll j22 = j2 + r;
        ll i21 = i2 - u;
        ll i22 = i2 + d;

        ll j31 = max(j11, j21);
        ll j32 = min(j12, j22);
        ll i31 = max(i11, i21);
        ll i32 = min(i12, i22);

        ll s = 0;
        if(j31 <= j32 && i31 <= i32)
            s = (j32 - j31 + 1) * (i32 - i31 + 1);

        ll s1 = (j12 - j11 + 1) * (i12 - i11 + 1);
        ll s2 = (j22 - j21 + 1) * (i22 - i21 + 1);

        cout << n * m - s1 - s2 + s << '\n';
    }
}