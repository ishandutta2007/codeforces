#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-15;
const ld PI = acos(-1);

const int M = 1e3 + 10;
const int N = 1e6 + 10;

pair <ll, ll> a[N];
ll b[N];

bool cmp(pair <ll, ll> a, pair <ll, ll> b) {
    return a.second < b.second;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    fr(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    fr(i, n)
        b[i] = (a[i].first + 1) / 2;
    ll curs = accumulate(b, b + n, 0ll);
    if (curs > w) {
        cout << -1;
        return 0;
    }
    ll lft = w - curs;
    for (int i = n - 1; i >= 0; i--) {
        ll add = min(lft, a[i].first - b[i]);
        b[i] += add;
        lft -= add;
    }

    if (lft) {
        cout << -1;
        return 0;
    }

    fr(i, n)
        a[i].first = b[i];
    sort(a, a + n, cmp);


    fr(i, n)
        cout << a[i].first << " ";


}