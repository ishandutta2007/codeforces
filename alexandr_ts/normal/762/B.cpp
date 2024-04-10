#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;



int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int cnt;
    cin >> cnt;
    vector <int> a, b;
    fr(i, cnt) {
        int x;
        string typ;
        cin >> x >> typ;
        if (typ == "USB")
            a.pb(x);
        else
            b.pb(x);
    }

    ll anscnt = 0, ans = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int c1 = 0, c2 = 0;
    for (int i = 0; i < min(n, (int)a.size()); i++)
        anscnt++, ans += a[i], c1++;
    for (int i = 0; i < min(m, (int)b.size()); i++)
        anscnt++, ans += b[i], c2++;
    vector <int> c((int)a.size() + (int)b.size() - c1 - c2);
    merge(a.begin() + c1, a.end(), b.begin() + c2, b.end(), c.begin());
    sort(c.begin(), c.end());
    for (int i = 0; i < min(k, (int)c.size()); i++)
        anscnt++, ans += c[i];
    cout << anscnt << " " << ans;
}