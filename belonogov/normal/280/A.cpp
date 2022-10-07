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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const double pi = acos(-1);

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

bool lessE(double a, double b) {
    return a < b ||  equal(a, b);
}

bool less(double a, double b) {
    return a < b && !equal(a, b);
}

struct pnt {
    double x, y;
    pnt () { }
    pnt (double x, double y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    pnt operator * (double k) {
        return pnt(x * k, y * k);
    }
    pnt operator / (double k) {
        return pnt(x / k, y / k);
    }
    double operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    double operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    pnt norm() {
        return (*this) / len();
    }
    pnt rotate() {
        return pnt(-y, x);
    }
    pnt rotate(double ang) {
        return pnt(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y);
    }
    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
}; 

struct Line {
    pnt O, v;
    Line (pnt A, pnt B): O(A), v((B - A).norm()) { }
    pnt operator * (Line l) {
        pnt u = l.v.rotate();
        double t = (l.O - O) % u / (v % u);
        return O + v * t;
    } 
    void Epr() {
        cerr << "O x y: " << O.x << " " << O.y << "      v:  " << v.x << " " << v.y << endl;
    }
};


int w, h, ang;

void read() {
    scanf("%d%d%d", &w, &h, &ang);
}

bool onSeg(pnt A, pnt B, pnt C) {
    return lessE((C - A) % (C - B), 0); 
}

pnt O;

bool cmpO(pnt A, pnt B) {
    A = A - O;
    B = B - O;
    return less(0, A * B) || (equal(A * B, 0) && less(A.len(), B.len()));
}

pnt st[N];

double convexHull(vector < pnt > p) {
    int n = p.size();
    assert(n > 1);
    for (int i = 0; i < n; i++)
        if (less(p[i].y, p[0].y) || (equal(p[i].y, p[0].y) && less(p[i].x, p[0].x)))
            swap(p[i], p[0]);
    //for (auto pp: p)
        //pp.Epr();
    O = p[0];
    sort(p.begin() + 1, p.end(), cmpO);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (; cur >= 2 && lessE((st[cur - 1] - st[cur - 2]) * (p[i] - st[cur - 1]), 0); cur--);
        st[cur++] = p[i];
    }
    double area = 0;
    for (int i = 0; i < cur; i++)
        area += st[i] * st[(i + 1) % cur];

    return area / 2;
}

double solve() {
    ang %= 180;
    if (ang == 0) 
        return w * 1ll * h;
    if (ang == 90)
        return min(w, h) * 1ll * min(w, h);

    double aa = ang * pi / 180;

    vector < pnt > a;
    a.pb(pnt(w, h) / 2);
    a.pb(pnt(-w, h) / 2);
    a.pb(pnt(-w, -h) / 2);
    a.pb(pnt(w, -h) / 2);
    vector < pnt > b = a;
    for (auto &p: b)
        p = p.rotate(aa);

    //for (auto p: b)
        //p.Epr();
    //cerr << endl;
    vector < pnt > g;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            Line l1(a[i], a[(i + 1) % 4]);            
            Line l2(b[j], b[(j + 1) % 4]);
            //l1.Epr();
            //l2.Epr();
            if (!equal(l1.v * l2.v, 0)) {
                pnt O = l1 * l2;
                if (onSeg(a[i], a[(i + 1) % 4], O) && onSeg(b[j], b[(j + 1) % 4], O)) {
                    g.pb(O);
                    //O.Epr();
                    //return -1;
                }
            }
        }
    return convexHull(g);
}

void printAns(double x) {
    printf("%.17f\n", x);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}