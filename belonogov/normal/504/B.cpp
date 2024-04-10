/*#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>*/
#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 3e5 + 10;
const int INF = 1e9;

struct Tree {
    vector < int > data;
    int sz;
    void init(int n) {
        sz = n; 
        data.resize(sz * 4);
    }
    void add(int v, int ll, int rr, int pos, int val) {
        if (ll >= pos + 1 || pos >= rr) return;
        if (rr - ll == 1) {
            data[v] = val;
            return;
        }
        add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        data[v] = data[v * 2 + 1] + data[v * 2 + 2];
    }
    void add(int pos, int val) {
        add(0, 0, sz, pos, val);
    }
    int getSum(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return 0;
        if (l <= ll && rr <= r) return data[v];
        return getSum(v * 2 + 1, ll, (ll + rr) / 2, l, r) +
               getSum(v * 2 + 2, (ll + rr) / 2, rr, l, r);
    }
    int getSum(int l, int r) {
        return getSum(0, 0, sz, l, r);
    }
    int getCntZero(int v, int ll, int rr) {
        return rr - ll - data[v];
    }
    int getK(int v, int ll, int rr, int k) {
        int cntZero = getCntZero(v, ll, rr);
        if (cntZero <= k) return -1; 
        if (rr - ll == 1) {
            if (data[v] == 0 && k == 0) {
                return ll;
            }
            return -1;
        }
        int x = getK(v * 2 + 1, ll, (ll + rr) / 2, k);
        if (x != -1) return x;
        int y = getK(v * 2 + 2, (ll + rr) / 2, rr, k - getCntZero(v * 2 + 1, ll, (ll + rr) / 2));
        assert(y != -1);
        return y;
    }
    int getK(int k) {
        return getK(0, 0, sz, k);
    }
};

int n;
int a[N];
int b[N];
int c[N];
int a1[N];
int b1[N];
int c1[N];

void read() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
}

void code(int * a, int * r) {
    Tree t; 
    t.init(n + 2);
    for (int i = 0; i < n; i++) {
        r[i] = a[i] - t.getSum(0, a[i]);
        t.add(a[i], 1);
        assert(r[i] < n - i);
    }
}

void decode(int * a, int * r) {
    Tree t;
    t.init(n + 2);
    for (int i = 0; i < n; i++) {
        a[i] = t.getK(r[i]);
        t.add(a[i], 1);
    }
}

void solve() {
    code(a, a1);
    code(b, b1);
    //for (int i = 0; i < n; i++)
        //cerr << a1[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << b1[i] << " ";
    //cerr << endl;
    int shift = 0;
    for (int i = n - 1; i >= 0; i--) {
        int md = n - i; 
        int t = a1[i] + b1[i] + shift;
        c1[i] = t % md;
        shift = t / md;
    }
    //for (int i = 0; i < n; i++)
        //cerr << c1[i] << " ";
    //cerr << endl;
    decode(c, c1);
}

void printAns() {
    for (int i = 0; i < n; i++)
        printf("%d ", c[i]);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}