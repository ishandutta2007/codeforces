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
#include <limits>
#include <tuple>
#include <complex>

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

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 2e5 + 5;
int p[20][maxn];
int d[maxn];

int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }
    int diff = d[a] - d[b];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            a = p[i][a];
        }
    }

    if (a == b) {
        return a;
    }

    int ans = 0;
    for (int i = 19; i >= 0; i--) {
        if (p[i][a] == p[i][b]) {
            ans = p[i][a];
        } else {
            a = p[i][a];
            b = p[i][b];
        }
    }

    return ans;
}

int dist(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    int u = 1, v = 1;
    for (int i = 0; i < 20; i++) {
        p[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (i > 2) {
            printf(" ");
        }
        int x;
        scanf("%d", &x);
        p[0][i] = x;
        d[i] = d[x] + 1;
        for (int j = 1; j < 20; j++) {
            p[j][i] = p[j - 1][p[j - 1][i]];
        }

        int curr = dist(u, v);
        if (dist(u, i) > curr) {
            v = i;
        }


        curr = dist(u, v);

        if (dist(v, i) > curr) {
            u = i;
        }

        printf("%d", dist(u, v));
    }
    printf("\n");


    return 0;
}