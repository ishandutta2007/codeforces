#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct Node {
    Node* ch[2] = {0, 0};
    int sz = 0;
};

void add(Node* t, int x, int i) {
    t->sz++;
    if (i < 0) {
        return;
    }
    int c = (x >> i) & 1;
    if (!t->ch[c]) {
        t->ch[c] = new Node();
    }
    add(t->ch[c], x, i - 1);
}

int k;

int get_sz(Node* t) {
    if (!t) {
        return 0;
    }
    return t->sz;
}

int get(Node* t, int x, int i) {
    if (i < 0) {
        return 0;
    }
    if (t == 0) {
        return 0;
    }
    int c = (x >> i) & 1;
    int ms = ~((1 << i) - 1);
    if (c == 0) {
        if ((x & ms) >= k) {
            return get_sz(t->ch[0]) + get_sz(t->ch[1]);
        }
        if (((x & ms) ^ (1 << i)) >= k) {
            return get(t->ch[0], x, i - 1) + get_sz(t->ch[1]);
        }
        x ^= (1 << i);
        return get(t->ch[1], x, i - 1);
    }
    if (((x & ms) ^ (1 << i)) >= k) {
        return get_sz(t->ch[0]) + get_sz(t->ch[1]);
    }
    if ((x & ms) >= k) {
        x ^= (1 << i);
        return get_sz(t->ch[0]) + get(t->ch[1], x, i - 1);
    }
    return get(t->ch[0], x, i - 1);
}

const int M = 30;

int main() {
    Node* root = new Node();
    add(root, 0, M);
    scid(n);
    sci(k);
    lint ans = 0;
    int cx = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        cx ^= x;
        ans += get(root, cx, M);
        add(root, cx, M);
    }
    cout << ans;

    return 0;
}