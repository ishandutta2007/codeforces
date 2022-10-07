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
typedef long double dbl;
const ll INF = 1.01e18;

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
    dbl x, y;

    pt() {}

    pt(dbl xx, dbl yy) : x(xx), y(yy) {}

    pt operator+(pt A) {
        return pt(x + A.x, y + A.y);
    }

    pt operator-(pt A) {
        return pt(x - A.x, y - A.y);
    }

    pt operator*(dbl k) {
        return pt(x * k, y * k);
    }

//    pt operator / (dbl k) {
//        assert(abs(k) > 1e-20);
//        return pt(x / k, y / k);
//    }
    dbl operator*(pt A) {
        return x * A.y - y * A.x;
    }

    dbl operator%(pt A) {
        return x * A.x + y * A.y;
    }

    bool operator==(pt A) {
        return eq(x, A.x) && eq(y, A.y);
    }

    bool operator!=(pt A) {
        return !eq(x, A.x) || !eq(y, A.y);
    }

    dbl len() {
        return sqrt(x * x + y * y);
    }

    dbl len2() {
        return x * x + y * y;
    }

    pt rotate() {
        return pt(-y, x);
    }

//    pt norm() {
//        return (*this) / len();
//    }
    void read() {
        double xx, yy;
        scanf("%lf%lf", &xx, &yy);
        x = xx;
        y = yy;
    }

    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

struct Line {
    pt O, v;

    Line(pt A, pt B) : O(A), v(B - A) {}

    pt operator*(Line l) {
        pt u = l.v.rotate();
        dbl t = (l.O - O) % u / (v % u);
        return O + v * t;
    }
};


int sign(dbl x) {
    if (eq(x, 0)) return 0;
    if (x < 0) return -1;
    return 1;
}

bool box(dbl a, dbl b, dbl c, dbl d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return le(max(a, c), min(b, d));
}

bool intSS(pt A, pt B, pt C, pt D) {
    return box(A.x, B.x, C.x, D.x) &&
           box(A.y, B.y, C.y, D.y) &&
           sign((B - A) * (C - A)) * sign((B - A) * (D - A)) <= 0 &&
           sign((D - C) * (A - C)) * sign((D - C) * (B - C)) <= 0;
}

dbl getX(pt A, pt B, pt C, pt D) {
    Line ab(A, B);
    Line cd(C, D);
    if (!eq(ab.v * cd.v, 0)) {
        return (ab * cd).x;
    }
    return max(min(A.x, B.x), min(C.x, D.x));
}


dbl slow(vector<pair<pt, pt>> seg) {
    dbl answer = INF;
    for (int i = 0; i < sz(seg); i++) {
        for (int j = i + 1; j < sz(seg); j++) {
            if (intSS(seg[i].F, seg[i].S, seg[j].F, seg[j].S)) {
                answer = min(answer, getX(seg[i].F, seg[i].S, seg[j].F, seg[j].S));
            }
        }
    }
    return answer;
}


