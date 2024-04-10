#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define x first
#define y second

const int MAXN = 100005;

int N, P, Q;
pii p[MAXN];
vector <pii> upper, lower, hull;

void load() {
    scanf("%d%d%d", &N, &P, &Q);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
}

ll ccw(pii A, pii B, pii C) {
    return (ll)A.x * (B.y - C.y) + (ll)B.x * (C.y - A.y) + (ll)C.x * (A.y - B.y);
}

void intersect(pii A, pii B) {
    ll num = (ll)P * ((ll)A.y * (B.x - A.x) - (ll)A.x * (B.y - A.y));
    ll denom = (ll)Q * (B.x - A.x) - (ll)P * (B.y - A.y);
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
    if (A.x > B.x) swap(A, B);
    if (num < denom * A.x || num > denom * B.x) 
        return;
    if (A.y > B.y) swap(A, B);
    if ((ld)num * Q < (ld)A.y * denom * P || (ld)num * Q > (ld)B.y * denom * P) 
        return;
    printf("%.15lf\n", (double)P / num * denom);
    exit(0);
}

void solve() {
    sort(p, p + N);
    
    for (int i = 0; i < N; i++) {
        while (upper.size() > 1 && ccw(upper[(int)upper.size() - 2], upper.back(), p[i]) >= 0)
            upper.pop_back();
        upper.push_back(p[i]);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        while (lower.size() > 1 && ccw(lower[(int)lower.size() - 2], lower.back(), p[i]) >= 0)
            lower.pop_back();
        lower.push_back(p[i]);
    }
    
    for (int i = 1; i < upper.size(); i++) 
        hull.push_back(upper[i]);
        
    for (int i = 1; i < lower.size(); i++) 
        hull.push_back(lower[i]);
        
    if (N == 1) hull.push_back(p[0]);
    
    int mx = 0, my = 0;
    for (int i = 0; i < hull.size(); i++) {
        if (hull[i].x > hull[mx].x) mx = i;
        if (hull[i].y > hull[my].y) my = i;
    }
    
    int sz = hull.size();
    for (int i = my; i != mx; i = (i + 1) % sz)
        intersect(hull[i], hull[(i + 1) % sz]);
    intersect(pii(0, hull[my].y), hull[my]);
    intersect(pii(hull[mx].x, 0), hull[mx]);
}

int main() {
    load();
    solve();
    return 0;
}