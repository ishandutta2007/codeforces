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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

struct Card {
    int a, b, c, d; 
    int id;
    void read() {
        scanf("%d%d%d%d", &a, &b, &c, &d);
    }
};


int n;
Card a[N];
vector < Card > data[N * 8];
int cur[N * 8];
int dist[N];
int p[N];
queue < int > q;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].read();
        a[i].id = i;
    }
}

bool cmpA(const Card & x, const Card & y) {
    return x.a < y.a;
}

bool cmpB(const Card & x, const Card & y) {
    return x.b < y.b;
}

bool cmpId(const Card & x, const Card & y) {
    return x.id < y.id;
}

void build(int v, int l, int r, int ll, int rr) {
    for (int i = ll; i < rr; i++)
        data[v].pb(a[i]); 
    sort(data[v].begin(), data[v].end(), cmpB);

    if (l + 1 == r) 
        return;
    int mid = (l + r) / 2;
    Card search;
    search.a = mid;
    int pos = lower_bound(a + ll, a + rr, search, cmpA) - a;
    build(v * 2 + 1, l, mid, ll, pos);
    build(v * 2 + 2, mid, r, pos, rr);
}

void go(int v, int ll, int rr, int x, int y, int me) {
    if (rr <= x + 1) {
        Card search;
        search.b = y;
        int pos = upper_bound(data[v].begin(), data[v].end(), search, cmpB) - data[v].begin();
        for (; cur[v] < pos; cur[v]++) {
            int id = data[v][cur[v]].id;
            if (dist[id] > dist[me] + 1) {
                dist[id] = dist[me] + 1; 
                p[id] = me;
                q.push(id);
            }
        }
        return;
    }
    if (x < ll) return;
    go(v * 2 + 1, ll, (ll + rr) / 2, x, y, me);
    go(v * 2 + 2, (ll + rr) / 2, rr, x, y, me);
}

void solve() {
    vector < int > xx;
    vector < int > yy;
    xx.pb(0);
    yy.pb(0);
    for (int i = 0; i < n; i++) {
        xx.pb(a[i].a);
        yy.pb(a[i].b);
        xx.pb(a[i].c);
        yy.pb(a[i].d);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());
    
    for (int i = 0; i < n; i++) {
        a[i].a = lower_bound(xx.begin(), xx.end(), a[i].a) - xx.begin();
        a[i].c = lower_bound(xx.begin(), xx.end(), a[i].c) - xx.begin();

        a[i].b = lower_bound(yy.begin(), yy.end(), a[i].b) - yy.begin();
        a[i].d = lower_bound(yy.begin(), yy.end(), a[i].d) - yy.begin();
    }
    
    sort(a, a + n, cmpA);
    int mxX = xx.size() + 1;
    build(0, 0, mxX, 0, n);


    sort(a, a + n, cmpId);  
    memset(dist, 63, sizeof(dist));
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++) {
        if (a[i].a == 0 && a[i].b == 0) {
            dist[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        go(0, 0, mxX, a[v].c, a[v].d, v);
    }
    //for (int i = 0; i < n; i++)
        //cerr << dist[i] << " ";
    //cerr << endl;
    if (dist[n - 1] > INF) {
        puts("-1");
        return;
    }
    vector < int > path;
    int v = n - 1;
    for (; v != -1; ) {
        path.pb(v);
        v = p[v];
    }
    reverse(path.begin(), path.end());
    //db2(path.size(), dist[n - 1]); 
    assert((int)path.size() == dist[n - 1]);
    printf("%d\n", (int)path.size());
    for (auto x: path)
        printf("%d ", x + 1);
    puts("");
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
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
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