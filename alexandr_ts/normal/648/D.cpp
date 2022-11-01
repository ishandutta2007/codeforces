#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 5e5 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

ll u[N], t[N];

pair <ll, ll> a[N], c[N];

//struct tn1 {
//    ll l, r, num;
//    tn() {}
//    tn(ll l, ll r, ll num): l(l), r(r), num(num) {}
//    bool operator < (const tn1 a) const {
//        return l < a.l || l == a.l && r < a.r;
//    }
//} l1[N];
//
//struct tn2 {
//    ll l, r, num;
//    tn() {}
//    tn(ll l, ll r, ll num): l(l), r(r), num(num) {}
//    bool operator < (const tn1 a) const {
//        return r < a.r || r == a.r && l < a.l;
//    }
//} r1[N];

vector <pair <ll, ll> >l1, r1;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    fr(i, n) {
        ll tmp;
        cin >> tmp;
        a[i] = mp(tmp, INF);
    }
    sort(a, a + n);
    fr(i, m) {
        cin >> u[i] >> t[i];
        l1.pb(mp(u[i] - t[i], i));
        r1.pb(mp(u[i] + t[i], i));
    }
    sort(l1.begin(), l1.end());
    //sort(r1.begin(), r1.end());
    merge(a, a + n, l1.begin(), l1.end(), c);
    //fr(i, n + m)
      //  cout << c[i].first << \" " << c[i].second << endl;
    set <pair <ll, ll> > r2;
    ll ans = 0;
    fr(i, n + m)
        if (c[i].second == INF) {
            while (r2.size() && r2.begin()->first < c[i].first)
                r2.erase(r2.begin());
            if (r2.size() == 0)
                continue;
            ans++;
            r2.erase(r2.begin());
        }
        else {
            r2.insert(mp(r1[c[i].second].first, c[i].second));
        }
    cout << ans;
}