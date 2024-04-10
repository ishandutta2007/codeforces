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
const int maxn = -1;
const int inf = 1e9;

struct Tree {
    vector < long long > sum;
    vector < pair < long long, int > > mx;

    int sz;
    Tree() {}
    void init2(vector < int > const & a) {
        sz = a.size();
        mx.resize(sz * 4);
        sum.resize(sz * 4);
        init(0, 0, sz, a);
    }

    void init(int v, int ll, int rr, vector < int > const & a) {
        if (ll + 1 == rr) {
            sum[v] = a[ll];
            mx[v] = mp(a[ll], ll);
            return;
        }
        init(v * 2 + 1, ll, (ll + rr) / 2, a);
        init(v * 2 + 2, (ll + rr) / 2, rr, a);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
        mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    }

    pair < int, int > getMax(int l, int r) {
        return getMax2(0, 0, sz, l, r);
    }

    pair < int, int > getMax2(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return mp(-1, -1);
        if (l <= ll && rr <= r) return mx[v];
        return max(getMax2(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                    getMax2(v * 2 + 2, (ll + rr) / 2, rr, l, r));
    }

    void add(int pos, int val) {
        add2(0, 0, sz, pos, val);
    }
    void add2(int v, int ll, int rr, int pos, int val) {
        if (pos >= rr || ll >= pos + 1) return;
        if (ll + 1 == rr) {
            sum[v] = val;
            mx[v] = mp(val, pos);
            return;
        }
        add2(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        add2(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
        mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    }

    long long getSum(int l, int r) {
        return getSum2(0, 0, sz, l, r); 
    }

    long long getSum2(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return 0;
        if (l <= ll && rr <= r)
            return sum[v];
        return getSum2(v * 2 + 1, ll, (ll + rr) / 2, l, r) + 
                getSum2(v * 2 + 2, (ll + rr) / 2, rr, l, r);
    }
};

double getTime() {
    return clock() * 1.0 / CLOCKS_PER_SEC;
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    //freopen("test.in", "r", stdin);
    int n, m, l, r, x, pos, val, type;
    scanf("%d%d", &n, &m);
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Tree t;
    t.init2(a);
    //cout << getTime() << endl; 
    for (int i = 0; i < m; i++) {
        //cerr << "i\n";
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &l, &r); l--;
            printf("%lld\n", t.getSum(l, r));
        }
        if (type == 2) {
            scanf("%d%d%d", &l, &r, &x); l--;
            for (;;) {
                pair < int, int > tmp = t.getMax(l, r);
                //cerr << tmp.fr << " " << tmp.sc << endl;
                if (tmp.fr >= x) {
                    tmp.fr %= x;
                    //cerr << tmp.fr << " " << tmp.sc << endl;
                    t.add(tmp.sc, tmp.fr);
                }
                else
                    break;
            }
        }
        if (type == 3) {
            scanf("%d%d", &pos, &val); pos--;
            t.add(pos, val);
        }
    }
    return 0;
}