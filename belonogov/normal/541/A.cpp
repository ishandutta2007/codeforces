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

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;

struct Seg {
    int l, r, c, id;
    int zl, zr;
    Seg() { }
    Seg(int l, int r, int c, int id):l(l), r(r), c(c), id(id) { }
};

struct event {
    int type, t;
    Seg s;
    event() { }
    event(int type, int t, Seg s): type(type), t(t), s(s) { } 
};

struct ForZip {
    int t, id, type;
    ForZip() { }
    ForZip(int t, int id, int type): t(t), id(id), type(type) { }
};

struct Tree {
    vector < pair < int, int > > data;
    int sz;
    Tree(int n) {
        sz = n;
        data.assign(sz * 4, mp(0, -1));
    }
    pair < int, int > getMax(int v, int ll, int rr, int l, int r) {
        if (rr <= l || r <= ll) return mp(0, -1);
        if (l <= ll && rr <= r) return data[v];
        return max(getMax(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                   getMax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
    }
    void set(int v, int ll, int rr, int pos, pair < int, int > val) {
        if (rr <= pos || pos < ll) return;
        if (ll + 1 == rr) {
            data[v] = val;
            return;
        }
        set(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        set(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        data[v] = max(data[v * 2 + 1], data[v * 2 + 2]);
    }
};


int n, m;
Seg a[N];
Seg b[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r); 
        a[i] = Seg(l, r, 1, i);
    }
    for (int i = 0; i < m; i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        b[i] = Seg(l, r, c, i);
    }
}


bool cmpE(const event & a, const event & b) {
    return a.t < b.t || (a.t == b.t && a.type < b.type);
}

bool cmpZ(const ForZip & a, const ForZip & b) {
    if (a.t != b.t) return a.t < b.t;
    if (a.id != b.id) return a.id < b.id;
    return a.type < b.type;
}

long long solve() {
    long long answer = 0;
    int bestA = -1, bestB = -1;

    for (int tt = 0; tt < 2; tt++) {
        //db(answer);
        vector < event > c;
        for (int i = 0; i < m; i++) {
            c.pb(event(1, b[i].r, b[i]));
        }       
        for (int i = 0; i < n; i++) {
            c.pb(event(0, a[i].l, a[i]));
            c.pb(event(2, a[i].r, a[i]));
        }
        sort(c.begin(), c.end(), cmpE);
        set < pair < int, int > > q; // left id

        for (auto x: c) {
            if (x.type == 0) {
                q.insert(mp(x.t, x.s.id));
            }
            if (x.type == 2) {
                int sz = q.size();
                q.erase(mp(x.s.l, x.s.id));
                assert(sz - 1 == (int)q.size());
            }
            if (x.type == 1) {
                if (q.empty()) continue;   
                int l = q.begin()->fr;
                l = max(l, x.s.l); 
                //db(l);
                //db(x.t);
                long long res = (x.t - l) * 1ll * x.s.c;
                if (res > answer) {
                    answer = res;
                    bestA = q.begin()->sc;
                    bestB = x.s.id;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            swap(a[i].l, a[i].r);
            a[i].l *= -1;
            a[i].r *= -1;
        }
        for (int i = 0; i < m; i++) {
            swap(b[i].l, b[i].r);
            b[i].l *= -1;
            b[i].r *= -1;
        }
    }  
    //db(answer);

    vector < ForZip > g;
    for (int i = 0; i < n; i++) {
        g.pb(ForZip(a[i].l, a[i].id, 0));
        g.pb(ForZip(a[i].r, a[i].id, 1));
    }
    
    for (int i = 0; i < m; i++) {
        g.pb(ForZip(b[i].l, b[i].id, 2));
        g.pb(ForZip(b[i].r, b[i].id, 3));
    } 

    sort(g.begin(), g.end(), cmpZ);
    int cur = 0;
    for (auto x: g) {
        if (x.type == 0) a[x.id].zl = cur;
        if (x.type == 1) a[x.id].zr = cur;
        if (x.type == 2) b[x.id].zl = cur;
        if (x.type == 3) b[x.id].zr = cur;
        cur++;
    }

    vector < event > h;
    for (int i = 0; i < n; i++) {
        h.pb(event(1, a[i].zr, a[i]));
    }
    for (int i = 0; i < m; i++) {
        h.pb(event(0, b[i].zl, b[i]));
        h.pb(event(2, b[i].zr, b[i]));
    }

    sort(h.begin(), h.end(), cmpE); 

    Tree t((n + m) * 2 + 3);

    for (auto x: h) {
        if (x.type == 0) {
            t.set(0, 0, t.sz, x.s.zl, mp(x.s.c, x.s.id));
        }
        if (x.type == 1) {
            auto cost = t.getMax(0, 0, t.sz, 0, x.s.zl);
            long long res = cost.fr * 1ll * (x.s.r - x.s.l);
            if (res > answer) {
                answer = res;
                bestA = x.s.id;
                bestB = cost.sc;
            }
        }
        if (x.type == 2) {
            t.set(0, 0, t.sz, x.s.zl, mp(0, -1));
        }
    }
    if (answer > 0) {
        cout << answer << "\n";
        printf("%d %d\n", bestA + 1, bestB + 1);
    }
    else {
        printf("0\n");
    }
    return answer;
}

void printAns() {

}

long long stupid() {
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int l = max(a[i].l, b[j].l);
            int r = min(a[i].r, b[j].r);
            if (l < r)
                res = max(res, (r - l) * 1ll * b[j].c);
        }
    return res;
}

void printTest() {
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", a[i].l, a[i].r);
    for (int i = 0; i < m; i++) 
        printf("%d %d %d\n", b[i].l, b[i].r, b[i].c);
}

void stress() {
    for (int tt = 0; ; tt++) {
        cerr << "test id: " << tt << endl;
        n = 300; 
        m = 10;
        int T = 100000000;
        for (int i = 0; i < n; i++) {
            int l = rand() % T;
            int r = rand() % T;
            if (l > r) swap(l, r);
            a[i] = Seg(l, r, 1, i);
        }
        for (int i = 0; i < m; i++) {
            int l = rand() % T;
            int r = rand() % T;
            int c = rand() % T + 1;
            if (l > r) swap(l, r);
            b[i] = Seg(l, r, c, i);
        }
        long long r1 = solve();
        long long r2 = stupid();
        cerr << "r1 r2: " << r1 << " " << r2 << endl;
        if (r1 != r2) {
            printTest();
        }
        assert(r1 == r2);
    }

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
            //cerr << stupid();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}