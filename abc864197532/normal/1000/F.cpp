#include <bits/stdc++.h>
using namespace std;
const int N = 500001, C = 707;

int cnt[N];

long long hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (pow * 2 - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct query {
    int l, r, id;
    long long ord;
    bool operator < (const query& o) {
        return ord < o.ord;
    }
};

struct DS {
    int cnt[N], block[N / C + 1];
    void upd(int x, int v) {
        cnt[x] += v;
        block[x / C] += v;
    }
    int query() {
        for (int i = 0; i < N; i += C) if (block[i / C] != 0) {
            for (int j = i; j < min(i + C, N); ++j) {
                if (cnt[j])
                    return j;
            }
        }
        return 0;
    }
} ds;


void add(int v) {
    if (cnt[v] == 1)
        ds.upd(v, -1);
    cnt[v]++;
    if (cnt[v] == 1)
        ds.upd(v, 1);
}

void del(int v) {
    if (cnt[v] == 1)
        ds.upd(v, -1);
    cnt[v]--;
    if (cnt[v] == 1)
        ds.upd(v, 1);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <query> queries;
    cin >> q;
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r, --l;
        long long ord =  hilbertOrder(l, r, 20, 0);
        queries.push_back({l, r, i, ord});
    }
    sort(queries.begin(), queries.end());
    int l = 0, r = 0;
    vector <int> ans(q);
    for (query q : queries) {
        while(r < q.r)
            add(a[r++]);
        while(r > q.r)
            del(a[--r]);
        while(l < q.l) 
            del(a[l++]);
        while(l > q.l) 
            add(a[--l]);
        ans[q.id] = ds.query();
    }
    for (int i : ans)
        cout << i << '\n';
}