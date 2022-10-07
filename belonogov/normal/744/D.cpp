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


vector<pt> convexHull(vector<pt> p) {
    for (int i = 0; i < (int)p.size(); i++) {
        if (less(p[i].y, p[0].y) || (equal(p[i].y, p[0].y) && less(p[i].x, p[0].x)))
            swap(p[i], p[0]);
    }
    pt O = p[0];
    sort(p.begin() + 1, p.end(), [=] (pt A, pt B) { 
                pt v = A - O; 
                pt u = B - O;
                return less(0, v * u) || (equal(v * u, 0) && less(v.len(), u.len()));
            });
    vector<pt> st;
    for (auto A: p) {
        for (;st.size() >= 2 && lessE((st.back() - st[sz(st) - 2]) * (A - st.back()), 0); st.pop_back());
        st.pb(A);
    }
    return st;
}

bool onLine(pt A, pt B, pt C) {
    return equal((A - B) * (C - A), 0);
}

bool onSeg(pt A, pt B, pt C) {
    return onLine(A, B, C) && (C - A) % (C - B) < 0;
}
// 0 out 
// 1 bound
// 2 inside

int checkInside(vector<pt> ch, pt A, int& id1, int& id2) {
    if (less(0, (A - ch[0]) * (ch[1] - ch[0]))) {
        return 0;
    }
    if (less((A - ch[0]) * (ch.back() - ch[0]), 0)) {
        return 0;
    }
    if (onSeg(ch[0], ch[1], A)) {
        id1 = 0;
        id2 = 1;
        return 1;
    }
    if (onSeg(ch.back(), ch[0], A)) {
        id1 = ch.size() - 1;
        id2 = 0;
        return 1;
    }
    int l = 1;
    int r = ch.size() - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if ((ch[mid] - ch[0]) * (A - ch[0]) > 0)
            l = mid;
        else
            r = mid;
    }
    if (onSeg(ch[l], ch[r], A)) {
        id1 = l;
        id2 = r;
        return 1;
    }
    if (less(0, (ch[r] - ch[l]) * (A - ch[l])))
        return 2;
    return 0;
}

double answer = INF;

void updAnswer(pt A, pt B) {
    pt v = (A - B).norm();
    answer = min(abs(v * A), answer);
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pt> red(n);
    vector<pt> blue(m);
    for (int i = 0; i < n; i++) {
        red[i].read();
    }
    for (int i = 0; i < m; i++) {
        blue[i].read();
    }
    double T = 10000;

    for (int i = 0; i < m; i++) {
        pt O = blue[i];
        vector<pt> p;
        for (int j = 0; j < m; j++) {
            if (i == j)
                p.pb(pt(0, 0));
            else {
                pt v = blue[j] - O;
                p.pb(v / v.len2() * T);
            }
        }
        auto ch = convexHull(p);
        if (ch.size() <= 2) {
            answer = 0; 
            continue;
        }
        //db(ch.size());
        int g = 1;
        for (; pw(g + 1) <= sz(ch); g++);
        
        vector<int> cof(sz(ch) + 1);
        for (auto A: red) {
            A = A - O;
            A = A / A.len2() * T;
            int id1, id2;
            int res = checkInside(ch, A, id1, id2);
            if (res == 1) {
                updAnswer(ch[id1], ch[id2]);
            }
            else if (res == 0) {
                int lt = 0;
                int rt = 0;

                for (int j = g; j >= 0; j--) {
                    int best = lt;
                    for (int tt = -1; tt <= 1; tt += 2) {
                        int np = (lt + pw(j) * tt + sz(ch)) % sz(ch);
                        if ((ch[np] - A) * (ch[best] - A) < 0)
                            best = np;
                    }
                    lt = best;
                }

                for (int j = g; j >= 0; j--) {
                    int best = rt;
                    for (int tt = -1; tt <= 1; tt += 2) {
                        int np = (rt + pw(j) * tt + sz(ch)) % sz(ch);
                        if ((ch[np] - A) * (ch[best] - A) > 0)
                            best = np;
                    }
                    rt = best;
                }
                //db2(lt, rt);

                assert(rt != lt);
                updAnswer(ch[lt], A);
                updAnswer(ch[rt], A);
                cof[lt]++;
                cof[rt]--;
                if (rt < lt) {
                    cof[0]++;
                    cof[sz(ch)]--;
                }
            }
        }
        int bal = 0;
        for (int j = 0; j < sz(ch); j++) {
            bal += cof[j];
            if (bal > 0)
                updAnswer(ch[j], ch[(j + 1) % ch.size()]);
        }
    }
    if (equal(answer, 0)) {
        puts("-1");
    } 
    else
        printf("%.17f\n", T / answer / 2);

    return 0;
}