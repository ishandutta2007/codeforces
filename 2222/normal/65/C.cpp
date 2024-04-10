#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)                  (a).begin(), (a).end()
#define sz(a)                   int((a).size())
#define FOR(i, a, b)    for (int i(a); i < b; ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(v)                   sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)                memset(a, b, sizeof a)
#define pb                              push_back
#define X                               first
#define Y                               second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

struct point {
        int x, y, z;
        void read() {
                scanf("%d%d%d", &x, &y, &z);
        }
} p[11111], p0;

double dist(const point &p, const point &q) {
        double x = p.x - q.x;
        double y = p.y - q.y;
        double z = p.z - q.z;
        return sqrt(x * x + y * y + z * z);
}

int n, vp, vs;

void solve(const point &p, const point &q, double t0, double t1) {
        double L = 0, R = 1, V;
        REP (k, 128) {
                V = (L + R) / 2;
                double x = p.x + (q.x - p.x) * V;
                double y = p.y + (q.y - p.y) * V;
                double z = p.z + (q.z - p.z) * V;               
                double t = t0 + (t1 - t0) * V;
                double d2 = x * x + y * y + z * z;
                double e2 = t * vp;
                (d2 <= e2 * e2 ? R : L) = V;
        }
        V = (L + R) / 2;
        double x = p.x + (q.x - p.x) * V;
        double y = p.y + (q.y - p.y) * V;
        double z = p.z + (q.z - p.z) * V;               
        double t = t0 + (t1 - t0) * V;
        double d2 = x * x + y * y + z * z;
        double e2 = t * vp;
        if (d2 <= e2 * e2 + 1e-9) {
                puts("YES");
                printf("%.12lf\n", t);
                printf("%.12lf %.12lf %.12lf\n", x + p0.x, y + p0.y, z + p0.z);
                exit(0);
        }
}

int main(){
        #ifdef LocalHost
        freopen("x.in", "r", stdin);
        freopen("x.out", "w", stdout);
        #endif
        cin >> n;
        REP (i, n + 1) p[i].read();
        cin >> vp >> vs;
        p0.read();
        REP (i, n + 1) {
                p[i].x -= p0.x;
                p[i].y -= p0.y;
                p[i].z -= p0.z;
        }
        double now = 0;
        REP (i, n) {
                double d = dist(p[i], p[i + 1]) / vs;
                solve(p[i], p[i + 1], now, now + d);
                now += d;
        }
        puts("NO");
        return 0;
}