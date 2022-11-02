#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define y1 botva23
#define getline botva47
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

struct point {
    ld x, y;
    point (){};
    point (ld X, ld Y) {
        x = X;
        y = Y;
    }
};

struct line {
    ld a, b, c;
};

line getline(point a, point b) {
    line res;
    res.a = b.y - a.y;
    res.b = a.x - b.x;
    res.c = b.x * a.y - a.x * b.y;
    return res;
}

ld dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int dist2(line l, point a) {
    if (l.a * a.x + l.b * a.y + l.c < 0)
        return -1;
    else if (l.a * a.x + l.b * a.y + l.c == 0)
        return 0;
    else return 1;
}

bool onsegm(point a, point b, point c){
    point x = a;
    point y = b;
    if (min(x.x, y.x) <= c.x && min(x.y, y.y) <= c.y && c.x <= max(y.x, x.x) && c.y <= max(y.y, x.y))
        return true;
    else return false;
}

ld vectprod(point a, point b) {
    return a.x * b.y - b.x * a.y;
}

ld scalprod(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

bool in_triangle(point a, point b, point c, point d) {
    bool f = true;
    if (abs(dist2(getline(a, b), c) - dist2(getline(a, b), d)) == 2)
        f = false;
    if (abs(dist2(getline(c, b), a) - dist2(getline(c, b), d)) == 2)
        f = false;
    if (abs(dist2(getline(a, c), b) - dist2(getline(a, c), d)) == 2)
        f = false;
    return f;
}

point a[201000];
point c;
int n;
ld alph[201000];

void build() {
    c.x = 0;
    c.y = 0;
    for (int i = 0; i < n; ++i) {
        c.x += a[i].x;
        c.y += a[i].y;
    }
    c.x /= ld(n);
    c.y /= ld(n);
    for (int i = 0; i <= n; ++i)
        alph[i] = atan2(vectprod(point(a[0].x - c.x, a[0].y - c.y), point(a[i].x - c.x, a[i].y - c.y)), 
                        scalprod(point(a[0].x - c.x, a[0].y - c.y), point(a[i].x - c.x, a[i].y - c.y))); 
    for (int i = 0; i <= n; ++i)
        if (alph[i] < 0)
            alph[i] += 2 * acos(ld(-1));
}

void printerr() {
    cout << "NO\n";
    exit(0);
}

void solve(point p) {
    ld tek = atan2(vectprod(point(a[0].x - c.x, a[0].y - c.y), point(p.x - c.x, p.y - c.y)), 
                   scalprod(point(a[0].x - c.x, a[0].y - c.y), point(p.x - c.x, p.y - c.y)));
    if (tek < 0)
        tek += 2 * acos(ld(-1));
    int l = 0;
    int r = n - 1;
    while (r - l > 2) {
        int m = (l + r) / 2;
        if (alph[m] > tek)
            r = m - 1;
        else l = m;
    }
    int sec;
    for (int i = r; i >= l; --i)
        if (alph[i] <= tek) {
            sec = i;
            break;
        }

    line L = getline(a[sec], a[sec + 1]);
    if (abs(L.a * p.x + L.b * p.y + L.c) == 0) 
        printerr();

    if (in_triangle(c, a[sec], a[sec + 1], p)) 
        return ;
    printerr();
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        a[i].x = ld(x);
        a[i].y = ld(y);
    }
    ld s = 0;
    a[n] = a[0];
    for (int i = 0; i < n; ++i)
        s += 0.5 * (a[i].y + a[i + 1].y) * (a[i + 1].x - a[i].x);
    
    if (s > 0) 
        reverse(a, a + n);

    a[n] = a[0];
    build();

    int k;
    scanf("%d ", &k);
    for (int i = 0; i < k; ++i) {
        point t;
        int x, y;
        scanf("%d %d", &x, &y);
        t.x = x;
        t.y = y;
        solve(t);
    }
    cout << "YES\n";
    return 0;
}