#include <bits/stdc++.h> 

using namespace std;

const int maxn = 5e5 + 42;

int gc[4 * maxn];

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        gc[v] = c;
        return;
    }
    int m = (l + r) / 2;
    if(p < m) {
        upd(p, c, 2 * v, l, m);
    } else {
        upd(p, c, 2 * v + 1, m, r);
    }
    gc[v] = __gcd(gc[2 * v], gc[2 * v + 1]);
}

int check(int a, int b, int c, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    if(a <= l && r <= b) {
        if(gc[v] % c == 0) {
            return 0;
        } else {
            if(r - l == 1) {
                return 1;
            } else {
                int A = gc[2 * v];
                int B = gc[2 * v + 1];
                if(A % c && B % c) {
                    return 2;
                } else if(A % c) {
                    return check(a, b, c, 2 * v, l, m);
                } else {
                    return check(a, b, c, 2 * v + 1, m, r);
                }
            }
        }
    } else if(r <= a || b <= l) {
        return 0;
    }
    int A = check(a, b, c, 2 * v, l, m);
    int B = check(a, b, c, 2 * v + 1, m, r);
    return min(2, A + B);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        upd(i, a[i]);
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            cout << (check(l - 1, r, x) < 2 ? "YES" : "NO") << endl;
        } else {
            int p, c;
            cin >> p >> c;
            upd(p - 1, c);
        }
    }
    return 0;
}