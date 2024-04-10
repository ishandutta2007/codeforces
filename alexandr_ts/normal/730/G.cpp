#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e5 + 10;

ll s[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> s[i] >> d[i];

    vector <pair <ll, ll> > a;
    fr(i, n) {
        ll l = s[i], r = s[i] + d[i] - 1;
        bool ok = true;
        for (auto t: a)
            if (max(t.first, l) <= min(t.second, r))
                ok = false;
        if (ok) {
            a.pb(mp(l, r));
            sort(a.begin(), a.end());
            cout << l << " " << r << endl;
        }
        else {
            if (a[0].first > d[i]) {
                a.pb(mp(1, d[i]));
                sort(a.begin(), a.end());
                cout << 1 << " " << d[i] << endl;
            }
            else {
                fr(j, a.size())
                    if (j == (int)a.size() - 1 || a[j + 1].first - a[j].second >= d[i] + 1) {
                        a.pb(mp(a[j].second + 1, a[j].second + d[i]));
                        cout << a[j].second + 1 << " " << a[j].second + d[i] << endl;
                        sort(a.begin(), a.end());
                        break;
                    }
            }
        }
    }


}