#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;

int a[N];
bool b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    ll sums = 0;
    fr(i, m) {
        int x;
        cin >> x;
        b[--x] = true;
        sums += a[x];
    }
    ll ans = 0;
    fr(i, n)
        if (!b[i] && !b[(i + 1) % n])
            ans += a[i] * a[(i + 1) % n];
    //cout << ans << endl;
    ll sum = accumulate(a, a + n, 0ll);
    ll sum2 = 0;
    fr(i, n)
        if (b[i]) {
            ans += (sum - a[i]) * a[i];
            sum2 += (sums - a[i]) * a[i];
        }
    cout << ans - sum2 / 2;

}