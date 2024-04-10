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
    bool operator < (pt A) const {
        return ls(x, A.x)  || (eq(x, A.x) && ls(y, A.y));
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
        scanf("%lf%lf", &x, &y);
    }
};


vector<pt> intSS(pt A, dbl ra, pt B, dbl rb) {
    dbl d = (A - B).len();
    dbl ca = (ra * ra + d * d - rb * rb)  / (2 * ra * d);
    vector<pt> res;
    if (ls(ca, -1))  return res;
    if (ls(1, ca)) return res;

    dbl si = sqrt(max(0.0, 1 - ca * ca));

    pt v = (B - A).norm();
    pt F = A + v * (ra * ca);
    pt u = v.rotate();
    if (eq(si, 0)) {
        res.pb(F);
        return res;
    }
    else {
        res.pb(F + u * (si * ra));
        res.pb(F - u * (si * ra));
        return res;
    }
    assert(false);
}




int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    vector<dbl> r(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
        scanf("%lf", &r[i]);
    }
    set<pt> total;
    vector<set<pt>> onC(n);

    int cntEdge = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<pt> tmp = intSS(p[i], r[i], p[j], r[j]);
            for (auto A: tmp) {
                onC[i].insert(A);
                onC[j].insert(A);
                total.insert(A);
            }
            if (!tmp.empty()) {
                cntEdge++;
            }
        }
    }


    int cntComp = 1;
    if (n == 2 && cntEdge == 0) {
        cntComp = 2;
    }
    if (n == 3 && cntEdge == 0) {
        cntComp = 3;
    }
    if (n == 3 && cntEdge == 1) {
        cntComp = 2;
    }

    int edge = 0;
    int v = total.size();
    for (int i = 0; i < n; i++) {
        edge += onC[i].size();
    }
//    db(cntComp);
    int answer = edge + 2 - v + cntComp - 1;
    cout << answer << endl;


















    return 0;
}