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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
const ll INF18 = 8.01e18;
typedef vector<int> vi;

struct pt {
    ll x, y;
    pt () { }
    pt (ll xx, ll yy): x(xx), y(yy) {}
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    pt operator * (ll k) {
        return pt(x * k, y * k);
    }
    pt operator / (ll k) {
        return pt(x / k, y / k);
    }
    ll operator * (pt A) {
        return x * A.y - y * A.x;
    }
    ll operator % (pt A) {
        return x * A.x + y * A.y;
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    pt rotate() {
        return pt(-y, x);
    }
};

struct Event {
    ll type, t, y, cof, id; 
};

int sign(double tmp) {
    if (tmp < 0) return -1;
    if (tmp > 0) return 1;
    assert(false);
}


ll safeScal(pt v, pt u) {
    double tmp = v.x * 1.0 * u.x + v.y * 1.0 * u.y;
    if (abs(tmp) > INF18) {
        return INF18 * sign(tmp);
    }
    return v % u;
}

struct Fen {
    vector<ll> data;
    int nn;
    void init(int n) {
        nn = n;
        data.resize(n + 1);
    }
    void add(int pos, int val) {
        assert(pos < nn);
        for (; pos < nn; pos |= (pos + 1))
            data[pos + 1] += val;
    }

    ll get(int pos) {
        ll sum = 0;
        for (; pos > 0; pos &= (pos - 1)) 
            sum += data[pos];
        return sum;
    }
};

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int k, n, q;
    scanf("%d%d%d", &k, &n, &q);
    vector<pt> dir(k);
    vector<pt> contur;
    forn(i, k) {
        dir[i].read();
        contur.pb(dir[i] * 2); 
        contur.pb(dir[i] * -2); 
    }
    auto getPart = [](pt A) {
        return A.x < 0 || (A.x == 0 && A.y < 0);
    };

    sort(all(contur), [&](pt A, pt B) {
                bool partA = getPart(A);
                bool partB = getPart(B);
                if (partA != partB) {
                    return partA < partB;
                }
                return A * B > 0;
            });

    pt cur(0, 0);
    vector<pt> shape;
    for (auto v: contur) {
        shape.pb(cur);
        cur = cur + v;
    }
    assert(k * 2 == sz(shape));
    pt shift = shape[k] / 2;
    for (auto& A: shape) {
        A = A - shift;
    } 
    //for (auto A: shape) { db2(A.x, A.y); }

    //vector<pt> fact(n);
    //vector<ll> factCost(n);
    vector<Event> event;
    
    vector<pt> query(q);
    vector<ll> answer(q);
    
    //ll type, t, y, cof, id; 


    vector<pt> nr;
    forn(i, k) {
        if (i != k - 1) {
            assert(contur[i].x != 0);
        }         
        if (contur[i].x != 0)
            nr.pb(contur[i].rotate());
    } 
    nr.pb(pt(0, 1));
    for (auto& A: nr) {
        ll d = __gcd(abs(A.x), abs(A.y));
        A.x /= d;
        A.y /= d;
    }


    //db(nr.size());


    forn(i, n) {
        int x, y, cost;
        scanf("%d%d%d", &x, &y, &cost);
        event.pb({-1, x, y, cost, -1}); 
    } 
    //for (auto A: nr) { db2(A.x, A.y); }

    bool hasVert = contur[k - 1].x == 0;



    vector<pt> C(q);
    vector<ll> tmr(q);
    forn(i, q) {
        //db(i);
        C[i].read();
        scanf("%lld", &tmr[i]);
        //for (int j = 0; j < k - hasVert; j++) {
    }
    
    auto _event = event;
    forn(j, sz(nr)) {
        vector<ll> val;
        event = _event;
        for (auto E: event) {
            ll curVal = pt(E.t, E.y) % nr[j];
            if (curVal != safeScal(pt(E.t, E.y), nr[j])) {
                while(true);
            }
            val.pb(curVal);
        }
        forn(i, q) {
            if (j < k - hasVert) {
                pt A = C[i] + shape[j] * tmr[i];
                pt B = C[i] + shape[j + 1] * tmr[i];
                ll valA = safeScal(nr[j], A);
                ll valB = safeScal(nr[j], B);
                assert(valA == valB);
                event.pb({j, A.x, valA, 1, i});
                event.pb({j, B.x, valA, -1, i});
            }

            if (j == k - hasVert) {
                pt A, B;
                if (hasVert) {
                    A = C[i] + shape[k - 1] * tmr[i];
                    B = C[i] + shape[k] * tmr[i];
                }
                else {
                    A = B = C[i] + shape[k] * tmr[i];
                }
                event.pb({sz(nr) - 1, B.x + 1, B.y + 1, 1, i});
                event.pb({sz(nr) - 1, B.x + 1, A.y, -1, i});
                event.pb({sz(nr) - 1, B.x, B.y + 1, -1, i});
                event.pb({sz(nr) - 1, B.x, A.y, 1, i});
            }

            if (j < k - hasVert) {
                pt A = C[i] + shape[j + k] * tmr[i];
                pt B = C[i] + shape[(j + 1 + k) % sz(shape)] * tmr[i];
                ll valA = safeScal(nr[j], A);
                ll valB = safeScal(nr[j], B);
                assert(valA == valB);
                event.pb({j, A.x, valA + 1, 1, i});
                event.pb({j, B.x, valA + 1, -1, i});
            }
        }    
        sort(all(event), [](Event A, Event B) {
                return A.t < B.t || (A.t == B.t && A.type > B.type);
                });
        //cerr << endl;
        //int F = nr.size(); // features size
        //for (auto& v: val) {
        Fen fen;
        //for (int i = 0; i < sz(val); i++) {
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        fen.init(val.size());
            //db(val[i].size());
        //}

        for (auto E: event) {
            if (E.type == -1) {
                //forn(i, F) {
                ll curVal = safeScal(pt(E.t, E.y), nr[j]);
                int pos = lower_bound(all(val), curVal) - val.begin();
                assert(val[pos] == curVal);
                fen.add(pos, E.cof);
                //}
            }
            else {
                int pos = lower_bound(all(val), E.y) - val.begin();
                //assert(val[i][pos] == E.y);
                answer[E.id] += E.cof * fen.get(pos);
            }
        }
    }

    for (auto x: answer) {
        printf("%lld\n", x);
    }
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}