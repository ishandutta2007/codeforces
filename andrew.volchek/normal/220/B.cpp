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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    map<int, int> b;
    vector<int> a;

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[x]++;
        a.pb(x);
    }

    vector<pair<int,int>> q;
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        q.pb(mp(l - 1, r - 1));
    }

    vector<int> c;
    for (auto kv : b) {
        if (kv.snd >= kv.fst) {
            c.pb(kv.fst);
        }
    }

    vector<int> ans(m, 0);

    for (int x : c) {
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            cnt[i] = a[i] == x;
            if (i) {
                cnt[i] += cnt[i - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            int l = q[i].fst, r = q[i].snd;

            int y = cnt[r] - (l ? cnt[l - 1] : 0);
            if (y == x) {
                ans[i]++;
            }
        }
    }

    for (int x : ans) {
        printf("%d\n", x);
    }

    return 0;
}