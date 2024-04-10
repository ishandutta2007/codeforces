#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T >
T abs(T x) {
    return x > 0 ? x : -x;
}

template < typename T >
T sqr(T x) {
    return x * x;
}

const int maxn = 2e5 + 5;
pair<ll, int> t[maxn * 4];
ll add[maxn * 4];

void push(int v) {
    if (add[v]) {
        add[2 * v] += add[v];
        add[2 * v + 1] += add[v];
        t[2 * v].fst += add[v];
        t[2 * v + 1].fst += add[v];
        add[v] = 0;
    }
}

int a[maxn];
int n;

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = mp(a[l] - (n - 1 - r), l);
        return;
    }

    int c = (l + r) >> 1;
    build(2 * v, l, c);
    build(2 * v + 1, c + 1, r);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

const ll inf = 1e16;

void addQ(int v, int l, int r, int i, int j, ll val) {
    if (i <= l && r <= j) {
        add[v] += val;
        add[v] = max(add[v], -inf);
        t[v].fst += val;
        t[v].fst = max(t[v].fst, -inf);
        return;
    }

    push(v);

    int c = (l + r) >> 1;
    if (i <= c) {
        addQ(2 * v, l, c, i, j, val);
    }

    if (c < j) {
        addQ(2 * v + 1, c + 1, r, i, j, val);
    }

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

void die() {
    cout << ":(" << endl;
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    build(1, 0, n - 1);

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        auto c = t[1];


        if (c.fst < 0) {
            die();
        }

        ans.pb(c.fst);
        addQ(1, 0, n - 1, c.snd, c.snd, -inf);
        addQ(1, 0, n - 1, 0, n - 1, 1);
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i + 1 < ans.size(); i++) {
        if (ans[i] > ans[i + 1]) {
            die();
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }


    return 0;
}