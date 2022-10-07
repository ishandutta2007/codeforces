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
const int N = -1;
const long long INF = 1e9 + 19;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

bool less(double a, double b) {
    return a < b && !equal(a, b);
}

bool lessE(double a, double b) {
    return a < b || equal(a, b);
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
    double operator * (pnt A) {
        return x * A.y - y * A.x; 
    }
    double operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    pnt operator * (double k) {
        return pnt(x * k, y * k);
    }
    pnt operator / (double k) {
        return pnt(x / k, y / k);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    pnt rotate() {
        return pnt(-y, x);
    }
    pnt norm() {
        return (*this) / len();
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

struct Line {
    pnt O, v;
    Line () { }
    Line (pnt A, pnt B): O(A), v((B - A).norm()) { }
    pnt operator * (Line l) {
        pnt u = l.v.rotate();
        assert(!equal(0, v % u));
        double t = (l.O - O) % u / (v % u);
        return O + v * t;
    }
};


double y11, y22, yw, r;
pnt O;


void read() {
    scanf("%lf%lf%lf", &y11, &y22, &yw);
    O.read();
    scanf("%lf", &r);
}

Line getTan(pnt A, double r, pnt B) {
    pnt v = (B - A).norm();
    double l = (A - B).len();
    double d = r * r / l;
    pnt C = A + v * d;
    v = v.rotate();
    pnt D = C + v * (r * sqrt(1 - r * r / l / l));  
    //db2((D - A).len(), r);
    assert(equal((D - A).len(), r));
    return Line(D, B);
}

void solve() {
    y11 = (yw - r) * 2 - y11;
    y22 = (yw - r) * 2 - y22;
    pnt A(0, y11 - r);
    Line l1(A, O);
    Line hor(pnt(0, yw - r), pnt(1, yw - r));
    double x1 = (l1 * hor).x;
    pnt B(0, y22);
    Line l2 = getTan(B, r, O);
    double x2 = (l2 * hor).x;
    assert(!equal(x1, x2));
    //db2(x1, x2);
    if (less(x2, x1)) {
        printf("%.17f\n", (x1 + x2) / 2);
    }
    else 
        puts("-1");
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
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}