dbl solve(vector<pair<pt, pt>> seg) {

    struct Seg {
        pt A, B;
    };

    struct CMP {
        bool operator()(Seg s1, Seg s2) const {
            if (eq(s1.A.x, s1.B.x)) {
                if (eq(s2.A.x, s2.B.x)) {
                    return ls(s1.A.y, s2.A.y);
                }
                return ls(0, (s1.A - s2.A) * (s2.B - s2.A));
            }
            if (eq(s2.A.x, s2.B.x)) {
                return ls(0, (s1.B - s1.A) * (s2.A - s1.A));
            }

            if (s1.A.x < s2.A.x) {
                return ls(0, (s1.B - s1.A) * (s2.A - s1.A));
            } else {
                return ls(0, (s1.A - s2.A) * (s2.B - s2.A));
            }
        }
    };
    struct Event {
        int type;
        pt A, B;
    };


    vector<Event> event;
    for (auto s: seg) {
        pt A = s.F;
        pt B = s.S;
        if (A.x > B.x) swap(A, B);
//        assert(!eq(A.x, B.x));
        event.pb({1, A, B});
        event.pb({-1, B, A});
    }

    sort(all(event), [](Event C, Event D) {
        if (eq(C.A.x, D.A.x)) {
            return C.type > D.type;
        }
        return C.A.x < D.A.x;
    });


    set<Seg, CMP> q;
    dbl win = INF;

    auto checkS = [&](Seg s1, Seg s2) {
        if (intSS(s1.A, s1.B, s2.A, s2.B)) {
            win = min(win, getX(s1.A, s1.B, s2.A, s2.B));
        }
    };

    auto check = [&](Seg s) {
        auto it = q.lower_bound(s);
        if (it != q.end()) {
            checkS(s, *it);
            it++;
            if (it != q.end()) {
                checkS(s, *it);
            }
        }
        it = q.lower_bound(s);
        if (it != q.begin()) {
            it--;
            checkS(s, *it);
            if (it != q.begin()) {
                it--;
                checkS(s, *it);
            }
        }
    };


    for (auto E: event) {
        if (le(win, E.A.x)) {
            break;
        }
        if (E.type == 1) {
            check({E.A, E.B});
//            assert(q.insert({E.A, E.B}).S);
            q.insert({E.A, E.B});
        } else {
            Seg s = {E.B, E.A};
            q.erase(s);
            auto it = q.lower_bound(s);
            if (it != q.end() && it != q.begin()) {
                auto it2 = it;
                it2--;
                checkS(*it, *it2);
            }

            //check({E.B, E.A});
        }
    }

    return win;
}


dbl solve2(vector<pair<pt, pt>> seg) {
    struct Event {
        pt A, B;
        int type;
    };
    vector<Event> event;
    for (auto s: seg) {
        pt A = s.F;
        pt B = s.S;
        if (A.x > B.x) swap(A, B);
        event.pb({A, B, 1});
        event.pb({B, A, -1});
    }
    sort(all(event), [](Event C, Event D) {
        return ls(C.A.x, D.A.x) || (eq(C.A.x, D.A.x) && C.type > D.type);
    });


    struct Seg {
        pt A, B;

        dbl getY(dbl x) const {
//            db3(A.x, x, B.x);
            assert(le(A.x, x) && le(x, B.x));
            if (eq(A.x, B.x)) {
                return A.y;
            }
            return (A.y * (B.x - x) + B.y * (x - A.x)) / (B.x - A.x);
        }
    };
    static dbl curX = 0;
    struct CMP2 {
        bool operator()(Seg s1, Seg s2) const {
            return ls(s1.getY(curX), s2.getY(curX));
        }
    };

    set<Seg, CMP2> q;


    dbl win = INF;

    auto checkS = [&](Seg s1, Seg s2) {
        if (intSS(s1.A, s1.B, s2.A, s2.B)) {
            win = min(win, getX(s1.A, s1.B, s2.A, s2.B));
        }
    };

    auto check = [&](Seg s) {
        auto it = q.lower_bound(s);
        if (it != q.end()) {
            checkS(s, *it);
            it++;
            if (it != q.end()) {
                checkS(s, *it);
            }
        }
        it = q.lower_bound(s);
        if (it != q.begin()) {
            it--;
            checkS(s, *it);
            if (it != q.begin()) {
                it--;
                checkS(s, *it);
            }
        }
    };

    for (auto E: event) {
        curX = E.A.x;
        if (le(win, curX)) {
            break;
        }
        if (E.type == 1) {
            Seg s = {E.A, E.B};
            check(s);
            q.insert(s);
        } else {
            Seg s = {E.B, E.A};
            auto it = q.lower_bound(s);
            if (it != q.end() && it != q.begin()) {
                auto it2 = it;
                it2--;
                it++;
                if (it != q.end()) {
                    checkS(*it, *it2);
                }
            }
            q.erase(s);
        }
    }

    return win;

}


void stress() {
    for (int tt = 0;; tt++) {
        db(tt);
        vector<pair<pt, pt>> seg;
        int n = rand() % 1000 + 1;
        int T = 100000;
        for (int i = 0; i < n; i++) {
            dbl speed = rand() % T + 1;
            dbl y1 = rand() % T;
            dbl y2 = rand() % T;
            int len = rand() % T;
            int shift = rand() % 10;
            dbl x1 = shift + (len + y1) / speed;
            dbl x2 = shift + (len + y2) / speed;
            seg.pb({{x1, y1},
                    {x2, y2}});
        }
        auto r1 = slow(seg);
        auto r2 = solve2(seg);
        db2(r1, r2);
        assert(eq(r1, r2));
    }

}

