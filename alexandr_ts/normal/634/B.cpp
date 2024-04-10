#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, ll> pr;

const int N = 2e5 + 2;
const int INF = 2e9 + 10;
const int ALPH = 300;
const ll MOD = 1e9 + 7;
const ll P = 29;

int a[N], b[N];

ll rec(ll s, ll x) {
    if (s < 0 || x < 0)
        return 0;
    if (s == 0 && x == 0)
        return 1;
    if (s == 1 && x == 1)
        return 2;
    if ((s & 1ll) ^ (x & 1ll))
        return 0;
    if ((s & 1ll) && (x & 1ll))
        return 2ll * rec(s / 2, x / 2);
    if (!(s & 1ll) && !(x & 1ll))
        return rec(s / 2ll, x / 2ll) + rec(s / 2ll - 1, x / 2ll);
}


int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    ll s, x;
    cin >> s >> x;
//    string s1, x1;
//    while (s > 0) {
//        s1 += char('0' + s % 2);
//        s /= 2;
//    }
//    while (x > 0) {
//        x1 += char('0' + x % 2);
//        x /= 2;
//    }
//    //reverse(s1.begin(), s1.end());
//    //reverse(x1.begin(), x1.end());
//    if (x1.size() > s1.size()) {
//        cout << 0;
//        return 0;
//    }
//    while (x1.size() > s1.size())
//        x1 = x1 + '0';
    ll ans = rec(s, x);
    if (s == x)
        ans -= 2;
    cout << ans;

}