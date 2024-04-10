#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1073741824;
const ll INF = 2e9;
const ll N = 3e5 + 2;
const ll M = 1e6;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

struct city {
    ll x, y, cnt;
} a[N];

ll n, s;


bool cmp(city a, city b) {
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y ||
        a.x * a.x + a.y * a.y == b.x * b.x + b.y * b.y && a.cnt > b.cnt;
}

bool check(ld dist, ll cnt) {
    ll ans = 0;
    fr(i, n)
        if (hypot(a[i].x, a[i].y) < dist)
            ans += a[i].cnt;
        else
            break;
    return ans >= cnt;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(8);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    fr(i, n)
        cin >> a[i].x >> a[i].y >> a[i].cnt;
    sort(a, a + n, cmp);

    ld l = 0, r = INF;
    if (!check(r, M - s)) {
        cout << -1;
        return 0;
    }

    fr(i, 80) {
        ld m = (l + r) / 2.;
        if (check(m, M - s))
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(12) << l;

}