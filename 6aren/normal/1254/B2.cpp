#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define int long long

const int N = 1000005;

vi v;
int sum, n, a[N], b[N];

int calc(int p) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        int u = (b[i] + p) % p;
        if (u <= p - u) {
            res += u;
            b[i + 1] += u;
        } else {
            res += p - u;
            b[i + 1] -= (p - u);
        }
    }
    return res;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            v.pb(i);
            while (sum % i == 0) {
                sum /= i;
            }
        }
    }
    if (sum > 1) v.pb(sum);
    int ans = 1e18;
    for (auto u : v) {
        ans = min(ans, calc(u));
    }
    if (ans == 1e18) cout << -1;
    else cout << ans;
    return 0;
}