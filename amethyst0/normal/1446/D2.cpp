#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define pss pair <short, short>
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10;
int v[maxn];

int t[4 * maxn];
int st[4 * maxn];

void sets(int it, int x) {
    st[it] += x;
    t[it] += x;
}

void push(int it) {
    if (st[it] != 0) {
        sets(2 * it, st[it]);
        sets(2 * it + 1, st[it]);
        st[it] = 0;
    }
}

void change(int it, int l, int r, int lm, int rm, int x) {
    if (l == lm && r == rm) {
        sets(it, x);
    }
    else {
        push(it);
        int m = (l + r) >> 1;

        if (rm <= m) {
            change(2 * it, l, m, lm, rm, x);
        }
        else if (lm > m) {
            change(2 * it + 1, m + 1, r, lm, rm, x);
        }
        else {
            change(2 * it, l, m, lm, m, x);
            change(2 * it + 1, m + 1, r, m + 1, rm, x);
        }

        t[it] = min(t[2 * it], t[2 * it + 1]);
    }
}

int getval(int it, int l, int r, int pos) {
    if (l == r) {
        return t[it];
    }
    else {
        int m = (l + r) >> 1;
        push(it);

        if (pos <= m) {
            return getval(2 * it, l, m, pos);
        }
        else {
            return getval(2 * it + 1, m + 1, r, pos);
        }
    }
}

int go(int it, int l, int r, int x) {
    if (l == r) {
        if (t[it] <= x) {
            return l;
        }

        return l + 1;
    }

    push(it);
    int m = (l + r) >> 1;
    if (t[2 * it] <= x) {
        return go(2 * it, l, m, x);
    }

    return go(2 * it + 1, m + 1, r, x);
}

int cnt[maxn];
vector <int> g[maxn];

int ans = 0;

int main() {
    int n;
    cin >> n;
    //n = (int)2e5;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        //v[i] = rand() % 100 + 1;
        v[i]--;
        cnt[v[i]]++;
        g[v[i]].push_back(i);
    }

    int x = 0;

    for (int i = 0; i < maxn; i++) {
        if (cnt[i] > cnt[x]) {
            x = i;
        }
    }

    for (int p : g[x]) {
        change(1, 0, n - 1, p, n - 1, -1);
    }

    for (int i = 0; i < maxn; i++) {
        if (i == x) {
            continue;
        }

        if (g[i].empty()) {
            continue;
        }

        int bal = 0;
        int numb = 0;

        for (int p : g[i]) {
            change(1, 0, n - 1, p, n - 1, 1);
            bal++;

            int pos = lower_bound(all(g[x]), p) - g[x].begin();
            int ad = 0;
            if (pos == (int)g[x].size()) {
                ad += n - p - 1;
            }
            else {
                ad += g[x][pos] - 1 - p;
            }

            int y = getval(1, 0, n - 1, p);
            int wh = go(1, 0, n - 1, y);

            if (y >= 0) {
                ans = max(ans, ad + p + 1);
            }
            else if (wh < p) {
                ans = max(ans, ad + p - wh);
            }

            while (bal > numb && pos < (int)g[x].size() && (bal == (int)g[i].size() || g[x][pos + 1] < g[i][bal])) {
                int p = g[x][pos];
                pos++;
                numb++;
                int ad = 0;
                if (pos == (int)g[x].size()) {
                    ad += n - p - 1;
                }
                else {
                    ad += g[x][pos] - 1 - p;
                }

                int y = getval(1, 0, n - 1, p);
                int wh = go(1, 0, n - 1, y);

                if (y >= 0) {
                    ans = max(ans, ad + p + 1);
                }
                else if (wh < p) {
                    ans = max(ans, ad + p - wh);
                }
            }
        }

        for (int p : g[i]) {
            change(1, 0, n - 1, p, n - 1, -1);
        }
    }

    cout << ans << '\n';
}