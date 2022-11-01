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
const int M = 1e3 + 3;
const int N = 1e6 + 3;

ll a[N], suf[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];
    d[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        d[i] = max(d[i + 1], suf[i] - d[i + 1]);
    }
    cout << suf[0] - d[0] << " " << d[0];
}