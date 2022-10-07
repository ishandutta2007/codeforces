#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;


struct pt {
    ll x, y;
    pt () {}
    pt (ll xx, ll yy): x(xx), y(yy) {}
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    ll operator * (pt A) {
        return x * A.y - y * A.x;
    }
    ll operator % (pt A) {
        return x * A.x + y * A.y;
    }
    pt operator * (ll k) {
        return pt(x * k, y * k);
    }
    pt operator / (ll k) {
        assert(x % k == 0 && y % k == 0);
        return pt(x / k, y / k);
    }
    pt ort() {
        return pt(-y, x);
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    bool zero() {
        return x == 0 && y == 0;
    }
    bool operator < (pt A) const {
        return x < A.x || (x == A.x && y < A.y);
    }
};

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    pt sum(0, 0);
    for (int i = 0; i < n; i++) {
        p[i].read();
        p[i] = p[i] * 2;
        sum = sum + p[i];
        p[i] = p[i] * n;
    }
    set<pt> f;
    f.insert(all(p));
    pt G;
    bool good = 1;
    for (int i = 0; i < n; i++) {
        pt cand = sum + sum - p[i];
        if (f.count(cand) == 0) {
            G = p[i];
            good = 0;
            break;
        }
    }
    if (good) {
        puts("-1");
        return 0;
    }
    //db2(G.x, G.y);

    pt A = sum;
    set<pt> q;
    //db2(sum.x, sum.y);
    //for (auto U: p) {
        //db2(U.x, U.y);
    //}
    for (int i = 0; i < n; i++) {
        pt B = (G + p[i]) / 2;
        pt v = (A - B).ort();
        //db2(v.x, v.y);
        if (!v.zero()) {
            vector<ll> proj;
            for (int j = 0; j < n; j++) {
                proj.pb(p[j] % v);
            }
            sort(all(proj));
            //dbv(proj);
            bool ok = 1;
            ll mid = (proj[0] + proj.back());
            for (int j = 0; j < n; j++) {
                ok &= (proj[j] + proj[n - 1 - j] == mid);
            }
            if (ok) {
                ll tmp = __gcd(abs(v.x), abs(v.y));
                v = v / tmp;
                if (v.x < 0 || (v.x == 0 && v.y < 0)) {
                    v = v * -1;
                }
                q.insert(v);
            }
        }
    }
     

    cout << q.size() << endl;

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}