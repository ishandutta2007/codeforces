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
const int N = 1e5;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;
const long long p = 1e7 + 19;
const int K = 1111;

struct Query {
    int type, c, w, id;
    Query() { }
    Query(int type, int c, int w, int id): type(type), c(c), w(w), id(id) { }
};

struct Item {
    int w, c;
    Item() { }
    Item(int w, int c): w(w), c(c) { }
};


int n, k;
int when[N];
vector < Query > q;
vector < Item > data[N * 2];
int answer[N];
int cur;
int dp[K];


void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int c, w;
        scanf("%d%d", &c, &w);
        q.pb(Query(1, c, w, i));
    }
    int cnt = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int type;
        scanf("%d", &type);
        if (type == 3)
            q.pb(Query(3, -1, -1, cur++));
        else if (type == 1) {
            int c, w;
            scanf("%d%d", &c, &w);
            q.pb(Query(1, c, w, n));
            n++;
        }
        else if (type == 2) {
            int id;
            scanf("%d", &id);
            id--;
            q.pb(Query(2, -1, -1, id));
        }
    }
}

void add(int v, int ll, int rr, int l, int r, Item item) {
    if (l >= rr || ll >= r) return;
    if (l <= ll && rr <= r) {
        data[v].pb(item);
        return;
    }
    add(v * 2 + 1, ll, (ll + rr) / 2, l, r, item);
    add(v * 2 + 2, (ll + rr) / 2, rr, l, r, item);
}


void go(int v, int ll, int rr) {
    //db(v);
    vector < int > tmp(k + 1);
    for (int i = 0; i <= k; i++)
        tmp[i] = dp[i];
    for (auto x: data[v]) {
        //db2(x.w, x.c);
        for (int j = k - x.w; j >= 0; j--)
            dp[j + x.w] = max(dp[j + x.w], dp[j] + x.c);
    }

    if (ll + 1 == rr) {
        if (q[ll].type == 3) {
            //for (int i = 0; i <= k; i++)
                //cerr << dp[i] << " ";
            //cerr << endl;
            int pp = 1;
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                sum = (sum + dp[i] * 1ll * pp) % MOD;
                pp = (pp * 1ll * p) % MOD;
            }
            answer[q[ll].id] = sum; 
        }
        for (int i = 0; i <= k; i++)
            dp[i] = tmp[i];
        return;
    }
    go(v * 2 + 1, ll, (ll + rr) / 2);
    go(v * 2 + 2, (ll + rr) / 2, rr);

    for (int i = 0; i <= k; i++)
        dp[i] = tmp[i];

}

void solve() {
    set < int > g;
    for (auto x: q) {
        if (x.type == 1) 
            g.insert(x.id);
        if (x.type == 2) {
            assert(g.count(x.id));
            g.erase(x.id);
        }
    }
    for (auto x: g)
        q.pb(Query(2, -1, -1, x));

    for (int i = 0; i < (int)q.size(); i++) {
        if (q[i].type == 1) 
            when[q[i].id] = i;
        if (q[i].type == 2) {
            int l = when[q[i].id];
            int r = i;
            add(0, 0, q.size(), l, r, Item(q[l].w, q[l].c));
        }
    }

    //for (int i = 0; i < 20; i++)
        //cerr << data[i].size() << endl;

    go(0, 0, q.size());
    

    for (int i = 0; i < cur; i++)
        printf("%d\n", answer[i]);



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