struct Robot {
    int t, c, v, u;

    void read() {
        scanf("%d%d%d%d", &t, &c, &v, &u);
        v--;
        u--;
    }
};


dbl fast(int n, vector<pair<int, int>> edge, vector<Robot> robot) {
    vector<vector<int>> e(n);
    for (auto x: edge) {
        int v = x.F;
        int u = x.S;
        e[v].pb(u);
        e[u].pb(v);
    }

    vector<int> h(n);
    vector<int> p(n, -1);
    vector<int> heavy(n, -1);
    vector<int> root(n);
    vector<int> pos(n);
    vector<vector<pair<pt, pt>>> seg(n);


    function<int(int, int)> dfs0 = [&](int v, int par) {
        int sz = 1;
        int mx = 0;
        for (auto u: e[v]) {
            if (u == par) continue;
            h[u] = h[v] + 1;
            p[u] = v;
            int ch = dfs0(u, v);
            if (ch > mx) {
                mx = ch;
                heavy[v] = u;
            }
            sz += ch;
        }
        return sz;
    };
    dfs0(0, -1);

    for (int i = 0; i < n; i++) {
        if (p[i] == -1 || heavy[p[i]] != i) {
            int cur = 0;
            for (int v = i; v != -1; v = heavy[v]) {
                root[v] = i;
                pos[v] = cur++;
            }
        }
    }
    auto add = [&](int v, int y1, int y2, dbl x1, dbl x2) {
        seg[v].pb({pt(x1, y1), pt(x2, y2)});
    };
    //const int MAGIC = 1;

    int m = robot.size();
    for (int i = 0; i < m; i++) {
//        db(i);
        dbl t = robot[i].t;
        dbl c = robot[i].c;
        int v = robot[i].v;
        int u = robot[i].u;

        int vv = v;
        int uu = u;
        int len = 0;
        for (; root[vv] != root[uu]; vv = p[root[vv]]) {
            if (h[root[uu]] > h[root[vv]]) swap(vv, uu);
            len += pos[vv] + 1;
        }
        len += abs(pos[vv] - pos[uu]);

        int progV = 0;
        int progU = 0;
        for (; root[v] != root[u];) {
            if (h[root[v]] > h[root[u]]) {
//                db2("VV", v);

                add(root[v], pos[v] + 1, 0, t + progV * 1.0 / c, t + (progV + pos[v] + 1) * 1.0 / c);
                progV += pos[v] + 1;
                v = p[root[v]];
            } else {
//                db(u);
                add(root[u], pos[u] + 1, 0, t + (len - progU) * 1.0 / c, t + (len - progU - pos[u] - 1) * 1.0 / c);
                progU += pos[u] + 1;
                u = p[root[u]];
            }
        }
//        db(v);
        //if (pos[v] > pos[u]) {
        add(root[v], pos[v] + 1, pos[u] + 1, t + (progV) * 1.0 / c, t + (progV + abs(pos[u] - pos[v])) * 1.0 / c);
        //}
//        else {
//            add(root[v], pos[v], pos[u], t + (progV) * 1.0 / c, t + (progV + pos[u] - pos[v]) * 1.0 / c);
//        }
    }
//    dbv(heavy);
//    dbv(root);

//    cerr << "FAST" << endl;
//    for (int i = 0; i < n; i++) {
//        db(i);
//        for (auto x: seg[i]) {
//            db2(x.F.x, x.F.y);
//            db2(x.S.x, x.S.y);
//            cerr << endl;
//        }
//    }

    dbl answer = INF;
    for (int i = 0; i < n; i++) {
        answer = min(answer, solve2(seg[i]));


    }
    return answer;
}

void mySwap(int &v, int &u) {
    if (v > u) swap(v, u);
}

