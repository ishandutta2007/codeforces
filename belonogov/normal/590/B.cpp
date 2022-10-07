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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;

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
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
};

double v, t;
pnt A, B;
pnt v1, v2;

void read() {
    A.read();
    B.read();
    scanf("%lf%lf", &v, &t);
    v1.read();
    v2.read();
}

bool check(double tmr) {
    pnt O = A;
    if (tmr < t) {
        O = O + v1 * tmr;
    }
    else {
        O = O + v1 * t + v2 * (tmr - t);
    }
    return (O - B).len() < tmr * v;
}

void solve() {
    double l = 0;
    double r = INF;
    for (int t = 0; t < 100; t++) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%.17f\n", l);
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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