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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
const long long INF = 1e9 + 19;
const double pi = acos(-1);

struct pnt {
    double x, y;
    pnt () { }
    pnt (double x, double y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    double operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    pnt operator * (double k) {
        return pnt(x * k, y * k);
    }
    double operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    pnt rotate(double alf) {
        return pnt(x * cos(alf) - y * sin(alf),  sin(alf) * x + cos(alf) * y);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
};


int n, m;

pair < pnt, int > data[N * 4];

double toRad(int x) {
    return -x / 180.0 * pi;
}

pair < pnt, int > merge( pair < pnt, int > left,  pair < pnt, int > right) {
    pnt v = left.fr + right.fr.rotate(toRad(left.sc)); 
    int ang = left.sc + right.sc;
    return mp(v, ang);
}

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        data[v] = mp(pnt(1, 0), 0);
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    data[v] = merge(data[v * 2 + 1], data[v * 2 + 2]);
}

 pair < pnt, int > get(int v, int ll, int rr, int l, int r) {
    if (ll >= r || l >= rr) 
        return mp(pnt(0, 0), 0);
    if (l <= ll && rr <= r) 
        return data[v];
    return merge(get(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                 get(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}

void update(int v, int ll, int rr, int id, int type, int val) {
    if (id < ll) return;
    if (id >= rr) return;
    if (ll + 1 == rr) {
        if (type == 1) {
            double len = data[v].fr.len();
            data[v].fr = data[v].fr * ((val + len) / len);
        }
        else {
            double ang = toRad(val);
            data[v].fr = data[v].fr.rotate(ang);
            data[v].sc += val;
        }
        return;
    }
    update(v * 2 + 1, ll, (ll + rr) / 2, id, type, val);
    update(v * 2 + 2, (ll + rr) / 2, rr, id, type, val);
    data[v] = merge(data[v * 2 + 1], data[v * 2 + 2]);

}

void read() {
    scanf("%d%d", &n, &m);
}

void solve() {
    build(0, 0, n);
    //db(get(0, 0, n, 0, 1).fr.len());
    //db(get(0, 0, n, 0, 3).fr.len());
    for (int i = 0; i < m; i++) {
        int type, id, val;
        scanf("%d%d%d", &type, &id, &val); id--;
        update(0, 0, n, id, type, val);
        
        printf("%.17f %.17f\n", data[0].fr.x, data[0].fr.y);
    }

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}