#include <bits/stdc++.h>
//#define int long long
#define mp make_pair

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

struct Tree {
    int n, *t;

    Tree(int n) : n(n) { t = new int[4 * n](); }

    void build(int v, int vl, int vr, int a[]) {
        if (vr - vl == 1) {
            t[v] = a[vl];
        }
        else {
            int vm = (vl + vr) / 2;
            build(v * 2, vl, vm, a);
            build(v * 2 + 1, vm, vr, a);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void build(int a[]) {
        build(1, 0, n, a);
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) {
            return 0;
        }
        if (l <= vl && vr <= r) {
            return t[v];
        }
        int vm = (vl + vr) / 2;
        return get(v * 2, vl, vm, l, r) + get(v * 2 + 1, vm, vr, l, r);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    int change(int v, int vl, int vr, int i, int x) {
        if (i < vl || vr <= i) {
            return t[v];
        }
        if (vr - vl == 1) {
            return t[v] = x;
        }
        int vm = (vl + vr) / 2;
        return t[v] = change(2 * v, vl, vm, i, x) + change(2 * v + 1, vm, vr, i, x);
    }

    int change(int i, int x) {
        change(1, 0, n, i, x);
    }


};

int gcd(int a, int b) {
    if (a <= 0 || b <= 0) {
        return max(a, b);
    }
    if (a > b) {
        return gcd(a % b, b);
    }
    else {
        return gcd(a, b % a);
    }
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    while(true) {
        if(n - __gcd(a, n) < 0) {
            cout << 1;
            return 0;
        }
        else {
            n -= __gcd(a, n);
        }
        if(n - __gcd(b, n) < 0) {
            cout << 0;
            return 0;
        }
        else {
            n -= __gcd(b, n);
        }
    }
}