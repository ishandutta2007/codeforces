#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 2010, mod = (int)1e9 + 7;
pair <pii, int> v[maxn];

int len;

int add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

int mul(int x, int y) {
    return (ll)x * y % mod;
}

struct vt {
    int w;
    int maxr;
    int minr;
    int st;
    int ans;
};

vector <vt> g;

vt t[4 * maxn];

vt recalc(vt a, vt b) {
    vt ans;
    ans.st = -1;
    ans.ans = add(a.ans, b.ans);
    ans.w = add(a.w, b.w);
    ans.maxr = max(a.maxr, b.maxr);
    ans.minr = min(a.minr, b.minr);
    return ans;
}

void build(int it, int l, int r) {
    if (l == r) {
        t[it] = g[l];
    }
    else {
        int m = (l + r) >> 1;

        build(2 * it, l, m);
        build(2 * it + 1, m + 1, r);
        t[it] = recalc(t[2 * it], t[2 * it + 1]);
    }
}

void sets(int it, int l, int r, int x) {
    t[it].maxr = x;
    t[it].minr = x;
    t[it].st = x;
    t[it].ans = mul(sub(len, x), t[it].w);
}

void push(int it, int l, int r) {
    if (t[it].st != -1) {
        int m = (l + r) >> 1;
        sets(2 * it, l, m, t[it].st);
        sets(2 * it + 1, m + 1, r, t[it].st);
        t[it].st = -1;
    }
}

void change(int it, int l, int r, int pos, int lm, int rm) {
    if (t[it].maxr < lm || t[it].minr >= rm) {
        return;
    }

    if (l != r) {
        push(it, l, r);
    }

    if (r < pos) {
        return;
    }

    int m = (l + r) >> 1;

    if (l < pos) {
        change(2 * it, l, m, pos, lm, rm);
        change(2 * it + 1, m + 1, r, pos, lm, rm);
        t[it] = recalc(t[2 * it], t[2 * it + 1]);
    } else if (lm <= t[it].minr && t[it].maxr < rm) {
        sets(it, l, r, rm);
    }
    else {
        change(2 * it, l, m, pos, lm, rm);
        change(2 * it + 1, m + 1, r, pos, lm, rm);
        t[it] = recalc(t[2 * it], t[2 * it + 1]);
    }
}

int tot = 0;
int used[maxn];
multiset <int> cl[maxn];

void change(int pos, int x) {
    if (used[pos]) {
        tot--;
    }

    used[pos] += x;

    if (used[pos]) {
        tot++;
    }
}

int main() {
    int n, k;
    cin >> n >> k >> len;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v[i].first.first, &v[i].first.second, &v[i].second);
        v[i].second--;
    }

    sort(v, v + n);
    int res = 0;

    for (int i = 0; i < n; i++) {
        tot = 0;
        memset(used, 0, sizeof used);
        vector <pair <pii, int> > f;

        for (int j = 0; j < k; j++) {
            cl[j].clear();
            cl[j].insert(len);
        }

        for (int j = i; j < n; j++) {
            f.push_back(mp(mp(v[j].first.second, v[j].second), j));
            cl[v[j].second].insert(v[j].first.second);
        }

        sort(all(f));
        g.clear();
        g.resize(f.size());
        int rm = 0;

        for (int j = 0; j < (int)f.size(); j++) {
            while (rm < (int)f.size() && tot < k) {
                change(f[rm].first.second, 1);
                rm++;
            }

            g[j].st = -1;
            g[j].maxr = g[j].minr = (tot == k ? f[rm - 1].first.first : len);
            g[j].w = (j == 0 ? f[j].first.first + 1 : f[j].first.first - f[j - 1].first.first);
            g[j].ans = mul(g[j].w, sub(len, g[j].maxr));
            change(f[j].first.second, -1);
            assert(rm > j);
        }

        build(1, 0, (int)f.size() - 1);

        int ans = mul(t[1].ans, sub(len, v[n - 1].first.first));

        for (int j = n - 1; j > i; j--) {
            int y = v[j].first.second;
            int c = v[j].second;
            auto itr = cl[c].lower_bound(y);
            int pos = 0;
            if (itr != cl[c].begin()) {
                itr--;
                pos = lower_bound(all(f), mp(mp(*itr, c), (int)1e9)) - f.begin();
                itr++;
            }
            assert(itr != cl[c].end());
            itr++;
            assert(itr != cl[c].end());
            change(1, 0, (int)f.size() - 1, pos, y, *itr);
            itr--;
            cl[c].erase(itr);
            ans = add(ans, mul(t[1].ans, v[j].first.first - v[j - 1].first.first));
        }

        ans = mul(ans, (i ? v[i].first.first - v[i - 1].first.first : v[i].first.first + 1));
        res = add(res, ans);
    }

    cout << res << '\n';
}