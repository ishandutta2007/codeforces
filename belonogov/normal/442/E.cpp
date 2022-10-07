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
    dbl x, y;
    int id;

    pt() {}

    pt(dbl xx, dbl yy) : x(xx), y(yy) {}

    pt(dbl xx, dbl yy, int iid) : x(xx), y(yy), id(iid) {}

    pt operator+(pt A) const {
        return pt(x + A.x, y + A.y);
    }

    pt operator-(pt A) const {
        return pt(x - A.x, y - A.y);
    }

    pt operator*(dbl k) const {
        return pt(x * k, y * k);
    }

    pt operator/(dbl k) {
        assert(abs(k) > 1e-20);
        return pt(x / k, y / k);
    }

    dbl operator*(pt A) const {
        return x * A.y - y * A.x;
    }

    dbl operator%(pt A) const {
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

    pt rotate() const {
        return pt(-y, x);
    }

    pt norm() {
        return (*this) / len();
    }

    void read() {
        double xx, yy;
        scanf("%lf%lf", &xx, &yy);
        x = xx;
        y = yy;
    }
};


vector<vector<int>> e;

struct Line {
    pt O, v;
    int id;

    Line() {}

    Line(pt A, pt B) : O(A), v((B - A).norm()) {}

    Line(pt A, pt B, int iid) : O(A), v((B - A).norm()), id(iid) {}

    pt operator*(const Line &l) const {
        pt u = l.v.rotate();
        assert(abs(v % u) > 1e-20);
        dbl t = (l.O - O) % u / (v % u);
        return O + v * t;
    }

    void print() {
        cerr << "O: " << O.x << " " << O.y << "     " << "v: " << v.x << " " << v.y << "         id: " << id << endl;
        cerr << endl;
    }
};


vector<pt> cell;
vector<Line> st;
vector<int> usedId;

bool getPart (pt v) {
    return ls(v.y, 0) || (eq(v.y, 0) && ls(v.x, 0));
};

vector<int> interHalfPlane(int n, vector<Line> l) {
    st.clear();
    cell.clear();

    //cerr << endl; //db(l.size()); //for (auto g: l) { g.print(); }

    int cur = 0;
    for (int j = 0; j < sz(l);) {
        int t = j;
        for (; j < sz(l) && getPart(l[j].v) == getPart(l[t].v) && eq(0, l[j].v * l[t].v); j++);
        l[cur++] = l[t];
    }
    l.resize(cur);

    for (int tt = 0; tt < 2; tt++) {
        for (int i = 0; i < sz(l); i++) {
//            db3(tt, i, st.size());
            for (; st.size() >= 2 && !ls(0, l[i].v * ((st.back() * st[st.size() - 2]) - l[i].O)); st.pop_back());
            st.pb(l[i]);
        }
    }
    usedId.assign(n + 4, -1);
    //db(l.size());

    vector<int> who;
    for (int i = 0; i < sz(st); i++) {
        if (usedId[st[i].id] != -1) {
            for (int j = usedId[st[i].id]; j < i; j++) {
                who.pb(st[j].id);
            }
            cell.clear();
            for (int j = usedId[st[i].id]; j < i; j++) {
                cell.pb(st[j] * st[j + 1]);
            }
            break;
        }
        usedId[st[i].id] = i;
    }
    return who;
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif
    int w, h, n;
    vector<pt> p;
    vector<int> deg;
    if (1) {
        scanf("%d%d%d", &w, &h, &n);
        vector<pair<int,int>> q;
        set<pair<int,int>> mem;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            q.pb({x, y});
        }
        sort(all(q));

        for (int i = 0; i < n; ) {
            int j = i;
            for (; i < sz(q) && q[i] == q[j]; i++);
            p.pb({q[j].F, q[j].S});
            deg.pb(i - j);
        }
        n = p.size();
    } else {
        w = h = 1e6;
        n = 1000;
        p.resize(n);
        w = 999000;
        h = 800000;
        for (int i = 0; i < n; i++) {
            p[i] = pt(1000 * i, 0);
        }
    }


    for (int i = 0; i < n; i++) {
        p[i].id = i;
    }
    dbl answer = 0;

    vector<vector<Line>> coolp(n);
    vector<vector<int>> who(n);
    auto addBound = [&](vector<Line> &g) {
        g.pb(Line(pt(0, 0), pt(1, 0), n));
        g.pb(Line(pt(0, 1), pt(0, 0), n + 1));
        g.pb(Line(pt(w, h - 1), pt(w, h), n + 2));
        g.pb(Line(pt(w, h), pt(w - 1, h), n + 3));

    };

    auto addLine = [&](pt A, pt B, vector<Line> &g) {
        g.pb(Line((A + B) / 2, (A + B) / 2 + (B - A).rotate(), B.id));
    };

    int totalLen = 0;
    for (int i = 0; i < n; i++) {
        vector<Line> g;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            addLine(p[i], p[j], g);
        }
        addBound(g);


        stable_sort(all(g), [&](const Line &A, const Line &B) {
            int partV = getPart(A.v);
            int partU = getPart(B.v);
            if (partV != partU) {
                return partV < partU;
            }
            if (eq(0, A.v * B.v)) {

                pt gg = A.v.rotate() * -1;
                return A.O % gg < B.O % gg;
            }
            return A.v * B.v > 0;
        });

        coolp[i] = g;

    }
//    cout << "total Len " << totalLen << endl; //    cout << (clock() - startT) * 1.0 / CLOCKS_PER_SEC << endl; //    cout << "AAAAA" << endl;
    for (int i = 0; i < n; i++) {
        who[i] = interHalfPlane(n, coolp[i]);
        for (auto H: cell) {
            answer = max(answer, (H - p[i]).len());
        }
    }
//    db("doneEEEEEEEEE"); //    cout << "BBBBB" << endl; //    cerr << (clock() - startT) * 1.0 / CLOCKS_PER_SEC << endl; //    cout << (clock() - startT) * 1.0 / CLOCKS_PER_SEC << endl;

    vector<int> megaUse;
    for (int i = 0; i < n; i++) {
//        db(i);
        if (deg[i] != 1) continue;
        for (auto neighbor: who[i]) {
            if (neighbor >= n) continue;
//            db2(i, neighbor);
            assert(i != neighbor);
            megaUse.assign(n + 4, 0);

            for (auto x: who[i]) {
                megaUse[x] = 1;
            }
            for (auto y: who[neighbor]) {
                megaUse[y] = 1;
            }

            megaUse[i] = 0;
//            dbv(megaUse);
            vector<Line> tmp;
            for (int t = 0; t < sz(coolp[neighbor]); t++) {
                if (megaUse[coolp[neighbor][t].id]) {
                    tmp.pb(coolp[neighbor][t]);
                }
            }
            interHalfPlane(n, tmp);
            for (auto A: cell) {
                dbl di = (A - p[i]).len();
                dbl dn = (A - p[neighbor]).len();
                if (le(di, dn)) {
                    answer = max(answer, dn);
                }
            }

        }
    }
    printf("%.17f\n", (double) answer);

//    cout << (clock() - startT) * 1.0 / CLOCKS_PER_SEC << endl;
    return 0;
}