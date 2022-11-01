#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e14 + 10;
const ld EPS = 1e-10;

ll a[N];
ll b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll ts, tf, t1;
    cin >> ts >> tf >> t1;
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        if (i)
            b[i] = max(ts, max(a[i], b[i - 1] + 1));
        else
            b[i] = max(ts, a[i]);
        b[i] += (t1 - 1);
    }
    //fr(i, n)
   //    cout << b[i] << " ";cout << endl;
    ll anst = INF, ans = 0;
    fr(i, n)
        if (i == n - 1 || a[i] != a[i + 1]) {
            if (i < n - 1) {
                ll t = a[i + 1] - 1;
                if (b[i] + 1 - t < anst && t <= tf - t1)
                    anst = b[i] + 1 - t, ans = t;
            }
            else {
                ll t = b[i] + 1;
                if (t <= tf - t1)
                    anst = 0, ans = t;
            }
        }
    if (n && ts - a[0] + 1 < anst && a[0] - 1 <= tf - t1)
        anst = ts - a[0] + 1, ans = a[0] - 1;
    if (n && a[0] > ts)
        anst = 0, ans = ts;
    if (!n)
        anst = 0, ans = ts;
    //cout << anst << endl;
    cout << ans;
}