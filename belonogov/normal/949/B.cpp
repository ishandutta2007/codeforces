#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

ll d3 = 0;

ll mxPw(ll x);


ll rec(ll n, ll k) {
    ll dd = mxPw(n);
    //assert(dd < )
    ll good = n - dd;
    assert(good > 0);
//    db3(n, good, dd);
    if (k < good * 2) {
        if (k % 2 == 0) {
            return k / 2;
        }
        else {
            ll megaId = good - k / 2 - 1;
            ll f = n - good;
            return rec(n - good, f - 1 - megaId) + good;
        }
    }
    else {
        return rec(n - good, k - good * 2) + good;
    }
}

ll n;

ll mxPw(ll x) {
//    db(x);
    if ((x & (x - 1)) == 0) return x / 2;
    assert(x == n);
    return pw(d3);
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int q;
    cin >> n >> q;
    for (; n > pw(d3 + 1); d3++);



    for (int tt = 0; tt < q; tt++) {
        ll x;
        scanf("%lld", &x);
        printf("%lld\n", rec(n, x - 1) + 1);
    }





    return 0;
}