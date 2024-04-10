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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct State {
    int l, r;
    int cnt;
    vector<int> c;
    void Epr() {
        cerr << "l r cnt: " << l << " " << r << " " << cnt << endl; 
        cerr << "c: ";
        for (auto x: c)
            cerr << x << " ";
        cerr << endl;
    }
};


int n, k;
vector<int> e[N];
vector<pair<int,int>> query;
State tree[N * 4];


void read() {
    scanf("%d%d", &n, &k);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int v, u; 
        scanf("%d%d", &v, &u); v--; u--;
        if (v > u)
            swap(v, u);
        // v < u;
        assert(abs(v - u) <= k);
        e[u].pb(v);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r); l--;
        //db2(l, r);
        query.pb(mp(l, r));
    }

}

State merge(State A, State B) {
    //db2(A.l, A.r);
    //db2(B.l, B.r);
    assert(A.r == B.l);
    State res;
    res.l = A.l;
    res.r = B.r;
    res.cnt = A.cnt + B.cnt;
    //int mxA = 0;
    //for (auto x: A.c)
        //mxA = max(mxA, x);
    //mxA++;
    for (auto& x: B.c)
        x += A.r - A.l;
    //cerr << endl;
    //cerr << "================" << endl;
    //A.Epr();
    //B.Epr();
    //cerr << "A.c: ";
    //for (auto x: A.c)
        //cerr << x << " ";
    //cerr << endl;
    //cerr << "B.c: ";
    //for (auto x: B.c)
        //cerr << x << " ";
    //cerr << endl;
    for (int i = 0; i < min(k, B.r - B.l); i++) {
        for (auto v: e[B.l + i]) {
            //db2(B.l + i, v);
            //db2(A.l, A.r);
            //db(A.c.size() - (A.r - v)); 
            //db3(A.l, A.r, v);
            //db(B.l + i);
            if (A.l <= v && v < A.r && A.c[A.c.size() - (A.r - v)] != B.c[i]) {
                //db("tut");
                int dd = A.c[A.c.size() - (A.r - v)];
                for (auto& x: A.c)
                    if (x == dd)
                        x = B.c[i];
                for (auto& x: B.c)
                    if (x == dd)
                        x = B.c[i];
                res.cnt--;
            }
        } 
    }  
    vector<int> tmp = A.c;
    tmp.insert(tmp.end(), all(B.c));
    if ((int)tmp.size() < k * 2) {
        res.c = tmp;
    }
    else {
        for (int i = 0; i < k; i++)
            res.c.pb(tmp[i]);
        for (int i = k - 1; i >= 0; i--)
            res.c.pb(tmp[tmp.size() - 1 - i]);
    }
    //res.Epr();
    assert(res.cnt >= 1);
    //set<int> gg(all(res.c));
    //assert((int)gg.size() <= res.cnt);
    return res;
}

void build(int v, int tl, int tr) {
    if (tl + 1 == tr) {
        tree[v].l = tl;
        tree[v].r = tr;
        tree[v].cnt = 1;
        tree[v].c = {0};
        return;
    }
    build(v * 2 + 1, tl, (tl + tr) / 2);
    build(v * 2 + 2, (tl + tr) / 2, tr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

State get(int v, int tl, int tr, int l, int r) {
    //cerr << "get: " << endl;
    //db2(l, r);
    //db3(v, tl, tr);
    //assert(v < n * 5);

    if (l <= tl && tr <= r)
        return tree[v];
    int mid = (tl + tr) / 2;
    if (mid <= l)
        return get(v * 2 + 2, mid, tr, l, r);
    if (r <= mid)
        return get(v * 2 + 1, tl, mid, l, r);
    return merge(get(v * 2 + 1, tl, mid, l, r),
                 get(v * 2 + 2, mid, tr, l, r));
}

void solve() {
    build(0, 0, n);
    //db("done");
    //for (auto x: query)
        //db2(x.F, x.S);
    //tree[1].Epr();
    //tree[5].Epr();

    //auto tmp = merge(tree[1], tree[5]);
    //tmp.Epr();

    //return;

    for (int i = 0; i < (int)query.size(); i++) {
        //db2(query[i].F, query[i].S);
        auto st = get(0, 0, n, query[i].F, query[i].S);
        printf("%d\n", st.cnt);
    }


}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    if (1) {
        read();
        solve();
        //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }
    else {
        stress();
    }

    return 0;
}