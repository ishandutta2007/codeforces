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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
const int INF = 1e9;

struct Tree {
    struct Node {
        pair < int, int > res;   // r - l - id  min
        pair < int, int > mnl; //  - l - id    min
        pair < int, int > mnr; // r - id   min
        int updl;
        int updr;
    };

    vector < Node > data;
    int sz;
    void init(int n) {
        sz = n;
        data.resize(sz * 4);
        for (int i = 0; i < sz * 4; i++) {
            data[i].res = mp(INF, -1);
            data[i].mnl = mp(INF, -1);
            data[i].mnr = mp(INF, -1);
            data[i].updl = data[i].updr = -1;
        }
    }

    void apply(int v, int rr, int value, int type) {
        if (type == 1) {
            data[v].updl = value;
            data[v].mnl = mp(-value - (rr - 1), 1);
            data[v].res = data[v].mnr;
            data[v].res.fr -= value;
        }
        else if (type == 2) {
            data[v].updr = value;
            data[v].mnr = mp(value - (rr - 1), 1);
            data[v].res = data[v].mnl;
            data[v].res.fr += value;
        }
        else
            assert(false);
    }
    
    void push(int v, int ll, int rr) {
        if (data[v].updl != -1) {
            apply(v * 2 + 1, (ll + rr) / 2, data[v].updl, 1);
            apply(v * 2 + 2, rr, data[v].updl, 1);
            data[v].updl = -1;
        } 
        if (data[v].updr != -1) {
            apply(v * 2 + 1, (ll + rr) / 2, data[v].updr, 2);
            apply(v * 2 + 2, rr, data[v].updr, 2);
            data[v].updr = -1;
        }
    }

    Node merge(Node r1, Node r2) {
        Node g;
        g.updl = g.updr = -1;
        pair < int, int > res;
        pair < int, int > mnl;
        pair < int, int > mnr;
        res = mp(min(r1.res.fr, r2.res.fr), 0);
        if (res.fr == r1.res.fr) res.sc += r1.res.sc;
        if (res.fr == r2.res.fr) res.sc += r2.res.sc;

        mnl = mp(min(r1.mnl.fr, r2.mnl.fr), 0);
        if (mnl.fr == r1.mnl.fr) mnl.sc += r1.mnl.sc;
        if (mnl.fr == r2.mnl.fr) mnl.sc += r2.mnl.sc;

        mnr = mp(min(r1.mnr.fr, r2.mnr.fr), 0);
        if (mnr.fr == r1.mnr.fr) mnr.sc += r1.mnr.sc;
        if (mnr.fr == r2.mnr.fr) mnr.sc += r2.mnr.sc;

        g.res = res;
        g.mnl = mnl;
        g.mnr = mnr; 
        return g;
    }

    void set(int v, int ll, int rr, int l, int r, int value, int type) {
        if (r <= ll || rr <= l) return; 
        if (l <= ll && rr <= r) {
            apply(v, rr, value, type);
            return;
        }
        push(v, ll, rr);
        set(v * 2 + 1, ll, (ll + rr) / 2, l, r, value, type);
        set(v * 2 + 2, (ll + rr) / 2, rr, l, r, value, type);
        data[v] = merge(data[v * 2 + 1], data[v * 2 + 2]); 
    }

    void set(int l, int r, int value, int type) { // type == 1 - l     /// type == 2 -- r
        set(0, 0, sz, l, r, value, type);
    }
};

int n;
int a[N];
Tree t;


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        a[x] = y;
    }
}

void solve() {
    t.init(n);
    vector < pair < int, int > > stackL;
    vector < pair < int, int > > stackR;
    stackL.pb(mp(-1, n));
    stackR.pb(mp(n, n));
    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        int h = a[i];
        for (; !stackL.empty() && h < stackL.back().fr; stackL.pop_back());
        assert(!stackL.empty());
        t.set(i, stackL.back().sc, h, 1);
        stackL.pb(mp(h, i));

        for (; !stackR.empty() && h > stackR.back().fr; stackR.pop_back());
        assert(!stackR.empty()); 
        t.set(i, stackR.back().sc, h, 2); 
        stackR.pb(mp(h, i));

        auto r = t.data[0].res;
        assert(r.fr >= -i);
        if (r.fr == -i)
            answer += r.sc;
    }
    cout << answer << endl;
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        for (int tt = 0; tt < 1; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}