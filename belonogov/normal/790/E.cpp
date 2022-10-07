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

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}
bool less(double a, double b) {
    return a < b && !equal(a, b);
}
bool lessE(double a, double b) {
    return a < b || equal(a, b);
}

struct ptll {
    ll x, y;
    ptll() {}
    ptll(ll xx, ll yy): x(xx), y(yy) { }
    ptll operator + (ptll A) {
        return ptll(x + A.x, y + A.y);
    }
    ptll operator - (ptll A) {
        return ptll(x - A.x, y - A.y);
    }
    ll operator * (ptll A) {
        return x * A.y - y * A.x;
    }
    ll operator % (ptll A) {
        return x * A.x + y * A.y;
    }
    ptll operator * (ll k) {
        return ptll(x * k, y * k);
    }
    ll len2() {
        return x * x + y * y;
    }
    bool operator == (ptll A) {
        return x == A.x && y == A.y;
    }
    bool operator != (ptll A) {
        return x != A.x || y != A.y;
    }
    ptll rotate() {
        return ptll(-y, x);
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    void Epr() {
        cerr << "x y " << x << " " << y << endl;
    }
};





struct pt {
    double x, y;
    pt() {}
    pt(double xx, double yy): x(xx), y(yy) { }
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    double operator * (pt A) {
        return x * A.y - y * A.x;
    }
    double operator % (pt A) {
        return x * A.x + y * A.y;
    }
    pt operator * (double k) {
        return pt(x * k, y * k);
    }
    pt operator / (double k) {
        assert(!equal(k, 0));
        return pt(x / k, y / k);
    }
    bool operator == (pt A) {
        return equal(x, A.x) && equal(y, A.y);
    }
    bool operator != (pt A) {
        return !equal(x, A.x) && !equal(y, A.y);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    double len2() {
        return x * x + y * y;
    }
    pt norm() {
        return (*this) / len();
    }
    pt rotate() {
        return pt(-y, x);
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    void Epr() {
        cerr << "x y " << x << " " << y << endl;
    }
};


pt makePt(ptll A) {
    return pt(A.x, A.y);
}

struct Line {
    pt O, v;
    int id;
    Line() { }
    Line(pt A, pt B): O(A), v((B - A).norm()) { }
    Line(ptll A, ptll B): O(makePt(A)), v(makePt((B - A)).norm()) { }
    pt operator * (Line l) {
        pt u = l.v.rotate();
        double k = (l.O - O) % u / (v % u);
        return O + v * k;
    }
};


int getPart(pt v) {
    return less(0, v.y) || (equal(0, v.y) && less(v.x, 0));
}

int cmpV(pt a, pt b) {
    int partA = getPart(a);
    int partB = getPart(b);
    if (partA < partB) return -1; 
    if (partA > partB) return 1;
    if (equal(0, a * b)) return 0;
    if (0 < a * b) return -1;
    return 1;
}

double planeInt(vector<Line> l) {
    int n = l.size();
    sort(all(l), [](Line a, Line b) {
            int r = cmpV(a.v, b.v);
            if (r != 0) return r < 0;
            return a.O % a.v.rotate() < b.O % a.v.rotate();
        });
    
    int cur = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && cmpV(l[j].v, l[i].v) == 0 && cmpV(l[i].v, l[j].v) == 0; i++);
        l[cur++] = l[i - 1];
    }
    n = cur;

    for (int i = 0; i < n; i++)
        l[i].id = i;

    int flagUp = 0;
    int flagDown = 0;
    for (int i = 0; i < n; i++) {
        int part = getPart(l[i].v);
        if (part == 1) flagUp = 1;
        if (part == 0) flagDown = 1;
    }
    if (!flagUp || !flagDown) return -1;

    for (int i = 0; i < n; i++) {
        pt v = l[i].v;
        pt u = l[(i + 1) % n].v;
        if (equal(0, v * u) && less(v % u, 0)) {
            pt dir = l[i].v.rotate();
            if (lessE(l[(i + 1) % n].O % dir, l[i].O % dir)) return 0;
            return -1;
        }
        if (less(v * u, 0))
            return -1;
    }  
    
    cur = 0;
    vector<Line> st(n * 2);
    for (int tt = 0; tt < 2; tt++) {
        for (int i = 0; i < n; i++) {
            for (; cur >= 2; cur--) {
                pt G = st[cur - 1] * l[i];
                if (!lessE(st[cur - 2].v * (G - st[cur - 2].O), 0))
                    break;
            }
            st[cur++] = l[i];
            if (cur >= 2 && lessE(st[cur - 2].v * st[cur - 1].v, 0)) return 0;
        }
    }
    vector < int > use(n, -1); 
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
    vector < pt > res;
    for (int i = 0; i < (int)tmp.size(); i++) 
        res.pb(tmp[i] * tmp[(i + 1) % tmp.size()]);
    double area = 0;
    for (int i = 0; i < (int)res.size(); i++)
        area += res[i] * res[(i + 1) % res.size()];
    return area / 2;
}



int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int n;
        scanf("%d", &n);
        vector<ptll> p(n);
        for (int i = 0; i < n; i++)
            p[i].read();
        vector<ptll> b;
        for (int i = 1; i < n; i++)
            b.pb(p[i] - p[0]);

        sort(all(b), [](ptll A, ptll B) {
                    bool partA = (A.y < 0 || (A.y == 0 && A.x < 0));
                    bool partB = (B.y < 0 || (B.y == 0 && B.x < 0));
                    if (partA != partB) 
                        return partA < partB;
                    return A * B > 0;
                });
            
        //for (int i = 0; i + 1 < (int)b.size(); i++) {
            //if (b[i] * b[i + 1] == 0 && b[i] % b[i + 1] > 0) {
                //flag0 = 1;
            //}
        //}
        int TT = 1e6;
        vector<pt> bound = {pt(TT, TT), pt(-TT, TT), pt(-TT, -TT), pt(TT, -TT)};

        vector<Line> l;
        for (int i = 0; i < 4; i++)
            l.pb(Line(bound[i], bound[(i + 1) % 4]));

        bool flag0 = 0;

        for (int i = 0; i < (int)b.size(); i++) {
            if (b[i] * b[(i + 1) % b.size()] == 0) {
                flag0 = 1;
            }
        }

        if (flag0) {
            puts("0.0");
            continue;
        }
 
        for (int i = 0; i < (int)b.size(); i++) {
            ptll A = b[i];
            ptll B = b[(i + 1) % b.size()];
            if (A * B < 0) {
                swap(A, B);
            }
            l.pb(Line(A + p[0], B + p[0]));
        }

        int cur = 0;
        int m = b.size();
        for (int i = 0; i < m; i++)
            b.pb(b[i]);

        for (int i = 0; i < m; i++) {
            cur = max(i, cur);
            for (; cur + 1 < i + m && b[i] * b[cur + 1] >= 0; cur++) { }

            ptll A = b[i];
            ptll B = b[cur];
            if (i != cur) {
                assert(A * B >= 0); 
                l.pb(Line(A + p[0], B + p[0]));
            }
        }
        double res = planeInt(l);
        assert(lessE(0, res));
        printf("%.17f\n", res);

    }



    return 0;
}