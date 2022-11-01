#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <ctime>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;
typedef long long ll;

const int MN = 100100;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef pair<double, double> Q;

vector<P> res;

ll a[MN], b[MN], c[MN];


bool near(Q x, Q y) {
    Q z = Q(x.first-y.first, x.second-y.second);
    return sqrt(z.first*z.first + z.second*z.second) < EPS;
}

bool iscross(int x, int y) {
    return a[x]*b[y] != b[x]*a[y];
}

Q cross(int x, int y) {
    double X = a[x]*b[y]-b[x]*a[y];
    Q q(b[x]*c[y]-c[x]*b[y], c[x]*a[y]-a[x]*c[y]);
    q.first /= X; q.second /= X;
    return q;
}

clock_t st;
time_point<system_clock> stc;

bool solve(vector<int> v, int k) {
    if (v.size() == 0) return true;
    if (k == 0) return false;
    int n = (int)v.size();
    vector<int> v2 = v;
    int ba = v2.back();
    v2.pop_back();
    if (solve(v2, k-1)) {
        res.push_back(P(ba, -2));
        return true;
    }
    for (int i = 0; i < n-1; i++) {
        if (!iscross(v[i], ba)) continue;
        Q q = cross(v[i], ba);
        vector<int> v2;
        for (int j = 0; j < n-1; j++) {
            if (!iscross(v[j], ba) || !near(q, cross(v[j], ba))) {
                v2.push_back(v[j]);
            }
        }
        if (solve(v2, k-1)) {
            res.push_back(P(v[i], ba));
            return true;
        }

    }
    return false;
}

typedef unsigned int uint;
uint xor128(void) { 
  static uint x = 123456789;
  static uint y = 362436069;
  static uint z = 521288629;
  static uint w = 88675123; 
  uint t;
 
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}


bool calc(vector<int> v, int k) {
    int n = (int)v.size();
    if (n == 0) return true;
    if (k == 0) return false;
    if (n <= k*k) {
        return solve(v, k);
    }
    while ((clock() - st) * 1000 / CLOCKS_PER_SEC < 1000) {
        if (duration_cast<milliseconds>(system_clock::now() - stc).count() > 1000) break;
        int x, y;
        while (true) {
            x = xor128() % n;
            y = xor128() % n;
            if (x == y) continue;
            break;
        }
        if (!iscross(v[x], v[y])) continue;
        Q q = cross(v[x], v[y]);
        int c = 2;
        for (int i = 0; i < n; i++) {
            if (i == x || i == y) continue;
            if (!iscross(v[x], v[i])) continue;
            if (near(q, cross(v[x], v[i]))) {
                c++;
            }
        }
        if (c > k) {
            res.push_back(P(v[x], v[y]));
            vector<int> v2;
            for (int i = 0; i < n; i++) {
                if (i == x || i == y) continue;
                if (iscross(v[x], v[i]) && near(q, cross(v[x], v[i]))) continue;
                v2.push_back(v[i]);
            }
            return calc(v2, k-1);
        }
    }
    return false;
}

int main() {
    stc = system_clock::now();
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int aa, bb, cc;
        scanf("%d %d %d", &aa, &bb, &cc);
        a[i] = aa; b[i] = bb; c[i] = cc;
    }

    st = clock();
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    if (calc(v, k)) {
        printf("YES\n");
        printf("%d\n", (int)res.size());
        for (P p: res) {
            printf("%d %d\n", p.first+1, p.second+1);
        }
    } else {
        printf("NO\n");
    }
    return 0;
}