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
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

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

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 200005;

int a[maxn];
vector<int> s[maxn];

int b[maxn];
int find(int v) {
    if (b[v] == v) {
        return v;
    }
    return b[v] = find(b[v]);
}

bool uniteD(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (u > v) {
            swap(u, v);
        }
        b[u] = v;
    }
}

int n;

void unite(int u, int v) {
    u = a[u], v = a[v];

    if (u == v) {
        return;
    }

    if (s[u].size() > s[v].size()) {
        swap(u, v);
    }

    for (int x : s[u]) {
        s[v].pb(x);
        a[x] = v;

        if (x + 1 < n && a[x] == a[x + 1]) {
            uniteD(x, x + 1);
        }

        if (x - 1 >= 0 && a[x - 1] == a[x]) {
            uniteD(x - 1, x);
        }
    }

    s[u].clear();
}

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        a[i] = b[i] = i;
        s[i].pb(i);
    }

    while (m--) {
        int t;
        scanf("%d", &t);
        int u, v;
        scanf("%d %d", &u, &v);

        if (t == 1) {
            unite(u, v);
        } else if (t == 2) {
            while (true) {
                int r = find(u);
                if (r + 1 <= v) {
                    uniteD(u, r + 1);
                    unite(a[u], a[r + 1]);
                } else {
                    break;
                }
            }
        } else {
            if (a[u] == a[v]) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}