#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5, maxc = 4e6 + 5;
int a[maxn], nxt_max[maxn], nxt_min[maxn], lst_max[maxn], lst_min[maxn], good[maxn], b[maxn], c[maxn], node[maxc], nxt_l[maxc], nxt_r[maxc], mini[maxc];
pair < int, int > pos_min[(1 << 19)], pos_max[(1 << 19)];
int inf = 1e9 + 7;
vector < int > goal[maxn], draw[maxn];
pair < int, int > tree[(1 << 19)];
int numb = 1;

void build(int i, int l, int r) {
    if (r - l == 1) {
        pos_min[i] = {a[l], l};
        pos_max[i] = {a[l], l};
        return;
    }
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
    pos_min[i] = min(pos_min[2 * i + 1], pos_min[2 * i + 2]);
    pos_max[i] = max(pos_max[2 * i + 1], pos_max[2 * i + 2]);
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return inf;
    if (lq <= l && r <= rq) return mini[i];
    int m = (r + l) / 2;
    return min(get(nxt_l[i], l, m, lq, rq), get(nxt_r[i], m, r, lq, rq));
}

pair < int, int > get_min(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return {inf, inf};
    if (lq <= l && r <= rq) return pos_min[i];
    int m = (r + l) / 2;
    return min(get_min(2 * i + 1, l, m, lq, rq), get_min(2 * i + 2, m, r, lq, rq));
}

pair < int, int > get_max(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return {-inf, -inf};
    if (lq <= l && r <= rq) return pos_max[i];
    int m = (r + l) / 2;
    return max(get_max(2 * i + 1, l, m, lq, rq), get_max(2 * i + 2, m, r, lq, rq));
}

void add(int i, int l, int r, int lq, int rq, pair < int, int > s) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        tree[i] = min(tree[i], s);
        return;
    }
    int m = (r + l) / 2;
    add(2 * i + 1, l, m, lq, rq, s);
    add(2 * i + 2, m, r, lq, rq, s);
}

pair < int, int > f(int i, int l, int r, int lq) {
    if (r - l == 1) return tree[i];
    int m = (r + l) / 2;
    if (lq < m) return min(tree[i], f(2 * i + 1, l, m, lq));
    return min(tree[i], f(2 * i + 2, m, r, lq));
}

inline void solve(int n) {
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        c[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    }
    for (int i = 0; i < (1 << 19); ++i) tree[i] = {inf, inf};
    vector < int > st;
    for (int i = n; i >= 1; --i) {
        while ((int)st.size() > 0 && c[st.back()] >= c[i]) st.pop_back();
        if ((int)st.size() == 0) nxt_min[i] = inf;
        else nxt_min[i] = st.back();
        st.push_back(i);
    }
    //return;
    for (int i = n; i >= 1; --i) {
        pair < int, int > tmp = f(0, 1, n + 1, c[i]);
        draw[i] = min(draw[i], {tmp.first, tmp.second, i});
        if (nxt_min[i] != n + 1) add(0, 1, n + 1, 1, c[i], {nxt_min[i], i});
    }
}

void build1(int i, int l, int r) {
    if (r - l == 1) {
        pos_min[i] = {goal[l].back(), l};
        pos_max[i] = {draw[l].back(), l};
        return;
    }
    int m = (r + l) / 2;
    build1(2 * i + 1, l, m);
    build1(2 * i + 2, m, r);
    pos_min[i] = min(pos_min[2 * i + 1], pos_min[2 * i + 2]);
    pos_max[i] = min(pos_max[2 * i + 1], pos_max[2 * i + 2]);
}

pair < int, int > get_maxx(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return {inf, inf};
    if (lq <= l && r <= rq) return pos_max[i];
    int m = (r + l) / 2;
    return min(get_maxx(2 * i + 1, l, m, lq, rq), get_maxx(2 * i + 2, m, r, lq, rq));
}

void modify(int i, int l, int r, int lq, int x) {
    if (r - l == 1) {
        mini[numb++] = x;
        return;
    }
    int m = (r + l) / 2;
    if (lq < m) {
        modify(nxt_l[i], l, m, lq, x);
        nxt_l[numb] = numb - 1, nxt_r[numb] = nxt_r[i];
    }
    else {
        modify(nxt_r[i], m, r, lq, x);
        nxt_l[numb] = nxt_l[i], nxt_r[numb] = numb - 1;
    }
    mini[numb] = min(mini[nxt_l[numb]], mini[nxt_r[numb]]);
    numb++;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    //n = 200000, q = n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector < int > imax, imin;
    for (int i = 1; i <= n; ++i) {
        while ((int)imax.size() > 0 && a[imax.back()] <= a[i]) imax.pop_back();
        while ((int)imin.size() > 0 && a[imin.back()] >= a[i]) imin.pop_back();
        if ((int)imax.size() > 0) lst_max[i] = imax.back();
        if ((int)imin.size() > 0) lst_min[i] = imin.back();
        imax.push_back(i), imin.push_back(i);
    }
    imax = {}, imin = {};
    for (int i = n; i >= 1; --i) {
        while ((int)imax.size() > 0 && a[imax.back()] <= a[i]) imax.pop_back();
        while ((int)imin.size() > 0 && a[imin.back()] >= a[i]) imin.pop_back();
        nxt_max[i] = n + 1, nxt_min[i] = n + 1;
        if ((int)imax.size() > 0) nxt_max[i] = imax.back();
        if ((int)imin.size() > 0) nxt_min[i] = imin.back();
        imax.push_back(i), imin.push_back(i);
    }
    for (int i = 1; i <= n; ++i) good[i] = min(lst_max[i], lst_min[i]);
    build(0, 1, n + 1);
    mini[0] = inf;
    for (int i = n; i >= 1; --i) {
        node[i] = node[i + 1];
        if (good[i] != 0) {
            modify(node[i], 1, n + 1, good[i], i);
            node[i] = numb - 1;
        }
    }
    for (int i = 1; i <= n; ++i) goal[i] = {inf, inf, inf, inf}, draw[i] = {inf, inf, inf};
    for (int i = 1; i <= n; ++i) {
        int go = max(nxt_min[i], nxt_max[i]) + 1;
        int cur = get(node[go], 1, n + 1, i + 1, n + 1);
        if (cur != inf) {
            int pos1 = get_min(0, 1, n + 1, i + 1, cur).second, pos2 = get_max(0, 1, n + 1, i + 1, cur).second;
            if (pos1 > pos2) swap(pos1, pos2);
            goal[i] = {i, pos1, pos2, cur};
        }
    }
    solve(n);
    for (int i = 1; i <= n; ++i) a[i] *= (-1);
    solve(n);
    for (int i = 1; i <= n; ++i) reverse(draw[i].begin(), draw[i].end());
    build1(0, 1, n + 1);
    //exit(0);
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        int R = get_min(0, 1, n + 1, l, r + 1).second;
        int ok = 1;
        for (int j = R; j <= R && ok; ++j) {
            if (goal[j].back() <= r) {
                ok = 0;
                cout << 4 << '\n';
                for (auto key : goal[j]) cout << key << " ";
                cout << '\n';
            }
        }
        R = get_maxx(0, 1, n + 1, l, r + 1).second;
        for (int j = R; j <= R && ok; ++j) {
            if (draw[j].back() <= r) {
                ok = 0;
                cout << 3 << '\n';
                for (auto key : draw[j]) cout << key << " ";
                cout << '\n';
            }
        }
        if (ok) cout << 0 << '\n';
    }
    return 0;
}