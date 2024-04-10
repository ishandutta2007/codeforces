#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node{
    int next[10];
    int sum[10];
};

int next1[10];
int next2[10];
int SUM[10];

int a[100005];
Node p[400005];

void union1(int i){
    for (int j = 0; j < 10; ++j) p[i].sum[j] = p[2 * i + 1].sum[j] + p[2 * i + 2].sum[j];
}

void push(int i, int l, int r){
    for (int j = 0; j < 10; ++j) SUM[j] = 0;
    if (l != r - 1){
        for (int j = 0; j < 10; ++j){
            next1[j] = p[i].next[p[2 * i + 1].next[j]];
            next2[j] = p[i].next[p[2 * i + 2].next[j]];
        }
        for (int j = 0; j < 10; ++j){
            p[2 * i + 1].next[j] = next1[j];
            p[2 * i + 2].next[j] = next2[j];
        }
    }
    for (int j = 0; j < 10; ++j){
        SUM[p[i].next[j]] += p[i].sum[j];
    }
    for (int j = 0; j < 10; ++j){
        p[i].sum[j] = SUM[j];
        p[i].next[j] = j;
    }
}

void build(int i, int l, int r){
    if (l == r - 1){
        for (int j = 0; j < 10; ++j) p[i].next[j] = j;
        int hp = a[l], zn = 1;
        while (hp > 0){
            p[i].sum[hp % 10] += zn;
            hp /= 10;
            zn *= 10;
        }
    }
    else{
        for (int j = 0; j < 10; ++j) p[i].next[j] = j;
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        union1(i);
    }
}

void upd(int i, int l, int r, int lq, int rq, int dx, int dy){
    push(i, l, r);
    if (lq >= r || rq <= l) return;
    if (lq <= l && r <= rq){
        p[i].next[dx] = dy;
        push(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, lq, rq, dx, dy);
    upd(2 * i + 2, m, r, lq, rq, dx, dy);
    union1(i);
}

int answ(int i, int l, int r, int lq, int rq){
    push(i, l, r);
    if (lq >= r || rq <= l) return 0;
    if (lq <= l && r <= rq){
        int ans = 0;
        for (int j = 0; j < 10; ++j) ans += p[i].sum[j] * j;
        return ans;
    }
    int m = (r + l) / 2;
    return answ(2 * i + 1, l, m, lq, rq) + answ(2 * i + 2, m, r, lq, rq);
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, t, l, r, x, y;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(0, 1, n + 1);
    for (int i = 1; i <= q; ++i){
        cin >> t;
        if (t == 1){
            cin >> l >> r >> x >> y;
            upd(0, 1, n + 1, l, r + 1, x, y);
        }
        else{
            cin >> l >> r;
            cout << answ(0, 1, n + 1, l, r + 1) << '\n';
        }
    }
    return 0;
}