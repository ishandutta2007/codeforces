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
const dbl PI = acos(-1);

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
    dbl x, y, id;

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

    pt operator/(dbl k) {
        assert(abs(k) > 1e-20);
        return pt(x / k, y / k);
    }

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

    pt norm() {
        return (*this) / len();
    }

    bool operator<(pt A) {
        return x < A.x || (eq(x, A.x) && ls(y, A.y));
    }

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

struct Line {
    pt O, v;

    Line(pt A, pt B) : O(A), v((B - A).norm()) {}

    pt operator*(Line l) {
        pt u = l.v.rotate();
        dbl t = (l.O - O) % u / (v % u);
        return O + v * t;
    }
};

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
    reverse(all(p));

    int idMn = 0;
    int idMx = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] < p[idMn]) {
            idMn = i;
        }
        if (p[idMx] < p[i]) {
            idMx = i;
        }
    }
    vector<dbl> tr(n);
    vector<dbl> prefArea(n + 1);

    auto getTrap = [&](pt A, pt B) {
        return (A.x - B.x) * (A.y + B.y) / 2;
    };

    for (int i = 0; i < n; i++) {
        tr[i] = getTrap(p[i], p[(i + 1) % n]);
        //tr[i] = (p[(i + 1) % n].x - p[i].x) * (p[i].y + p[(i + 1) % n].y) / 2;
        prefArea[i + 1] = prefArea[i] + tr[i];
    }
    for (int i = 0; i < n; i++) p[i].id = i;
    vector<pt> part[2];
    for (int tt = 0; tt < 2; tt++) {
        for (int i = idMn; i != idMx; i = (i + 1) % n) {
            part[tt].pb(p[i]);
        }
        part[tt].pb(p[idMx]);
        swap(idMn, idMx);
    }


    auto getFarPoint = [&](pt v) {
        int where = 0;
        //for (int tt = 0; tt < 2; tt++) {
        int tt;
        //if (ls(0, v.y) || (eq(v.y, 0) && ls(v.x, 0))) {
        if (v.y < 0) {
            tt = 0;
        } else {
            tt = 1;
        }
        int l = 0;
        int r = part[tt].size() - 1;
        while (r - l > 3) {
            int m1 = (l + l + r) / 3;
            int m2 = (l + r + r) / 3;
            if (part[tt][m1] % v > part[tt][m2] % v) {
                r = m2;
            } else {
                l = m1;
            }
        }
        for (int i = l; i <= r; i++) {
            if (part[tt][i] % v > p[where] % v) {
                where = part[tt][i].id;
            }
        }
        return where;
    };
    auto getSegArea = [&](int l, int r) {
        l %= n;
        r %= n;
        if (l <= r) {
            return prefArea[r] - prefArea[l];
        }
        return prefArea[n] - prefArea[l] + prefArea[r];
    };

    auto getArea = [&](pt O, dbl ang) {
        pt v(cos(ang), sin(ang));
        pt u = v.rotate();
        int p1 = getFarPoint(u);
        int p2 = getFarPoint(u * -1);
        int ret[2];
        for (int tt = 0; tt < 2; tt++) {
            int l = p2;
            int r = p1;
            assert(l != r);
            if (r < l) {
                r += n;
            }
            while (r - l > 1) {
                if ((p[(l + r) / 2 % n] - O) * v > 0) {
                    l = (l + r) / 2;
                } else {
                    r = (l + r) / 2;
                }
            }
            ret[tt] = l;
            v = v * -1;
            swap(p1, p2);
        }
        pt G1 = Line(p[ret[0] % n], p[(ret[0] + 1) % n]) * Line(O, O + v);
        pt G2 = Line(p[ret[1] % n], p[(ret[1] + 1) % n]) * Line(O, O + v);

        dbl res = 0;
        res += getSegArea((ret[0] + 1) % n, ret[1]);
        res += getTrap(p[ret[1] % n], G2);
        res += getTrap(G2, G1);
        res += getTrap(G1, p[(ret[0] + 1) % n]);
        return res;
    };


    for (
            int tt = 0;
            tt < q;
            tt++) {
        pt O;
        O.

                read();

        dbl l, r;
        dbl res = getArea(O, 0);
        if (res * 2 < prefArea.

                back()

                ) {
            l = 0;
            r = PI;
        } else {
            l = PI;
            r = PI * 2;
        }


        for (
                int it = 0;
                it < 40; it++) {
            dbl tmp = getArea(O, (l + r) / 2);
            if (tmp * 2 < prefArea.

                    back()

                    ) {
                l = (l + r) / 2;
            } else {
                r = (l + r) / 2;
            }
        }
        dbl ang = (l + r) / 2;
        if (ang > PI) {
            ang -=
                    PI;
        }
        printf("%.17f\n", ang);
    }


    return 0;
}