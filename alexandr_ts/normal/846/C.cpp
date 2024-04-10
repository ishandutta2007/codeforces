#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1003;
const int N = 1e6 + 10;

ll a[N];
ll pr[N];
ll mx[N];
int p1[N];

ll sum(int l, int r) {
    return pr[r] - pr[l];
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    pr[0] = 0;
    frab(i, 1, n + 1)
        pr[i] = pr[i - 1] + a[i - 1];
    mx[0] = 0;
    frab(i, 1, n + 1) {
        if (mx[i - 1] > pr[i])
            p1[i] = p1[i - 1];
        else
            p1[i] = i;
        mx[i] = max(mx[i - 1], pr[i]);
    }

    ll ans = -INF * n;
    vector <int> ansv = {-1, -1, -1};
    for (int i1 = 0; i1 <= n; i1++)
        for (int i2 = i1; i2 <= n; i2++) {
            //cout << i1 << " " << i2 << " " << sum(i1, i2) << ' ' << sum(i2, n) << endl;
            ll cur = sum(i1, i2) - sum(i2, n) - sum(0, i1) + 2 * mx[i1];
            if (ans < cur)
                ans = cur, ansv = {p1[i1], i1, i2};
        }
    fr(i, 3)
        cout << ansv[i] << " ";
    //cout << endl << ans;
}