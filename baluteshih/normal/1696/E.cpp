#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MOD = 1e9 + 7;
int arr[200005], J[400005], invJ[400005];

int pw(int a, int n) {
    int rt = 1;
    for (; n; n >>= 1, a = (ll)a * a % MOD)
        if (n & 1)
            rt = (ll)rt * a % MOD;
    return rt;
}

int C(int n, int m) {
    if (n < m) return 0;
    return (ll)J[n] * invJ[m] % MOD * invJ[n - m] % MOD;
}

void add(int &x, int val) {
    x += val;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    const int MAXC = 400000;
    int n;
    cin >> n;
    J[0] = 1;
    for (int i = 1; i <= MAXC; ++i)
        J[i] = (ll)J[i - 1] * i % MOD;
    invJ[MAXC] = pw(J[MAXC], MOD - 2);
    for (int i = MAXC - 1; i >= 0; --i)
        invJ[i] = (ll)invJ[i + 1] * (i + 1) % MOD;
    int ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
        cin >> arr[i];
        add(ans, C(arr[i] + i - 1, i));
    }
    cout << ans << "\n";
}