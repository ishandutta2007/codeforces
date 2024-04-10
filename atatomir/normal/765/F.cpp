#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define inf 2000000000

struct query {
    int l, r;
    int id;

    bool operator<(const query& who)const {
        return l > who.l;
    }
};

struct intr {
    int l, r;
    int val;

    bool operator<(const intr& who)const {
        return l > who.l;
    }
};

struct aint {
    int n;
    vector<int> data;

    void init(int _n) {
        n = _n;
        data = vector<int>(4 * n + 11, inf);
    }

    void update(int node, int l, int r, int pos, int v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(lSon, l, mid, pos, v);
        if (pos > mid)
            update(rSon, mid + 1, r, pos, v);

        data[node] = min(data[lSon], data[rSon]);
    }

    int query(int node, int l, int r, int qL, int qR, int limit) {
        if (data[node] > limit) return -1;
        if (l == r)
            return l;

        int ans = -1;

        int mid = (l + r) >> 1;
        if (qR > mid)
            ans = query(rSon, mid + 1, r, qL, qR, limit);

        if (ans != -1) return ans;
        return query(lSon, l, mid, qL, qR, limit);
    }
};

int n, q, i;
int v[maxN];
query Q[maxN];
int ans[maxN];

vector< pair<int, int> > ord;
vector< intr > todo;

aint work;
int aib[maxN];

int abss(int x) {
    if (x < 0) return -x;
    return x;
}

int zrs(int x) {
    return (x & (x - 1)) ^ x;
}

void add(int pos, int v) {
    while (pos <= n) {
        aib[pos] = min(aib[pos], v);
        pos += zrs(pos);
    }
}

int que(int pos) {
    int ans = inf;

    while (pos > 0) {
        ans = min(ans, aib[pos]);
        pos -= zrs(pos);
    }

    return ans;
}

void add_todo() {
    int i, up, wh, last;

    sort(ord.begin(), ord.end(), [](pair<int, int> a, pair<int, int> b)->bool const {
        return mp(a.first, -a.second) < mp(b.first, -b.second);
    });
    reverse(ord.begin(), ord.end());

    work.init(n);

    for (auto e : ord) {
        int pos = abss(e.second);

        work.update(1, 1, n, pos, e.first);

        if (pos == 1) continue;
        up = inf - 10;

        last = pos;

        while (last > 1) {
           wh = work.query(1, 1, n, 1, last - 1, up);
           wh = max(wh, 1);


           if (v[wh] < v[pos]) break;
           if (v[wh] > up) break;

           todo.pb({wh, pos, v[wh] - v[pos]});
           up = min(up - 1, (v[wh] + v[pos]) / 2);
           last = wh;
        }
    }
}

void solve() {
    int i, pos;

    for (i = 1; i <= n; i++) aib[i] = inf;

    sort(todo.begin(), todo.end());
    sort(Q + 1, Q + q + 1);

    pos = 0;
    for (i = 1; i <= q; i++) {
        auto act = Q[i];

        while (pos < todo.size()) {
            if (todo[pos].l < act.l) break;
            add(todo[pos].r, todo[pos].val);
            pos++;
        }

        ans[act.id] = que(act.r);
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        ord.pb(mp(v[i], i));
    }

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
        ans[i] = inf;
    }

    add_todo();

    ord.clear();
    for (i = 1; i <= n; i++) {
        v[i] = -v[i];
        ord.pb(mp(v[i], i));
    }

    add_todo();

    solve();

    for (i = 1; i <= q; i++) printf("%d\n", ans[i]);


    return 0;
}