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
    pt(){}
    pt(dbl xx, dbl yy): x(xx), y(yy) {}
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    pt operator * (dbl k) {
        return pt(x * k, y * k);
    }
    pt operator / (dbl k) {
        /*if (abs(k) < 1e-20) {
            while (true);
        }*/
        assert(abs(k) > 1e-20);
        return pt(x / k, y / k);
    }
    dbl operator * (pt A) {
        return x * A.y - y * A.x;
    }
    dbl operator % (pt A) {
        return x * A.x + y * A.y;
    }
    bool operator == (pt A) {
        return eq(x, A.x) && eq(y, A.y);
    }
    bool operator != (pt A) {
        return !eq(x, A.x) || !eq(y, A.y);
    }
    dbl len() {
        return sqrt(x * x + y * y);
    }
    dbl len2() {
        return x * x + y * y;
    }
    pt rotate () {
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
    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

struct Line {
    pt O, v;
    int id;
    Line() {}
    Line(pt A, pt B): O(A), v((B - A).norm()) {}
    pt operator * (Line l) {
        pt u = l.v.rotate();
        assert(abs(v % u) > 1e-20);
        /*if (eq(v % u, 0)) {
            while (true);
        }*/
        dbl t = (l.O - O) % u / (v % u);
        return O + v * t;
    }
    void Epr() {
        cerr << "v: " << v.x << " " << v.y << endl;
        cerr << "O: " << O.x << " " << O.y << endl;
    }
};


int getPart(pt v) {
    return ls(0, v.y) || (eq(0, v.y) && ls(v.x, 0));
    //return ls(v.y, 0) || (eq(0, v.y) && ls(v.x, 0));
}

int cmpV(pt a, pt b) {
    int partA = getPart(a);
    int partB = getPart(b);
    if (partA < partB) return -1; 
    if (partA > partB) return 1;
    if (eq(0, a * b)) return 0;
    if (0 < a * b) return -1;
    return 1;
}

bool planeInt(vector<Line> l, pt& ret) {
    /*db("CALL");
    for (auto L: l) {
        cerr << endl;
        db2(L.O.x, L.O.y);
        db2(L.v.x, L.v.y);
    }*/
    int n = l.size();
    //db(l.size());
    //db("!");
    /*sort(all(l), [](Line a, Line b) {
            int r = cmpV(a.v, b.v);
            if (r != 0) return r < 0;
            return a.O % a.v.rotate() < b.O % a.v.rotate();
        });*/
    //db("done");
    
    int cur = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && cmpV(l[j].v, l[i].v) == 0 && cmpV(l[i].v, l[j].v) == 0; i++);
        l[cur++] = l[i - 1];
    }
    n = cur;

    for (int i = 0; i < n; i++)
        l[i].id = i;

    /*int flagUp = 0;
    int flagDown = 0;
    for (int i = 0; i < n; i++) {
        int part = getPart(l[i].v);
        if (part == 1) flagUp = 1;
        if (part == 0) flagDown = 1;
    }
    if (!flagUp || !flagDown) return -1;*/

    /*for (int i = 0; i < n; i++) {
        pt v = l[i].v;
        pt u = l[(i + 1) % n].v;
        if (eq(0, v * u) && ls(v % u, 0)) {
            pt dir = l[i].v.rotate();
            if (le(l[(i + 1) % n].O % dir, l[i].O % dir)) return 0;
            return -1;
        }
        if (ls(v * u, 0))
            return -1;
    }  */
    
    cur = 0;
    vector<Line> st(n * 2);
    for (int tt = 0; tt < 2; tt++) {
        for (int i = 0; i < n; i++) {
            for (; cur >= 2; cur--) {
                //db3(cur, tt, i);
                ///st[cur - 1].Epr();
                //l[i].Epr();
                if (eq(st[cur - 1].v * l[i].v, 0)) return 0;
                pt G = st[cur - 1] * l[i];
                //db("!!!!!!!!!!!");
                if (!le(st[cur - 2].v * (G - st[cur - 2].O), 0))
                    break;
            }
            st[cur++] = l[i];
            if (cur >= 2 && le(st[cur - 2].v * st[cur - 1].v, 0)) return 0;
        }
    }
    vector<int> use(n, -1); 
    int left = -1, right = -1;
    for (int i = 0; i < cur; i++) {
        if (use[st[i].id] == -1) {
            use[st[i].id] = i;
        }
        else {
            left = use[st[i].id];
            right = i;
            break;
        }
    }
    vector < Line > tmp;
    for (int i = left; i < right; i++)
        tmp.pb(st[i]);
    //db(tmp.size());
    if (!tmp.empty()) {
        /*if (tmp.size() < 2) {
            return false;
        }*/
        assert(tmp.size() >= 2);
        //if (eq(tmp[0].v * tmp[1].v, 0)) {
            //while(true);
        //}
        ret = tmp[0] * tmp[1];        
        return true;
    }
    return false;

    /*vector < pt > res;
    for (int i = 0; i < (int)tmp.size(); i++) 
        res.pb(tmp[i] * tmp[(i + 1) % tmp.size()]);
    double area = 0;
    for (int i = 0; i < (int)res.size(); i++)
        area += res[i] * res[(i + 1) % res.size()];
    return area / 2;*/
}

