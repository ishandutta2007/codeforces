#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 200500;

int N; ll S;
struct cookie {
    ll v, c;
    cookie (ll v = 0, ll c = 0): v(v), c(c) { }
};

cookie cookies[N_];

struct line {
    ll a, b; 
    ll s;
    line (ll a = 0, ll b = 0, ll s = 0): a(a), b(b), s(s) { }
    ll y() { return a * s + b; }
    ll y(ll x) { return a * x + b; }
};

vector<line> hull;

ll ceilDivision (ll p, ll q) {
    return (p + q - 1) / q;
}

int main() {
    scanf("%d%lld", &N, &S);
    for(int i = 1; i <= N; i++) {
        cookie &p = cookies[i];
        scanf("%lld%lld", &p.v, &p.c);
    }

    sort(cookies + 1, cookies + N + 1, [](const cookie &p, const cookie &q) {
        return p.c != q.c ? p.c < q.c : p.v > q.v;
    });

    cookies[N+1] = cookie((ll)1e9, S);

    hull.push_back(line(cookies[1].v, 0));
    for(int i = 2; i <= N+1; i++) {
        cookie &cookie = cookies[i];
        if(hull.back().a >= cookie.v) continue;

        int low = 0, high = (int)hull.size() - 1, pos = (int)hull.size() - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            lf maxy = hull[mid].y(hull[mid+1].s - 1);
            if(maxy >= cookie.c)
                high = mid - 1, pos = mid;
            else
                low = mid + 1;
        }

        ll t0 = ceilDivision(cookie.c - hull[pos].b, hull[pos].a);
        if(i == N+1) return 0 & printf("%lld\n", t0);

        ll y0 = hull[pos].y(t0) - cookie.c;
        line newLine = line(cookie.v, y0 - cookie.v * t0);

        while(!hull.empty() && hull.back().s >= t0 && hull.back().y() <= newLine.y(hull.back().s))
            hull.pop_back();

        if(hull.back().a < newLine.a) {
            newLine.s = ceilDivision(hull.back().b - newLine.b, newLine.a - hull.back().a);
            hull.push_back(newLine);
        }
    }

    return 0;
}