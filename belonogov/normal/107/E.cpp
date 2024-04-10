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

bool eq(dbl A, dbl B) {
    return abs(A - B) < 1e-9;
}

bool ls(dbl A, dbl B) {
    return A < B && !eq(A, B);
}

bool le(dbl A, dbl B) {
    return A < B || eq(A, B);
}

struct pt {
    ll x, y;

    pt() {}

    pt(ll xx, ll yy) : x(xx), y(yy) {}

    pt operator+(pt A) {
        return pt(x + A.x, y + A.y);
    }

    pt operator-(pt A) {
        return pt(x - A.x, y - A.y);
    }

    pt operator*(ll k) {
        return pt(x * k, y * k);
    }

    pt operator/(ll k) {
        assert(x % k == 0 && y % k == 0);
        return pt(x / k, y / k);
    }

    ll operator*(pt A) {
        return x * A.y - y * A.x;
    }

    ll operator%(pt A) {
        return x * A.x + y * A.y;
    }

    bool operator==(pt A) {
        return x == A.x && y == A.y;
    }

    bool operator!=(pt A) {
        return x != A.x && y != A.y;
    }

    pt rotate() {
        return pt(-y, x);
    }

    ll len2() {
        return x * x + y * y;
    }

    dbl len() {
        return sqrt(x * x + y * y);
    }

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

struct Line {
    pt O, v;

    Line() {}

    Line(pt A, pt B) : O(A) {
        v = (B - A);
        ll d = __gcd(abs(v.x), abs(v.y));
        v = v / d;
        assert(v.x != 0);
        if (v.x < 0) {
            v = v * -1;
        }
//        if (v.y < 0 || (v.y == 0 && v.x < 0)) {
//            v = v * -1;
//        }
    }
};

ll sign(ll x) {
    if (x == 0) return 0;
    if (x < 0) return -1;
    return 1;
}


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<vector<pt>> p(n);
    ll sumArea = 0;
    for (int i = 0; i < n; i++) {
        p[i].resize(4);
        for (int j = 0; j < 4; j++) {
            p[i][j].read();
        }
        ll area = 0;
        for (int j = 0; j < 4; j++) {
            area += p[i][j] * p[i][(j + 1) % 4];
        }
        if (area < 0) {
            reverse(all(p[i]));
            area *= -1;
        }
        sumArea += area;
    }
    vector<Line> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            pt A = p[i][j];
            pt B = p[i][(j + 1) % 4];
            if (eq(A.x, B.x)) continue;
            l.pb(Line(A, B));
        }
    }

    sort(all(l), [](Line A, Line B) {
        if (A.v * B.v != 0) {
            return A.v * B.v > 0;
        }
        assert(A.v == B.v);
        pt u = A.v.rotate();
        return A.O % u < B.O % u;
    });


    l.resize(unique(all(l), [](Line A, Line B) {
        return (A.v * B.v == 0 && (A.O - B.O) % A.v.rotate() == 0);
    }) - l.begin());

    struct Event {
        dbl tmr;
        int type;
    };

    dbl unionArea = 0;
    for (auto L: l) {
        for (int ss = -1; ss <= 1; ss += 2) {
//            cerr << endl;
//            db(ss);
//            db2(L.O.x, L.O.y);
//            db2(L.v.x, L.v.y);
            vector<Event> event;
            for (int i = 0; i < n; i++) {
                vector<dbl> tmr;
                for (int j = 0; j < 4; j++) {
                    pt A = p[i][j];
                    pt B = p[i][(j + 1) % 4];
                    pt C = p[i][(j + 3) % 4];
                    if ((A - L.O) * L.v == 0 && (B - L.O) * L.v == 0) {
                        dbl tA = (A - L.O) % L.v * 1.0 / L.v.len();
                        dbl tB = (B - L.O) % L.v * 1.0 / L.v.len();
                        if ((tB - tA) * ss < 0) {
                            event.pb({min(tB, tA), 2});
                            event.pb({max(tA, tB), -2});
                        }
                    }
                    if ((A - L.O) * L.v == 0 && sign(L.v * (C - L.O)) * sign(L.v * (B - L.O)) == -1) {
                        tmr.pb((A - L.O) % L.v * 1.0 / L.v.len());
                    }
                    if (sign(L.v * (A - L.O)) * sign(L.v * (B - L.O)) == -1) {
                        if (L.v * (A - L.O) < 0) {
                            swap(A, B);
                        }
                        ll pa = (A - L.O) % L.v;
                        ll pb = (B - L.O) % L.v;
                        ll ca = (L.v * (A - L.O));
                        ll cb = ((B - L.O) * L.v);
                        dbl res = (pa * cb + pb * ca) * 1.0 / (ca + cb);
                        tmr.pb(res);
                    }
                }
                assert(tmr.size() == 0 || tmr.size() == 2);
                if (tmr.size() == 2) {
                    sort(all(tmr));
                    event.pb({tmr[0] / L.v.len(), 1});
                    event.pb({tmr[1] / L.v.len(), -1});
                }
            }
            sort(all(event), [](Event A, Event B) {
                return A.tmr < B.tmr;
            });
//            db("_____________________");
//            for (auto A: event) {
//                db2(A.tmr, A.type);
//            }
            int bal1 = 0;
            int bal2 = 0;
            dbl prev = 0;
            for (auto E: event) {
                bool good = bal2 > 0 && bal1 == 0;
                if (E.type == 1) bal1++;
                if (E.type == 2) bal2++;
                if (E.type == -1) bal1--;
                if (E.type == -2) bal2--;

                bool good2 = bal2 > 0 && bal1 == 0;
//                db2(good, good2);
                if (good && !good2) {
                    dbl dx = L.v.x * (E.tmr - prev) / L.v.len();
                    dbl midY = L.O.y + L.v.y * (E.tmr + prev) / 2 / L.v.len();
//                    db2(dx, midY);
//                    db3(dx * midY * ss, dx, midY);
                    unionArea += dx * midY * ss;
                }
                if (!good && good2) {
                    prev = E.tmr;
//                    db2("set prev", prev);
                }
            }
        }
//        db(uninoArea);
//        exit(0);
    }

//    db2(sumArea, unionArea);
    printf("%.17f\n", sumArea / 2.0 / unionArea);



    return 0;
}