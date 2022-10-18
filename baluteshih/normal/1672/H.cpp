#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

struct node {
    int l, r;
    int type, bld, done;
    node operator+(const node &a) const {
        node rt;
        rt.l = l, rt.r = a.r;
        rt.type = type, rt.bld = bld, rt.done = done + a.done;
        if (r == a.l) {
            if (type == r)
                ++rt.bld;
            else {
                if (rt.bld > 0)
                    --rt.bld, ++rt.done;
                else
                    rt.bld = 1, rt.type = r;
            }
        }
        if (rt.type == a.type)
            rt.bld += a.bld;
        else {
            if (rt.bld < a.bld)
                rt.type = a.type;
            rt.done += min(a.bld, rt.bld);
            rt.bld = abs(rt.bld - a.bld);
        }
        return rt;
    }
} seg[800005];

string s;

void build(int l, int r, int rt) {
    if (l == r) {
        int val = s[l] - '0';
        seg[rt] = node{val, val, val, 0, 0};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

node query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r)
        return seg[rt];
    int mid = (l + r) >> 1;
    if (R <= mid)
        return query(L, R, l, mid, rt << 1);
    if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q >> s;
    s.insert(s.begin(), '?');
    build(1, n, 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        node rt = query(l, r, 1, n, 1);
        node lft = node{rt.l, rt.l, rt.l, 0, 0};
        node rgt;
        if (rt.l == rt.r)
            rgt = node{rt.r ^ 1, rt.r ^ 1, rt.r ^ 1, 1, 0};
        else
            rgt = node{rt.r, rt.r, rt.r, 0, 0};

        rt = lft + rt + rgt;
        cout << rt.bld + rt.done << "\n";
    }
}