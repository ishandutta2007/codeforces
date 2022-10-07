#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define stack stackkk

const int N = 1e6 + 10;
const int INF = 1e9 + 19;

struct pnt {
    long long x, y;
    int type;
    pnt() { }
    pnt(long long x, long long y): x(x), y(y) { }
    pnt(long long x, long long y, int type): x(x), y(y), type(type) { }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    long long operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    long long len2() {
        return x * x + y * y;
    }
    void read() {
        scanf("%I64d%I64d", &x, &y);
    }
};


pnt _O;
vector < pnt > p; 
int n, m;
map < pair < int, int >, int > q;
int cur;
pnt stack[N];

void read() {
    scanf("%d%d", &n, &m);
    _O.read();
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        q[mp(x, y)] |= 1; 
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        q[mp(x, y)] |= 2;
    }
}

bool cmp(pnt A, pnt B) {
    A = A - p[0];
    B = B - p[0]; 
    return A * B > 0 || (A * B == 0 && A.len2() < B.len2());
}

void convexHull() {
    int sz = p.size();
    for (int i = 0; i < sz; i++)
        if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
            swap(p[i], p[0]);
    sort(p.begin() + 1, p.end(), cmp);
    for (int i = 0; i < sz; i++) {
        for (; cur >= 2 && (stack[cur - 1] - stack[cur - 2]) * (p[i] - stack[cur - 1]) < 0; cur--);
        stack[cur++] = p[i];
    }
}

void solve() {
    for (auto x: q) {
        p.pb(pnt(x.fr.fr, x.fr.sc, x.sc));
    }
    p.pb(pnt(0, 0, 0));

    convexHull();

    int st = 0;
    int fn = 0;
    for (int i = 0; i < cur; i++) {
        if (stack[i].x > stack[st].x || (stack[i].x == stack[st].x && stack[i].y < stack[st].y))
            st = i;
        if (stack[i].y > stack[fn].y || (stack[i].y == stack[fn].y && stack[i].x < stack[fn].x))
            fn = i;
    }
     
    assert(0 < st);
    assert(st <= fn);
    for (int i = st; i <= fn; i++) {
        assert(stack[i].type != 0);
        if (stack[i].type & 1) {
            cout << "Max\n";
            return;
        }
    }

    cout << "Min\n";

}

void stress() {

}


int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
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