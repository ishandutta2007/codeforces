#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2 * 1e9 + 1;
const ld EPS = 1e-9;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, l;
    cin >> n >> l;
    fr(i, n)
        cin >> a[i];
    //a[n] = 0, a[n + 1] = l;
    sort(a, a + n);
    ll maxx = -1;
    fr(i, n - 1)
        maxx = max(a[i + 1] - a[i], maxx);
    maxx = max(max(maxx, 2 * a[0]), 2 * l - 2 * a[n - 1]);
    double ans = (double)maxx / 2.0;
    printf("%.10lf", (double)ans);


}