#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e6 + 42;
int d[maxn];
int A[maxn];

int sm[4 * maxn];
bool has[4 * maxn];
void build(int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        sm[v] = A[l];
        has[v] = A[l] > 2;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    sm[v] = sm[2 * v] + sm[2 * v + 1];
    has[v] = has[2 * v] || has[2 * v + 1];
}

void upd(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        if(r - l == 1) {
            sm[v] = A[l] = d[A[l]];
            has[v] = A[l] > 2;
            return;
        } else {
            int m = (l + r) / 2;
            if(has[2 * v]) {
                upd(a, b, 2 * v, l, m);
            }
            if(has[2 * v + 1]) {
                upd(a, b, 2 * v + 1, m, r);
            }
            sm[v] = sm[2 * v] + sm[2 * v + 1];
            has[v] = has[2 * v] || has[2 * v + 1];
        }
    } else if(r <= a || b <= l) {
        return;
    } else {
        int m = (l + r) / 2;
        upd(a, b, 2 * v, l, m);
        upd(a, b, 2 * v + 1, m, r);
        sm[v] = sm[2 * v] + sm[2 * v + 1];
        has[v] = has[2 * v] || has[2 * v + 1];
    }
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return sm[v];
    } else if(r <= a || b <= l) {
        return 0;
    } else {
        int m = (l + r) / 2;
        return get(a, b, 2 * v, l, m) + get(a, b, 2 * v + 1, m, r);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < maxn; i++) {
        for(int j = i; j < maxn; j += i) {
            d[j]++;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    build();
    while(m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            upd(l - 1, r);
        } else {
            cout << get(l - 1, r) << "\n";
        }
    }
    return 0;
}