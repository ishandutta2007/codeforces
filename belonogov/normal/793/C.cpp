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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;

struct Fraq {
    ll p, q;
    Fraq(ll pp, ll qq): p(pp), q(qq) {
        if (q < 0) {
            q *= -1;
            p *= -1;
        }
    }
    bool operator < (Fraq A) const {
        //db2(p * A.q, A.p * q);
        //int res = 
        //db(res);
        //return res;
            return p * A.q < A.p * q;
    }
    bool operator == (Fraq A) const {
        return p * A.q == A.p * q;
    }
};

struct pt {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
};


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    pt A, B;
    A.read();
    B.read();
    vector<pt> p(n);
    vector<pt> v(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
        v[i].read();
    }
    Fraq l(0, 1); 
    Fraq r(INF, 1);

    for (int tt = 0; tt < 2; tt++) {
        for (int i = 0; i < n; i++) {
            if (v[i].x != 0) {
                Fraq t1(A.x - p[i].x, v[i].x);
                Fraq t2(B.x - p[i].x, v[i].x);
                if (t2 < t1) {
                    swap(t1, t2);
                }
                l = max(l, t1);
                r = min(r, t2);
            }
            else {
                if (p[i].x <= A.x || B.x <= p[i].x) {
                    puts("-1");
                    return 0;
                }
            }
        }
        swap(A.x, A.y);
        swap(B.x, B.y);
        for (int i = 0; i < n; i++) {
            swap(p[i].x, p[i].y);
            swap(v[i].x, v[i].y);
        }
    }

    //db2(l.p, l.q);
    //db2(r.p, r.q);
    if (l < r) {
        printf("%.17f\n", l.p * 1.0 / l.q);
    }
    else {
        puts("-1");
    }

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}