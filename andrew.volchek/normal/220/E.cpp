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
const int maxn = 1e5 + 5;

struct tree {
    int t[maxn * 4];

    tree() {
        fill(t, t + maxn * 4, 0);
    }

    void modify(int v, int l, int r, int i, int x) {
        if (l == r) {
            t[v] += x;
            return;
        }

        t[v] += x;
        int c = (l + r) >> 1;

        if (i <= c) {
            modify(2 * v, l, c, i, x);
        } else {
            modify(2 * v + 1, c + 1, r, i, x);
        }
    }

    int sum(int v, int l, int r, int i, int j) {
        if (i <= l && r <= j) {
            return t[v];
        }

        int res = 0;
        int c = (l + r) >> 1;

        if (i <= c) {
            res += sum(2 * v, l, c, i, j);
        }

        if (c < j) {
            res += sum(2 * v + 1, c + 1, r, i, j);
        }

        return res;
    }
};

tree tl, tr;


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

    int n;
    scanf("%d", &n);
    ll k;
    cin >> k;

    vector<int> a, cc;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
        cc.pb(x);
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int &x : a) {
        x = lower_bound(cc.begin(), cc.end(), x) - cc.begin() + 1;
    }

    ll ans = 0;
    int r = n;

    ll s = 0;


    for (int i = 0; i < n; i++) {
        if (i == r) {
            s -= tl.sum(1, 0, maxn - 1, a[i] + 1, maxn - 1);
            tr.modify(1, 0, maxn - 1, a[i], -1);
            s -= tr.sum(1, 0, maxn - 1, 0, a[i] - 1);
            r++;
        }


        s += tl.sum(1, 0, maxn - 1, a[i] + 1, maxn - 1);
        s += tr.sum(1, 0, maxn - 1, 0, a[i] - 1);
        tl.modify(1, 0, maxn - 1, a[i], 1);



        while (i < r - 1 && s <= k) {
            r--;
            s += tr.sum(1, 0, maxn - 1, 0, a[r] - 1);
            s += tl.sum(1, 0, maxn - 1, a[r] + 1, maxn - 1);
            tr.modify(1, 0, maxn - 1, a[r], 1);
        }

        while (r < n && s > k) {
            s -= tl.sum(1, 0, maxn - 1, a[r] + 1, maxn - 1);
            tr.modify(1, 0, maxn - 1, a[r], -1);
            s -= tr.sum(1, 0, maxn - 1, 0, a[r] - 1);
            r++;
        }

        if (s <= k) {
            ans += n - r;
        }
    }

    cout << ans << endl;

    return 0;
}