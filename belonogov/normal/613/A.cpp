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
const int N = 1e6;
const long long INF = 1e9 + 19;
const double pi = acos(-1);

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

bool lessE(double a, double b) {
    return a < b || equal(a, b);
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
    pnt norm() {
        return (*this) / len();
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

pnt O;
int n;
pnt p[N];

void read() {
    scanf("%d", &n);
    O.read();
    for (int i = 0; i < n; i++) {
        p[i].read();
        p[i] = p[i] - O;
    }
}

bool onSeg(pnt A, pnt B, pnt C) {
    return lessE((C - A) % (C - B), 0);
}

void solve() {
    double mx = 0;
    double mn = INF;
    for (int i = 0; i < n; i++) {
        mx = max(mx, p[i].len());
        mn = min(mn, p[i].len());
        pnt A = p[i];
        pnt B = p[(i + 1) % n];
        pnt v = (B - A).norm();
        double h = (pnt(0, 0) - A) % v;
        pnt G = A + v * h;
        if (onSeg(A, B, G))
            mn = min(mn, G.len()); 
    }




    printf("%.17f\n", pi * (mx * mx - mn * mn));
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