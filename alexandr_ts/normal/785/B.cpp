#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2001;
const ld EPS = 1e-8;
const ll INF = 2e9 + 10;

vector <int> a, b, c, d;

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        int l, r;
        cin >> l >> r;
        a.pb(l);
        b.pb(r);
    }
    int m;
    cin >> m;
    fr(i, m) {
        int l, r;
        cin >> l >> r;
        c.pb(l);
        d.pb(r);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    cout << max(0, max(a.back() - d[0], c.back() - b[0]));
}