dbl slow(int n, vector<pair<int, int>> edge, vector<Robot> robot) {
    vector<vector<int>> e(n);
    for (auto x: edge) {
        e[x.F].pb(x.S);
        e[x.S].pb(x.F);
    }

//    for (int i = 0; i < n; i++) {
//        dbv(e[i]);
//    }

    //vector<int> h(n);
    //vector<int> par(n);
    vector<int> st;
    vector<int> path;
    function<void(int, int, int)> dfs = [&](int v, int p, int target) {
        st.pb(v);
//        db3(v, p, target);
        if (v == target) {
            path = st;
//            db("!!!");
//            dbv(path);
            return;
        }
        for (auto u: e[v]) {
            if (u != p) {
                dfs(u, v, target);
                if (!path.empty()) {
                    return;
                }
            }
        }
        st.pop_back();
    };

    map<pair<int, int>, vector<pair<pt, pt>>> seg;
    vector<vector<dbl>> moment(n);
    for (auto x: robot) {
        int v = x.v;
        int u = x.u;
        dbl c = x.c;
        path.clear();
        st.clear();
        dfs(v, -1, u);
        assert(!path.empty());
        //for (int v =  )
//        db2(x.t, x.c);
//        dbv(path);
        for (int i = 0; i < sz(path) - 1; i++) {
            int vv = path[i];
            int uu = path[i + 1];
//            db2(vv, uu);
            if (vv > uu) {
                swap(vv, uu);
                seg[{vv, uu}].pb({{x.t + (i) * 1.0 / c,     1},
                                  {x.t + (i + 1) * 1.0 / c, 0}});
            } else {
                seg[{vv, uu}].pb({{x.t + (i) * 1.0 / c,     0},
                                  {x.t + (i + 1) * 1.0 / c, 1}});
            }
        }


        for (int i = 0; i < sz(path); i++) {
            dbl tmr = x.t + i * 1.0 / x.c;
            moment[path[i]].pb(tmr);
        }
    }
//    for (auto x: seg[{3, 5}]) {
//        db2(x.F.x, x.F.y);
//        db2(x.S.x, x.S.y);
//    }


    dbl answer = INF;
    for (int i = 0; i < n; i++) {
        sort(all(moment[i]));
        for (int j = 0; j < sz(moment[i]) - 1; j++) {
            if (eq(moment[i][j], moment[i][j + 1])) {
                answer = min(answer, moment[i][j]);
            }
        }
    }

    for (auto x: seg) {
        auto g = x.S;
        for (int i = 0; i < sz(g); i++) {
            for (int j = 0; j < i; j++) {
                if (intSS(g[i].F, g[i].S, g[j].F, g[j].S)) {
                    answer = min(answer, getX(g[i].F, g[i].S, g[j].F, g[j].S));
                }
            }
        }
    }
//    db(answer);

    return answer;
}


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif

    if (1) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<pair<int, int>> edge;
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            scanf("%d%d", &v, &u);
            v--;
            u--;
            edge.pb({v, u});
        }
        vector<Robot> robot(m);
        for (int i = 0; i < m; i++) {
            robot[i].read();
        }
        auto res = fast(n, edge, robot);
        if (res == INF) {
            puts("-1");
        } else {
            printf("%.17f", (double) res);
        }
    } else {
        for (int tt = 0;; tt++) {
            db(tt);
            int n = rand() % 10 + 1;
//            int n = 3;
            int m = rand() % 5 + 1;
//            int m = 2;
            vector<pair<int, int>> edge;
            for (int i = 1; i < n; i++) {
                int v = rand() % i;
                edge.pb({v, i});
            }
            vector<Robot> robot(m);
            for (int i = 0; i < m; i++) {
                robot[i] = {rand() % 10, rand() % 10 + 1, rand() % n, rand() % n};
            }
            auto r1 = fast(n, edge, robot);
            auto r2 = slow(n, edge, robot);
            cerr << n << " " << m << endl;
            for (auto x: edge) {
                cerr << x.F + 1 << " " << x.S + 1 << endl;
            }
            for (auto x: robot) {
                cerr << x.t << " " << x.c << " " << x.v + 1 << " " << x.u + 1 << endl;
            }
            db2(r1, r2);
            assert(eq(r1, r2));
        }
    }
    return 0;
}