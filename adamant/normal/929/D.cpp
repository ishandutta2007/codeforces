#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

ll mod = 1000000007;

int g[100100];
int k[100100];
int w[100100];
int mn[20][100100];
int mx[20][100100];
int M[100100];

int main() {
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    forn (i, n - 1) {
        cin >> g[i];
    }
    forn (i, n) {
        cin >> k[i];
    }
    if (a > b) {
        forn (i, n / 2) {
            swap(g[i], g[n - 2 - i]);
            swap(k[i], k[n - 1 - i]);
        }
        a = n - 1 - a;
        b = n - 1 - b;
    }
    n = b + 1;
/*    cerr << a << " " << b << endl;
    forn (i, n - 1) {
        cerr << g[i] << " ";
    }
    cerr << endl;
    forn (i, n) {
        cerr << k[i] << " ";
    }
    cerr << endl;
*/    forn (i, 100100) {
        M[i] = 1000000000;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i < a) {
            w[i] = M[g[i]];
        }
        M[k[i]] = i;
    }
    forn (i, 100100) {
        M[i] = -1000000000;
    }
    forn (i, n - 1) {
        M[k[i]] = i;
        if (i >= a) {
            w[i] = M[g[i]];
        }
    }
    for (int i = a - 2; i >= 0; --i) {
        w[i] = max(w[i], w[i + 1]);
    }
    for (int i = a + 1; i < n - 1; ++i) {
        w[i] = min(w[i], w[i - 1]);
    }
    forn (i, n - 1) {
//        cerr << w[i] << " ";
    }
    ll ans = 0;
    int cur = b;
    int l = -1, r = b;
    while (1) {
//        cerr << cur << " " << l << " " << r << endl;
        if (cur == a) {
            cout << ans << endl;
            return 0;
        }
        if (cur == r) {
            int nl = w[r - 1];
            if (nl <= l) {
                cout << -1 << endl;
                return 0;
            }
            l = nl;
            ans += cur - l;
            cur = l;
        } else {
            int nr = w[l];
            if (nr >= r) {
                cout << -1 << endl;
                return 0;
            }
            r = nr;
            ans += r - cur;
            cur = r;
        }
    }
    return 0;
}