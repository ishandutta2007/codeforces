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
#include <unordered_set>
#include <unordered_map>
#include <stack>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 3e5 + 10;
const int INF = 1e9;

struct Tree {
    vector < int > data;
    int sz;
    Tree() { }
    Tree(int n) {
        sz = n;
        data.resize(n * 4);
    }
    void add(int v, int ll, int rr, int pos, int val) {
        if (pos + 1 <= ll || rr <= pos) return;
        if (ll + 1 == rr) {
            data[v] = val;
            return;
        }
        add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        data[v] = data[v * 2 + 1] + data[v * 2 + 2];
    }

    void add(int pos, int val) {
        //cerr << "pos val: " << pos << " " << val << endl;
        add(0, 0, sz, pos, val);
    }

    int get(int v, int ll, int rr, int l, int r) {
        if (rr <= l || r <= ll) return 0;
        if (l <= ll && rr <= r) return data[v];
        return get(v * 2 + 1, ll, (ll + rr) / 2, l, r) +
                get(v * 2 + 2, (ll + rr) / 2, rr, l, r);
    }

    int get(int l, int r) {
        //cerr << "l r: " << l << " " << r << endl;
        return get(0, 0, sz, l, r);
    }
};

struct Query {
    int t, r, id;
    Query() { }
    Query(int t, int r, int id): t(t), r(r), id(id) { }
};

int n, m;
int p[N];
int l[N];
int answer[N];
stack < int > q;
vector < Query > b;
int x[N];
int y[N];
int who[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i], &l[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x[i], &y[i]);
        x[i]--;
    }
}

bool cmp(Query a, Query b) {
    return a.t > b.t;
}

void solve() {
    memset(who, -1, sizeof(who));
    for (int i = 0; i < m; i++)
       b.pb(Query(x[i], y[i], i)); 
    sort(b.begin(), b.end(), cmp);
    Tree t(n + 2);
    int curQuery = 0;
    for (int i = n - 1; i >= 0; i--) {
        //cerr << "current: p l " << p[i] << " " << l[i] << endl;
        for (; !q.empty() && p[i] + l[i] >= p[q.top()] + l[q.top()]; q.pop()) {
            if (who[q.top()] != -1) {
                t.add(who[q.top()], 0);
                who[q.top()] = -1;
            }

            //val[q.top()] = 0;
        }
        //cerr << "sz: " << q.size() << endl;
        //if (cur > 0)
            //cerr << "cur: " << cur << " " <<  p[i] + l[i] << " " << p[stack[cur - 1]] << endl;
        if (!q.empty() && p[i] + l[i] < p[q.top()]) {
            t.add(q.top(), p[q.top()] - p[i] - l[i]);
            who[i] = q.top();
            //assert(val[q.top()] == 0);
            //val[q.top()] += l[q.top()] - p[i] - l[i]; 
        }
        q.push(i);
        for (; curQuery < m && b[curQuery].t == i; curQuery++)
            answer[b[curQuery].id] = t.get(i, b[curQuery].r); 
    }
    for (int i = 0; i < m; i++)
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}