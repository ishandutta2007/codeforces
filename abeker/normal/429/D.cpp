#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN = 100005; 

typedef long long ll;

struct bla {
    int x, y, z;
    bla(int _x, int _y, int _z = 0) { x = _x; y = _y; z = _z; }
    bla(){}
};

typedef vector <bla> vec;
 
bool cmpx(const bla &lhs, const bla &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

bool cmpy(const bla &lhs, const bla &rhs) {
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    return lhs.x < rhs.x;
}

int N;
bla a[MAXN];
int c, sum;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { 
        scanf("%d", &c);
        sum += c;
        a[i] = bla(sum, i + 1, i);
    }
}

inline ll square(int x) { return (ll)x * (ll)x; }

inline ll dist(bla p, bla q) { return square(p.x - q.x) + square(p.y - q.y); }

void finish(int x) { if (!x) printf("FAREWELL %d\n", 42 / x); }

ll brute(vec &p) {
    //finish(p.size());
    if (p.size() < 2) return 2 * (ll)(1e18) - 1;
    ll res = dist(p[0], p[1]); 
    for (int i = 0; i < p.size(); i++) 
        for (int j = 0; j < i; j++) 
            res = min(res, dist(p[i], p[j]));
    return res;
}

bool le[MAXN];

ll rec(vec &px, vec &py) {
    ///finish(px.size());
    if (px.size() < 4) 
        return brute(px);
    for (int i = 0; i < px.size(); i++) 
        le[px[i].z] = false;
    int mid = (int)px.size() / 2;
    vec plx, ply, prx, pry, strip;
    for (int i = 0; i < px.size(); i++) 
        if (i < mid) { 
            le[px[i].z] = true; 
            plx.push_back(px[i]); 
        }
        else prx.push_back(px[i]);
    //finish(mid);
    //finish(plx.size());
    //finish(prx.size());
    for (int i = 0; i < py.size(); i++) 
        if (le[py[i].z]) ply.push_back(py[i]);
        else pry.push_back(py[i]);
    ll dm = min(rec(plx, ply), rec(prx, pry));
    for (int i = 0; i < py.size(); i++) 
        if (square(abs(px[mid].x - py[i].x)) < dm)
            strip.push_back(py[i]);
    for (int i = 0; i < strip.size(); i++) 
        for (int j = i + 1; j < strip.size() && square(strip[j].y - strip[i].y) < dm; j++)
            dm = min(dm, dist(strip[i], strip[j]));
    return dm;
}

ll solve() {
    vec sx, sy;
    for (int i = 0; i < N; i++) {
        sx.push_back(a[i]);
        sy.push_back(a[i]);
    }
    sort(sx.begin(), sx.end(), cmpx);
    sort(sy.begin(), sy.end(), cmpy);
    finish(sx.size());
    return rec(sx, sy);
}

int main() {
    load();
    cout << solve() << endl;
    return 0;
}