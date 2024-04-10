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
#include <functional>

using namespace std;

#define F first
#define S second
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
typedef double dbl;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}
bool less(double a, double b) {
    return a < b && !equal(a, b);
}
bool lessE(double a, double b) {
    return a < b || equal(a, b);
}

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

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
    reverse(all(p));
    double answer = 1e18;
    for (int i = 0; i < n; i++) {
        pt A = p[i];
        pt B = p[(i + 1) % n];
        pt C = p[(i + 2) % n];
        pt v = (C - A).norm();
        answer = min(answer, (A - B).len());
        answer = min(answer, (B - A) * v);
    }


    printf("%.17f\n", answer / 2);
        



    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}