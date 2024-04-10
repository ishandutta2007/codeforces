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

struct pt {
    ll x, y;
    pt() {}
    pt(ll xx, ll yy): x(xx), y(yy) {}
    pt operator + (pt A) const {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) const {
        return pt(x - A.x, y - A.y);
    }
    pt operator * (ll k) const {
        return pt(x * k, y * k);
    }
    pt operator / (ll k) const {
        assert(x % k == 0 && y % k == 0);
        return pt(x / k, y / k);
    }
    ll operator * (pt A) const {
        return x * A.y - y * A.x;
    }    
    ll operator % (pt A) {
        return x * A.x + y * A.y;
    }
    bool operator == (pt A) const {
        return x == A.x && y == A.y;
    }
    bool operator != (pt A) {
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

bool checkOrd(pt v, pt A, pt B) {
    bool partA = v * A < 0 || (v * A == 0 && v % A < 0);
    bool partB = v * B < 0 || (v * B == 0 && v % B < 0);
    if (partA != partB) {
        return partA < partB;
    }
    return A * B > 0;
}


int main() {
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
    int st, fn;
    scanf("%d%d", &st, &fn); st--; fn--;
   
    vector<vector<pair<int,dbl>>> e;
    vector<pair<dbl,int>> event;

    vector<dbl> pref;
    pref.pb(0);
    for (int i = 0; i < n; i++) {
        pref.pb(pref.back() + (p[i] - p[(i + 1) % n]).len());
    }

    e.resize(2);
    //db2(st, fn);
    event.pb({pref[st], 0});
    event.pb({pref[fn], 1});

    struct Event {
        int type;
        pt A, B;
        dbl la, lb;
    };

    vector<Event> ee;

    for (int i = 0; i < n; i++) {
        pt A = p[i];
        pt B = p[(i + 1) % n];
        if (A.x == B.x) continue;
        //cerr << endl; db2(A.x, A.y); db2(B.x, B.y); 
        dbl la = pref[i];
        dbl lb = pref[i + 1];
        if (A.x > B.x) {
            //swap(A.x, B.x);
            swap(A, B);
            swap(la, lb);
        } 
        //db2(B.x, B.y);
        ee.pb({1, A, B, la, lb});
        ee.pb({4, B, A, -1, -1});
    }


    for (int i = 0; i < n; i++) {
        pt A = p[(i - 1 + n) % n];
        pt B = p[i];
        pt C = p[(i + 1) % n];
        if (checkOrd(pt(0, 1), A - B, C - B)) {
            ee.pb({2, B, pt(-1, -1), pref[i], -1});
        }
        if (checkOrd(pt(0, -1), A - B, C - B)) {
            ee.pb({3, B, pt(-1, -1), pref[i], -1});
        }
    }


    sort(all(ee), [](Event E1, Event E2) {
            return E1.A.x < E2.A.x || (E1.A.x == E2.A.x && E1.type < E2.type);
            });
    struct Seg {
        pt A, B;
        dbl la, lb;
        pair<dbl,dbl> getProj(ll x) const { // p y
            assert(A.x <= x && x <= B.x);
            dbl y = (A.y * (B.x - x) + B.y * (x - A.x)) * 1.0 / (B.x - A.x);
            dbl p = (la * (B.x - x) + lb * (x - A.x)) * 1.0 / (B.x - A.x);
            return {p, y};            
        }
        bool operator < (Seg other) const {
            if (A.x == B.x) {
                return (other.A - other.B) * (A - other.B) > 0;
            }
            if (other.A.x == other.B.x) {
                return (other.A - B) * (A - B) > 0;
            }

            if (A.x < other.A.x) {
                if (other.A.x < B.x) {
                    return (other.A - B) * (A - B) > 0;
                } 
                assert(other.A.x == B.x);
                if (other.A.y != B.y) {
                    return B.y < other.A.y;
                }
                return true;
            }
            if (other.A.x < A.x) {
                if (A.x < other.B.x) {
                    return (other.A - other.B) * (A - other.B) > 0;
                }
                if (other.B.y != A.y) {
                    return A.y < other.B.y;
                }
                return false;
            }
            assert(other.A.x == A.x);
            if (other.A.y != A.y) {
                return A.y < other.A.y; 
            }
            assert(A == other.A);
            return (B - A) * (other.B - other.A) > 0;
        }
    };
    //db(ee.size());
    //for (auto E: ee) { cerr << E.type << " (" << E.A.x << ", " << E.A.y << "), ("<< E.B.x << ", " << E.B.y << ")" << endl; }


    set<Seg> q;
    for (auto E: ee) {
        //db("GO");
        if (E.type == 1) {
            assert(q.insert({E.A, E.B, E.la, E.lb}).S);
        }     
        else if (E.type == 4) {
            assert(q.erase({E.B, E.A, -1, -1}));
        }
        else if (E.type == 2) {
            auto it = q.upper_bound({E.A, E.A, -1, -1});
            assert(it != q.end());
            auto res = it->getProj(E.A.x);
            assert(E.A.y + 1e-9 < res.S);
            int vert1 = e.size();            
            int vert2 = e.size() + 1;
            //db2(vert1, vert2);
            e.emplace_back();
            e.emplace_back();
            event.pb({res.F, vert1});
            event.pb({E.la, vert2});
            //db(E.A.x); db3("jump1", res.S, E.A.y);
            e[vert1].pb({vert2, res.S - E.A.y});
        }
        else if (E.type == 3) {
            auto it = q.lower_bound({E.A, E.A, -1, -1});
            assert(it != q.begin());
            it--;
            auto res = it->getProj(E.A.x);
            assert(res.S + 1e-9 < E.A.y);
            int vert1 = e.size();            
            int vert2 = e.size() + 1;
            //db2(vert1, vert2);
            e.emplace_back();
            e.emplace_back();
            event.pb({E.la, vert1});
            event.pb({res.F, vert2});
            //db(E.A.x); //db3("jump2", res.S, E.A.y);
            e[vert1].pb({vert2, E.A.y - res.S});
        }
    }
    //for (auto x: event) { db2(x.F, x.S); }

    sort(all(event));
    //for (auto x: event) { db2(x.F, x.S); }

    for (int i = 0; i < sz(event); i++) {
        dbl d = event[(i + 1) % sz(event)].F - event[i].F;
        if (d < 0) {
            assert(d < 1e-9);
            d += pref.back();
        }
        //db(d);
        int v = event[(i + 1) % sz(event)].S;
        int u = event[i].S;
        e[v].pb({u, d});
        e[u].pb({v, d});
    }

    vector<dbl> dist(e.size(), INF);
    dist[0] = 0;
    set<pair<dbl,int>> w;
    w.insert({0, 0});

    /*for (int i = 0; i < sz(e); i++) {
        for (auto x: e[i]) {
            cerr << "(" << x.F << ", " << x.S << ") ";
        }
        cerr << endl;
    }*/

    while (!w.empty()) {
        int v = w.begin()->S;
        w.erase(w.begin());
        for (auto x: e[v]) {
            int u = x.F;
            if (dist[u] > dist[v] + x.S + 1e-9) {
                w.erase({dist[u], u});
                dist[u] = dist[v] + x.S;
                w.insert({dist[u], u});
            }
        }
    }
    //dbv(dist);


    //dbv(pref);
    printf("%.17f\n", dist[1]);

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif 
}