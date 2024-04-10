#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

pr l[N], r[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > a;
    a.resize(n);
    fr(i, n)
        a[i].resize(m);
    fr(i, max(n, m))
        l[i] = r[i] = mp(0, 0);
    fr(i, k) {
        int typ, pos, x;
        cin >> typ >> pos >> x;
        if (typ == 1) {
            l[pos - 1] = mp(i + 1, x);
        }
        if (typ == 2) {
            r[pos - 1] = mp(i + 1, x);
        }
    }
    fr(i, n) {
        fr(j, m)
            if (l[i].first > r[j].first)
                cout << l[i].second << " ";
            else
                cout << r[j].second << " ";
        cout << endl;
    }

}