bool checkPoint(vector<Line> l, pt& ret) {
    random_shuffle(all(l)); 
    pt A = l[0].O;
    for (int i = 1; i < sz(l); i++) {
        if (!le(0, l[i].v * (A - l[i].O))) {
            dbl mn = -INF;    
            dbl mx = INF;
            for (int j = 0; j < i; j++) {
                if (eq(l[j].v * l[i].v, 0)) {
                    if (l[j].v % l[i].v < 0 && (l[j].O - l[i].O) % l[i].v.rotate() <= 0) {
                        return false;
                    }
                }
                else {
                    pt u = l[j].v.rotate();
                    dbl proj = (l[j].O - l[i].O) % u / (l[i].v % u);
                    if (l[i].v * l[j].v > 0) {
                        mx = min(mx, proj);
                    }
                    else {
                        mn = max(mn, proj);
                    }
                }
            }
            if (mn <= mx) {
                A = l[i].O + l[i].v * mn;
            }
            else {
                return false;
            }
        }
    }
    ret = A;
    return true;
}



dbl fast(vector<pt> p, pt& R1, pt& R2) {
    int n = p.size();
    auto build = [&](int st, int cnt, dbl d, pt& ret) {
        vector<Line> l;
        //vector<Line> l1, l2;
        for (int i = 0; i < cnt; i++) {
            pt A = p[(st + i) % n];
            pt B = p[(st + i + 1) % n];
            pt v = (B - A).norm().rotate();
            l.pb(Line(A, B));
            l.pb(Line(B + v * d, A + v * d));
        }
        return checkPoint(l, ret);
    };

    pair<pt,pt> sert;

    auto check = [&](dbl d) {
        vector<int> go(n); 
        vector<pt> how(n);
        int cur = 0;
        pt lastRet = pt(0, 0);
        for (int i = 0; i < n; i++) {
            cur = max(cur, 1);
            for (;cur < n; cur++) {
                pt ret;
                if (build(i, cur + 1, d, ret)) {
                    lastRet = ret;
                }
                else {
                    break;
                }
            }
            how[i] = lastRet;
            go[i] = cur;
            cur--;
        }

        for (int i = 0; i < n; i++) {
            if (go[i] + go[(i + go[i]) % n] >= n) {
                sert = {how[i], how[(i + go[i]) % n]};
                return true;
            }
        }
        return false;
    };

    dbl l = 0;
    dbl r = 1e6;
    for (int it = 0; it < 70; it++) {
        if (check((l + r) / 2)) {
            r = (l + r) / 2;
        }
        else {
            l = (l + r) / 2;
        }
    }
    R1 = sert.F;
    R2 = sert.S;
    return r;

}

vector<pt> convexHull(vector<pt> p) {
    //db(p.size()); for (auto A: p) { db2(A.x, A.y); }
    sort(all(p), [](pt A, pt B) {
            return ls(A.x, B.x) || (eq(A.x, A.y) && ls(A.y, B.y));
            });
    //db("sort Done");

    vector<pt> st;
    for (int tt = 0; tt < 2; tt++) {
        int cur = st.size();
        for (auto A: p) {
            for (; sz(st) >= cur + 2 && le((st.back() - st[st.size() - 2]) * (A - st.back()), 0); st.pop_back());
            st.pb(A);
        }
        st.pop_back();
        reverse(all(p));
    }
    //db(st.size());
    return st;
}


int main() {
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
    //freopen("C.test", "r", stdin);
#endif
    if (1) {
        int n;
        scanf("%d", &n);
        vector<pt> p(n);
        for (int i = 0; i < n; i++) {
            p[i].read(); 
        }
        pt R1, R2;
        dbl r = fast(p, R1, R2);
        printf("%.17f\n", (double)r);
        printf("%.17f %.17f\n", (double)R1.x, (double)R1.y);
        printf("%.17f %.17f\n", (double)R2.x, (double)R2.y);
    }
    else {
        for (int tt = 237; ; tt++) {
            srand(tt);
            db(tt);
            int n;
            vector<pt> p;
            while (true) {
                n = rand() % 300 + 1;
                p.clear();
                int T = 100;
                for (int i = 0; i < n; i++) {
                    p.pb(pt(rand() % T, rand() % T));
                }
                p = convexHull(p);
                if (p.size() >= 3) {
                    break;
                }
            }
            pt R1, R2;
            db(p.size());
            fast(p, R1, R2);

        }
    }
    return 0;
}