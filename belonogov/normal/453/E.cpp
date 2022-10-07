#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 2e6 + 1000;
const int INF = 1e9;
const double eps7 = 1e-7;

struct pony {
    int val, mx, r, t;
};

struct query {
    int t, l, r;
};

struct state {
    double t, val, speed;
    state() { }
    state(double t, double val, double speed): t(t), val(val), speed(speed) { }
};

struct blockState {
    int type; /// 1 - use /// 0 - clear
    int t;
    int l, r;
    vector < state > e;
};

int n, m;
pony a[N];
vector < query > b;
blockState c[N];
vector < long long > answer;
int SZ;
int cntBlocks;

void read() {
    if (scanf("%d", &n) != 1) exit(0);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].val, &a[i].mx, &a[i].r);
        a[i].t = 0;
    }
    scanf("%d", &m);
    b.clear();
    for (int i = 0; i < m; i++) {
        query tmp;
        scanf("%d%d%d", &tmp.t, &tmp.l, &tmp.r);
        tmp.l--;
        b.pb(tmp);
    }
}

bool cmpT(state a, state b) {
    return a.t < b.t;
}

void solve() {
    answer.clear();
    SZ = sqrt(n * 2);
    cntBlocks = (n + SZ - 1) / SZ;
    for (int i = 0; i < cntBlocks; i++) {
        c[i].l = i * SZ;
        c[i].r = min((i + 1) * SZ, n);
        c[i].type = 1;
        double speed = 0;
        c[i].e.clear();
        for (int j = c[i].l; j < c[i].r; j++) {
            speed += a[j].r;
            double tmr = INF;
            if (a[j].r != 0)
                tmr = a[j].mx * 1.0 / a[j].r;
            c[i].e.pb(state(tmr, 0, a[j].r));
        }
        c[i].e.pb(state(0, 0, 0));
        sort(c[i].e.begin(), c[i].e.end(), cmpT);
        double sum = 0;
        double last = 0;
        for (int j = 0; j < (int)c[i].e.size(); j++) {
            sum += (c[i].e[j].t - last) * speed;
            last = c[i].e[j].t;
            c[i].e[j].val = sum;
            speed -= c[i].e[j].speed;
            c[i].e[j].speed = speed;
        }
    }
    for (int i = 0; i < m; i++) {
        long long ans = 0;
        for (int j = b[i].l; j < b[i].r; ) {
            int blockId = j / SZ;
            if (j % SZ == 0 && j + SZ <= b[i].r && c[blockId].type == 0) {
                int dt = b[i].t - c[blockId].t;
                //for (int tt = 0; tt <  (int)c[blockId].e.size() - 1; tt++)
                    //assert(!cmpT(c[blockId].e[tt + 1], c[blockId].e[tt]));
                int pos = upper_bound(c[blockId].e.begin(), c[blockId].e.end(), state(dt, 0, 0), cmpT)
                     - c[blockId].e.begin();
                pos--;
                //int myPos = c[blockId].e.size();
                //for (; myPos > 0 && c[blockId].e[myPos - 1].t > dt; myPos--);
                //myPos--;
//...............................................................................
//...............................................................................
//...............................................................................
                //for (int tt = 0; tt < (int)c[blockId].e.size() - 1; tt++)
                    //assert(!(c[blockId].e[tt + 1].t < c[blockId].e[tt].t));
                //for (int tt = 0; tt < (int)c[blockId].e.size() - 1; tt++)
                    //if (!(c[blockId].e[tt + 1].t >= c[blockId].e[tt].t)) {
                        ////assert(false);
                        //cout << c[blockId].e[tt + 1].t << endl;
                        //cout << c[blockId].e[tt].t << endl;
                        //exit(0);
                    //}

//                for (int tt = 0; tt < (int)c[blockId].e.size() - 1; tt++)
  //                  assert(c[blockId].e[tt].t <= c[blockId].e[tt + 1].t);
//.............................................................................
//.............................................................................
//.............................................................................

                //assert(pos == myPos);

                assert(pos >= 0);
                assert(pos + 1 == (int)c[blockId].e.size() || dt < c[blockId].e[pos + 1].t);
                //assert(c[blockId].e[pos].t <= dt + 1000);
                double dx = c[blockId].e[pos].val;
                //assert(dt - c[blockId].e[pos].t >= 0);
                if (pos < (int)c[blockId].e.size())
                    dx += (dt - c[blockId].e[pos].t) * c[blockId].e[pos].speed;
                ans += dx + eps7;
                c[blockId].t = b[i].t;
                j += SZ;
                continue;
            }
            if (j % SZ == 0 && j + SZ <= b[i].r) {
                for (int k = j; k < j + SZ; k++) {
                    ans += min(a[k].r * 1ll * (b[i].t - a[k].t) + a[k].val, a[k].mx * 1ll);
                    a[k].val = 0;
                }
                c[blockId].t = b[i].t;
                c[blockId].type = 0;
                j += SZ;
                continue;
            }
            if (c[blockId].type == 0) {
                for (int j = c[blockId].l; j < c[blockId].r; j++) {
                    a[j].t = c[blockId].t;
                    a[j].val = 0;
                }
                c[blockId].type = 1;
            }
            ans += min(a[j].r * 1ll * (b[i].t - a[j].t) + a[j].val, a[j].mx * 1ll);
            a[j].val = 0;
            a[j].t = b[i].t;
            j++;
        }
        answer.pb(ans);
    }

}


void printAns() {
  //  cerr << "sdfdd\n";
    //cerr << answer.size() << endl;
    for (auto x: answer)
        printf("%lld\n", x);
    printf("\n");
}

void stress() {

}


int main(){
//freopen("in", "r", stdin);
#ifdef DEBUG
    //freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
   // freopen("out", "w", stdout);
#endif

    //
    //freopen("in", "r", stdin);
    //cerr << "sdf\n";
    if (1) {
        while (true) {
            read();
    //        cerr << "sdf\n";
            solve();
            printAns();
            //return 0;
            cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}