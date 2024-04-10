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
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    multiset<ll> q;
    ll add = 0;
    for (int i = 0; i < n; i++) {
        q.insert(v[i] - add);
        add -= t[i];
        ll res = q.size() * 1ll *  t[i];
        for (; !q.empty() && *q.begin() + add < 0; ) {
            ll x = *q.begin();
            q.erase(q.begin());
            res -= (0 - (x + add));
        }
//        db2(i, add);
//        dbv(q);
        printf("%lld ", res);
    }
    puts("");











    return 0;
}