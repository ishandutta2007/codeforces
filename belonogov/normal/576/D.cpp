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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 155;
const int INF = 1e9 + 19;
const int SZ = N * N;

int n, m;
vector < pair < int, int > > e[N];
int dp[SZ][N];
int dpCur;

int getNew() {
    int r = dpCur;
    memset(dp[r], 0, sizeof(dp[r]));
    dpCur = (dpCur + 1) % SZ; 
    return r;
}

int getPrev(int pos, int shift) {
    return (pos + SZ - shift) % SZ;
}

int getLast() {
    return (dpCur - 1 + SZ) % SZ;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, d;
        scanf("%d%d%d", &v, &u, &d); v--; u--;
        e[v].pb(mp(u, d));
    }
}

int solve() {
    int step = n * n + 1;
    vector < pair < int, int > > event;
    for (int v = 0; v < n; v++)
        for (auto x: e[v]) {
            event.pb(mp(x.sc, 1));
            event.pb(mp(x.sc + step, - 1));
        }
    event.pb(mp(0, 1));
    event.pb(mp(step, -1)); 
    sort(event.begin(), event.end()); 
    vector < pair < int, int > > seg;
    int b = 0;
    int last = -1;
    for (int i = 0; i < (int)event.size(); ) {
        int j = i;
        for (; i < (int)event.size() && event[i].fr == event[j].fr; i++)
            b += event[i].sc;
        if (b > 0 && last == -1) {
            last = event[j].fr;
        }
        if (b == 0) {
            assert(last != -1);
            seg.pb(mp(last, event[j].fr));
            last = -1;
        }
    }
    //for (auto x: seg)
        //db2(x.fr, x.sc);
   
    //cerr << endl;
    for (int t = 0; t < (int)seg.size(); t++) {
        int l = seg[t].fr;
        int r = seg[t].sc;
        //db2(l, r);
        int id;
        if (t == 0) {
            id = getNew();
            dp[id][0] = 1;
        }
        else {
            assert(l > step);
            last = getLast();
            id = getNew();
            //for (int i = 0; i <= n; i++, cerr << endl) {
                //int g = getPrev(last, i);
                //for (int v = 0; v < n; v++) {
                    //cerr << dp[g][v] << " ";
                //}
            //}
                    


            for (int v = 0; v < n; v++) {
                //db(v);
                int tmp = -1;
                int step = -1;
                for (int i = 0; i <= n * 2; i++) {
                    int curId = getPrev(last, i);
                    if (dp[curId][v]) {
                        if (tmp == -1)
                            tmp = i;
                        else {
                            step = i - tmp;
                            break;
                        }
                    } 
                }
                if (step == -1)
                    assert(tmp == -1);
                else {
                    int lastR = seg[t - 1].sc;
                    int dist = l - lastR;
                    int shift = (dist - 1 + step) / step * step;
                    int innerShift = shift - dist;
                    assert(innerShift >= 0);
                    int tmpId = getPrev(last, innerShift);
                    dp[id][v] = dp[tmpId][v];
                } 

            }
        }

        //db2(l, r);
        for (int i = l; i < r; i++) {
            int next = getNew();
            for (int v = 0; v < n; v++)
                if (dp[id][v])
                    for (auto x: e[v])
                        if (x.sc <= i)
                            dp[next][x.fr] = 1; 
            id = next;
            if (dp[id][n - 1]) {
                //printf("%d\n", i + 1);
                return i + 1;
            }
        }
        
    }
    //puts("Impossible");
    return -1;
}

void printAns(int r) {
    if (r != -1)
        printf("%d\n", r);
    else
        puts("Impossible");
}

void genTest() {
    dpCur = 0;
    n = 2 + rand() % 3;
    m = 1 + rand() % 10;
    for (int i = 0; i < n; i++)
        e[i].clear();

    int T1 = 1000;
    int T2 = 5;
    for (int i = 0; i < m; i++) {
        int v = rand() % n;
        int u = rand() % n;
        int d; 
        if (rand() % 2)
            d = rand() % T1;
        else
            d = rand() % T2;
        e[v].pb(mp(u, d));
    }
}

int stupid() {
    int mx = 0;
    for (int v = 0; v < n; v++)
        for (auto x: e[v])
            mx = max(mx, x.sc);

    mx += n + 1;
    //db(mx);
    vector < vector < int > > dp(mx, vector < int > (n)); 
    dp[0][0] = 1;
    for (int i = 0; i < mx - 1; i++) {
        for (int v = 0; v < n; v++)
            for (auto x: e[v])
                if (i >= x.sc)
                    dp[i + 1][x.fr] |= dp[i][v];
        if (dp[i + 1][n - 1])
            return i + 1;
    }
    return -1;
}

void printTest() {
    cerr << endl;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
        for (auto x: e[i]) 
            cerr << i + 1 << " " << x.fr + 1 << " " << x.sc << endl;
}


void stress() {
    for (int tt = 0; ; tt++) {
        if (tt % 100 == 0)
            cerr << "test id: " << tt << endl;
        genTest();
        if (tt >= 24000)
            printTest();
        int r1 = solve();
        int r2 = stupid();
        if (r1 > 100)
            db(r1);
            //db2(r1, r2);
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
            //printAns(stupid());
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}