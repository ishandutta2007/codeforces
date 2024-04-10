#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

ll a[N], b[N];
ll pref[N];

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < q; i++)
        scanf("%I64d", &b[i]);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    ll cur = 0;
    for (int i = 0; i < q; i++) {
        cur += b[i];
        if (cur >= pref[n]) {
            cur = 0;
            cout << n << "\n";
        }
        else {
            int pos = upper_bound(pref, pref + n + 1, cur) - pref;
            cout << n - pos + 1 << "\n";
        }
    }

}

int main() {
    //freopen("a.in", "r", stdin);
    solve();
}