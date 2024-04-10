#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int imin[(1 << 19)], psh[(1 << 19)];

void build(int i, int l, int r) {
    imin[i] = maxn, psh[i] = maxn;
    if (r - l == 1) {
        return;
    } else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
    }
}

void update(int i, int l, int r, int lq, int rq, int x) {
    if (lq >= r || l >= rq) return;
    imin[i] = min(imin[i], x);
    if (lq <= l && r <= rq) {
        psh[i] = min(psh[i], x);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return maxn;
    if (lq <= l && r <= rq) return imin[i];
    int m = (r + l) / 2;
    return min({get(2 * i + 1, l, m, lq, rq), get(2 * i + 2, m, r, lq, rq), psh[i]});
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r, x, t;
    cin >> n >> q;
    set < pair < int, int > > Q;
    for (int i = 0; i <= n; ++i) Q.insert({i, i});
    build(0, 0, n + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> t;
        if (t == 0) {
            cin >> l >> r >> x;
            if (x == 0) {
                pair < int, int > cur = {l, -1};
                auto it = Q.lower_bound(cur);
                it--;
                int L = n + 1, R = -1;
                vector < pair < int, int > > del;
                while (it != Q.end()) {
                    cur = (*it);
                    if (cur.first > r) break;
                    L = min(L, cur.first);
                    R = max(R, cur.second);
                    del.push_back(cur);
                    it++;
                }
                for (auto key : del) Q.erase(key);
                Q.insert({L, R});
                assert(L <= R);
                update(0, 0, n + 1, L, R + 1, get(0, 0, n + 1, L, R + 1));
                int lef = -1, righ = L;
                while (righ - lef > 1) {
                    int mid = (righ + lef) / 2;
                    if (get(0, 0, n + 1, mid, L) > R) righ = mid;
                    else lef = mid;
                }
                if (lef != -1) update(0, 0, n + 1, 0, lef + 1, L);
            } else {
                pair < int, int > cur = {l, -1};
                auto it = Q.lower_bound(cur);
                it--;
                pair < int, int > tmp = *it;
                cur = {r + 1, -1};
                it = Q.lower_bound(cur);
                it--;
                cur = *it;
                update(0, 0, n + 1, tmp.first, tmp.second + 1, cur.first);
            }
        } else {
            cin >> l;
            pair < int, int > cur = {l, -1};
            auto it = Q.lower_bound(cur);
            it--;
            if ((*it).second >= l) cout << "NO" << '\n';
            else if (get(0, 0, n + 1, l - 1, l) == l) cout << "YES" << '\n';
            else cout << "N/A" << '\n';
        }
    }
    return 0;
}