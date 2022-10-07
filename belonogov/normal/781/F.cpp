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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool equal(double a, double b) {
    return abs(a - b) < 1e-12;
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
        double xx, yy;
        scanf("%lf%lf", &xx, &yy);
        x = xx;
        y = yy;
    }
    void Epr() {
        cerr << "x y " << x << " " << y << endl;
    }
};

struct State {
    int v;
    double shift;
};

int n, m;
pt p[N];
State pos[N];
double step;
int use[N];

double mxStep(State A) {
    double segLen = (p[A.v] - p[(A.v + 1) % n]).len();
    return segLen - A.shift;
}

void upd(State& A) {
    double segLen = (p[A.v] - p[(A.v + 1) % n]).len();
    if (equal(segLen, A.shift)) {
        A.v = (A.v + 1) % n;
        A.shift = 0;
    }
}

void getPos(State A, pt& O, pt& v) {
    v = (p[(A.v + 1) % n] - p[A.v]).norm();
    O = p[A.v] + v * A.shift;
} 

bool intSL(pt O, double R, pt A, pt v, double& t1, double& t2) {
    double d = (O - A) % v;
    double h = abs((O - A) * v);
    if (R <= h)
        return 0;
    double tmp = sqrt(max(0.0, R * R - h * h));
    t1 = d - tmp;
    t2 = d + tmp;
    return 1;
}

struct Event {
    double t;
    int type;
    int id;
};

bool check(double R) {
    cerr << R << endl;
    vector<Event> event; 
    for (int i = 0; i < m; i++) {
        double need = step;
        State A = pos[i];
        State B = pos[(i + 1) % m];
        for (;!equal(need, 0);) {
            double d = min(need, min(mxStep(A), mxStep(B)));
            pt C, D, v, u;            
            getPos(A, C, v);
            getPos(B, D, u);
            u = u - v; 
            if (!equal(d, 0)) {
                if (equal(u.len(), 0)) {
                    if ((C - D).len() <= R) {
                        double l = 0 + step - need;
                        double r = d + step - need;
                        event.pb({l, 1, i}); 
                        event.pb({r, -1, i}); 
                    }
                }
                else {
                    double lenU = u.len();
                    u = u.norm();
                    double t1, t2; 
                    if (intSL(C, R, D, u, t1, t2)) {
                        t1 /= lenU;
                        t2 /= lenU;
                        t1 = min(d, max(t1, 0.0));
                        t2 = min(d, max(t2, 0.0));
                        if (0 < t2 && t1 < d) {
                            double l = t1 + step - need;
                            double r = t2 + step - need;
                            event.pb({l, 1, i}); 
                            event.pb({r, -1, i}); 
                        }
                    }
                }
            }
            A.shift += d;
            B.shift += d;
            need -= d;
            upd(A);
            upd(B);
        }
    }
    sort(all(event), [](Event A, Event B) {
            return A.t < B.t || (A.t == B.t && A.type < B.type);
            });
    int bal = 0;
    memset(use, 0, sizeof use);
    for (auto x: event) {
        bal -= use[x.id] >= 1;
        use[x.id] += x.type;
        bal += use[x.id] >= 1;
        //assert(bal >= 0);
        if (bal == m)
            return 1;
    } 
    return 0;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
}

double solve() {
    double T = 0;
    for (int i = 0; i < n; i++) {
        T += (p[i] - p[(i + 1) % n]).len();
    }
    step = T / m;    

    State A = {0, 0};
    for (int i = 0; i < m; i++) {
        double need = step;
        for (;!equal(need, 0); ) {
            double d = min(mxStep(A), need);
            need -= d;
            A.shift += d;
            upd(A);
        }
        pos[i] = A;
    }
    double l = 0;
    double r = 1e4;
    for (int it = 0; it < 60; it++) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    return r;
}
int main(){
    read();
    printf("%.17f\n", solve());
    return 0;
}