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
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;

bool eq(dbl a, dbl b) {
    return abs(a - b) < 1e-9;
}

bool ls(dbl a, dbl b) {
    return a < b && !eq(a, b);
}

bool lsE(dbl a, dbl b) {
    return a < b || eq(a, b);
}

struct pt {
    dbl x, y;
    pt operator + (pt A) {
        return {x + A.x, y + A.y};
    }
    pt operator - (pt A) {
        return {x - A.x, y - A.y};
    }
    dbl operator * (pt A) {
        return x * A.y - y * A.x;
    }
    dbl operator % (pt A) {
        return x * A.x + y * A.y;
    }
    pt operator * (dbl k) {
        return {x * k, y * k};
    }
    pt operator / (dbl k) {
        assert(abs(k) > 1e-20);
        return {x / k, y / k};
    }
    dbl len2() {
        return x * x + y * y;
    }
    dbl len() {
        return sqrt(x * x + y * y);
    }
    pt rotate() {
        return {-y, x};
    }
    pt norm() {
        return (*this) / len();
    }
    pt setLen(dbl l) {
        return norm() * l;
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    void Epr() {
        cerr << "pt x y: " << x << ", " << y << endl;
    }
};

void intCC(pt A, dbl ra, pt B, dbl rb, pt& E, pt& F) {
    dbl d = (A - B).len(); 
    dbl ca = (ra * ra + d * d - rb * rb) / (2 * ra * d);
    //db3(ra, d, rb);
    dbl si = sqrt(max(0.0, 1 - ca * ca));
    //db2(ca, si);
    pt v = (B - A).norm();
    pt u = v.rotate();
    E = A + v * (ra * ca) + u * (ra * si);
    F = A + v * (ra * ca) - u * (ra * si);
    assert(eq((A - E).len(), ra));
    assert(eq((A - F).len(), ra));
    assert(eq((B - E).len(), rb));
    assert(eq((B - F).len(), rb));
}

pt inv(pt A) {
    return A / A.len2();
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int t;
    scanf("%d", &t);   
    for (int tt = 0; tt < t; tt++) {
        int R, r, k;
        scanf("%d%d%d", &R, &r, &k);
        k++;
         

        pt C1, C2; 
        pt D1, D2;
        intCC({0, 0}, 1, {0, R * 1.0}, R, C1, C2);
        intCC({0, 0}, 1, {0, r * 1.0}, r, D1, D2);

        dbl h1 = C1.y; 
        dbl h2 = D1.y;
        //db2(h1, h2);
        assert(h1 < h2);
        dbl dh = h2 - h1;
        dbl rr = dh / 2;
        dbl x = 0 + (k - 1) * dh; 
        dbl y = h1 + rr;
        pt O = {x, y};
        //O.Epr();
        pt O1 = O.setLen(O.len() - rr); 
        pt O2 = O.setLen(O.len() + rr); 
        //db2(O1.x, O1.y);
        //db2(O2.x, O2.y);
        //inv(O1).Epr();
        //inv(O2).Epr();

        dbl res = (inv(O1) - inv(O2)).len() / 2; 
        printf("%.17f\n", res);





    }
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}