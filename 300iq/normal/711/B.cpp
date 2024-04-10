#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 500 + 7;
ll a[MAXN][MAXN];
ll sum[MAXN];

int main() {
    set <ll> p;
    int n;
    cin >> n;
    int pi = 0, pj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                pi = i;
                pj = j;
            }
            sum[i] += a[i][j];
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll ans;
    if (pi == 0) {
        ans = sum[1] - sum[0];
    } else {
        ans = sum[pi - 1] - sum[pi];
    }
    if (ans <= 0) {
        cout << -1 << endl;
        return 0;
    }
    if (pi != 0) sum[pi] = sum[pi - 1];
    else sum[0] = sum[1];
    a[pi][pj] = ans;
    for (int i = 1; i < n; i++) {
        if (sum[i] != sum[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    p.insert(sum[0]);
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[i] += a[j][i];
        }
    }
    for (int i = 1; i < n; i++) {
        if (sum[i] != sum[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    p.insert(sum[0]);
    ll s1 = 0;
    for (int i = 0; i < n; i++) {
        s1 += a[i][i];
    }
    ll s2 = 0;
    for (int i = 0; i < n; i++) {
        s2 += a[i][n - 1 - i];
    }
    p.insert(s1);
    if (s1 != s2 || p.size() != 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}