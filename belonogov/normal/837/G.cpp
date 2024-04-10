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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;

struct Seg {
    int l, r;
    ll a, b;
    void print() {
        cerr << "l r a b: " << l << " " << r << " " << a << " " << b << endl;
    }
};


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vi x1(n);
    vi x2(n);
    vi y1(n);
    vi a(n);
    vi b(n);
    vi y2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x1[i], &x2[i], &y1[i], &a[i], &b[i], &y2[i]);
    }

    vector<vector<Seg>> tree(n * 4); 

    auto merge = [](vector<Seg>& A, vector<Seg>& B) {
        vector<Seg> C;
        int curA = 0;
        int curB = 0;
        for (;curA < sz(A) && curB < sz(B);) {
            int l = max(A[curA].l, B[curB].l);
            int r = min(A[curA].r, B[curB].r);
            C.pb({l, r, A[curA].a + B[curB].a, A[curA].b + B[curB].b});
            if (A[curA].r < B[curB].r) {
                curA++;
            }
            else {
                curB++;
            }
        }
        return C;
    };

    function<void(int, int, int)> build = [&](int v, int tl, int tr) { 
        if (tl + 1 == tr) {
            tree[v].pb({-INF, x1[tl], 0, y1[tl]});
            tree[v].pb({x1[tl] + 1, x2[tl], a[tl], b[tl]});
            tree[v].pb({x2[tl] + 1, INF, 0, y2[tl]});
            return;
        }
        build(v * 2 + 1, tl, (tl + tr) / 2);
        build(v * 2 + 2, (tl + tr) / 2, tr);
        tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]); 
    };
    build(0, 0, n);

    function<ll(int, int, int, int, int, int)> query = [&](int v, int tl, int tr, int l, int r, int x) {
        if (r <= tl || tr <= l) return 0ll;
        if (l <= tl && tr <= r) {
            int fl = 0;
            int fr = sz(tree[v]);
            while (fr - fl > 1) {
                int mid = (fl + fr) / 2;
                if (x < tree[v][mid].l) {
                    fr = mid;
                }
                else {
                    fl = mid;
                }
            } 
            assert(tree[v][fl].l <= x && x <= tree[v][fl].r);

            //auto it = lower_bound(all(tree[v]), {x, x, 0, 0}, [](Seg, A, Seg B) {
                    // todo
                    //});
            //tree[v][fl].print();
            return tree[v][fl].b + tree[v][fl].a * x;
        }
        return query(v * 2 + 1, tl, (tl + tr) / 2, l, r, x) + 
               query(v * 2 + 2, (tl + tr) / 2, tr, l, r, x);
    };


    int m;
    scanf("%d", &m);
    ll last = 0;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--;
        //db3(l, r, n);
        last = query(0, 0, n, l, r, (x + last) % (int)1e9);
        printf("%lld\n", last);
    }
    



    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}