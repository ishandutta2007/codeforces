#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 321;
const int N = 1e6 + 10;
const int POW = 20;

int a[N], l[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int m;
    cin >> m;
    fr(i, m)
        cin >> l[i] >> r[i];
    ll sum = accumulate(a, a + n, 0ll);
    fr(i, m)
        if (l[i] >= sum) {
            cout << l[i];
            return 0;
        }
        else if (r[i] >= sum) {
            cout << sum;
            return 0;
        }
    cout << -1;
}