#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

struct tmp {
    ll x, pos;
} a[N], d[N];

bool cmp1(tmp a, tmp b) {
    return a.x > b.x;
}

bool cmp2(tmp a, tmp b) {
    return a.pos < b.pos;
}

ll b[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    cin >> n >> m;
    fr(i, n) {
        cin >> a[i].x;
        a[i].pos = i;
    }
    fr(i, m) {
        ll t1, t2;
        cin >> t1 >> t2;
        b[t1 - 1]++, b[t2]--;
    }
    c[0] = b[0];
    frab(i, 1, n)
        c[i] = c[i - 1] + b[i];
    fr(i, n)
        d[i].x = c[i], d[i].pos = i;
    sort(d, d + n, cmp1);
    sort(a, a + n, cmp1);
    ll sum = 0;
    fr(i, n)
        sum += a[i].x * d[i].x;
    cout << sum;
}