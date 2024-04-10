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

int main() {
    int a[10][10];
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) {
                cout << abs(3 - i) + abs(3 - j) << endl;
                return 0;
            }
        }
    }
}