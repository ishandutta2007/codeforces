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



int main() {
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
#endif
    int q;
    scanf("%d", &q);
    auto getLevel = [](ll x) {
        int res = 0;
        for (; x > 1; x /= 2, res++); 
        return res;
    };
    const int LOG = 61;
    vector<ll> shift(LOG); 
    for (int tt = 0; tt < q; tt++) {
        int type;
        ll x;
        scanf("%d%lld", &type, &x); 
        //db(type);
        ll h = getLevel(x);
        if (type == 1 || type == 2) {
            ll k;
            scanf("%lld", &k); 
            if (type == 1) {
                shift[h] = (shift[h] + k) % pw(h);
            }
            else {
                for (int i = h; i < LOG; i++, k *= 2) {
                    shift[i] = (shift[i] + k) % pw(i);
                }
            }
        }
        else {
            for (int i = h; i >= 0; i--) {
                printf("%lld ", x);
                if (i == 0) {
                    break;
                }
                ll realPos = (x - pw(i) + shift[i] + pw(i)) % pw(i);
                //db(realPos);
                ll up = (realPos + pw(i)) / 2;
                //db(up);
                x = (up - pw(i - 1) - shift[i - 1] + pw(i - 1)) % pw(i - 1) + pw(i - 1);
            }
            puts("");
        }

    }





    return 0;
}