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
#define prev prevvv
const int N = 5e5;
const long long INF = 1e9 + 19;

//bool myCmp(pair < int, int > a, pair < int, int > b) {
    //return a.fr < b.fr || (a.fr == b.fr && a.sc > b.sc);
//}

struct Tree {
    vector < pair < int, int > > data;
    int n;
    Tree(int n):n(n) {
        data.assign(n * 4, mp(0, -1));
    }

    pair < int, int > getMax(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return mp(0, -1);
        if (l <= ll && rr <= r)
            return data[v];
        return max(getMax(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                   getMax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
    }

    void setVal(int v, int ll, int rr, int pos, pair < int, int > val) {
        if (pos < ll || rr <= pos) return;
        if (ll + 1 == rr) {
            data[v] = max(data[v], val);
            //if (myCmp(data[v], val))
                //data[v] = val;
            return;
        }
        setVal(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        setVal(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        //if (myCmp(data[v * 2 + 1], data[v * 2 + 2]))
            //data[v] = data[v * 2 + 2];
        //else
            //data[v] = data[v * 2 + 1];
        data[v] = max(data[v * 2 + 1], data[v * 2 + 2]);
    }

};

struct Query {
    int pos, val, id;
};

int n, m;
int a[N];
Query b[N];
int answer[N];
int prev[N];


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &b[i].pos, &b[i].val);
        b[i].pos--;
        b[i].id = i;
    }
}

bool notFound(vector < int > & a, int x) {
    //for (auto y: a)
        //cerr << y << " ";
    //cerr << endl;
    //db(x);
    int p = lower_bound(a.begin(), a.end(), x) - a.begin();
    return !(0 <= p && p < (int)a.size() && a[p] == x);
}


void solve() {
    vector < int > xx; 
    for (int i = 0; i < n; i++)
        xx.pb(a[i]);
    for (int i = 0; i < m; i++)
        xx.pb(b[i].val);
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(xx.begin(), xx.end(), a[i]) - xx.begin();
    for (int i = 0; i < m; i++)
        b[i].val = lower_bound(xx.begin(), xx.end(), b[i].val) - xx.begin();

    int sz = xx.size(); 
    Tree t1(sz);
    int mx = 0;
    int pos = -1;
    sort(b, b + m, [](Query a, Query b) { return a.pos < b.pos; });

    for (int i = 0; i < m; i++)
        answer[i] = 1;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        auto tmp = t1.getMax(0, 0, sz, 0, a[i]);             
        int val = tmp.fr + 1;
        if (val > mx) {
            mx = val;
            pos = i;
        }
        for (; cur < m && b[cur].pos == i; cur++) {
            auto tmp = t1.getMax(0, 0, sz, 0, b[cur].val);
            answer[b[cur].id] += tmp.fr;
        }

        t1.setVal(0, 0, sz, a[i], mp(val, -i));
        //db(tmp.sc);
        if (val == 1)
            tmp.sc = 1;
        prev[i] = -tmp.sc;
    }

    vector < int > g; 
    for (; pos != -1; ) {
        //db(pos);
        g.pb(pos);
        pos = prev[pos];
    }
    reverse(g.begin(), g.end());
    assert((int)g.size() == mx);

   //////////////////////// 
    Tree t2(sz);
    mx = 0;
    pos = -1;   
    sort(b, b + m, [](Query a, Query b) { return a.pos > b.pos; } );

    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto tmp = t2.getMax(0, 0, sz, a[i] + 1, sz);
        int val = tmp.fr + 1;
        if (val > mx) {
            mx = val;
            pos = i;
        }
        for (; cur < m && b[cur].pos == i; cur++) {
            auto tmp = t2.getMax(0, 0, sz, b[cur].val + 1, sz);
            answer[b[cur].id] += tmp.fr;
        }
        t2.setVal(0, 0, sz, a[i], mp(val, i));
        prev[i] = tmp.sc;
    }

    vector < int > h;
    for (; pos != -1; ) {
        h.pb(pos);
        pos = prev[pos];
    }
    assert(h.size() == g.size());

    //for (auto x: h)
        //cerr << x << " ";
    //cerr << endl;

    //for (auto x: g)
        //cerr << x << " ";
    //cerr << endl;

    //for (int i = 0; i < m; i++)
        //cerr << answer[i] << " ";
    //cerr << endl;

    for (int i = 0; i < m; i++) {
        if (notFound(g, b[i].pos) || notFound(h, b[i].pos))
            answer[b[i].id] = max(answer[b[i].id], (int)h.size());
        else 
            answer[b[i].id] = max(answer[b[i].id], (int)h.size() - 1);
    } 


    for (int i = 0; i < m; i++)
        printf("%d\n", answer[i]);

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