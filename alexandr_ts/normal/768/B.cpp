#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-10;

ll n, l, r;

string ans;

ll cnt(ll n) {
    if (n == 1) return 1;
    return 1 + 2 * cnt(n / 2);
}

void rec(ll v, ll tl, ll tr) {
    if (tl > tr) return;
    //cout << v << " " << tl << " " << tr << endl;
    ll len = (tr - tl) / 2;
    if (tl > r || tr < l) return;
    if (tl + len - 1 >= l)
        rec(v / 2, tl, tl + len - 1);
    if (l <= tl + len && tl + len <= r)
        ans += ('0' + v % 2);
    if (tl + len + 1 <= r)
        rec(v / 2, tl + len + 1, tr);

}

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> l >> r;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    //cout << cnt(n) << endl;
    rec(n, 1, cnt(n));
    int answ = 0;
    fr(i, ans.size())
        if (ans[i] == '1')
            answ++;
    cout << answ;
}