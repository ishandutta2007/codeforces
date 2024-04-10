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

const int maxn = (int)3e5 + 10;
int v[maxn];

int t[maxn];

void change(int pos) {
    for (; pos < maxn; pos = pos |= pos + 1) {
        t[pos]++;
    }
}

int go(int pos) {
    int ans = 0;

    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ans += t[pos];
    }
    return ans;
}

int go(int l, int r) {
    return go(r) - go(l - 1);
}

int res[maxn];

int main() {
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        v[i] = i + 1 - v[i];
    }

    vector <pair <pii, int> > qw;
    int it = -1;
    int qq = q;

    while (q--) {
        it++;
        int l, r;
        scanf("%d %d", &l, &r);
        r = n - 1 - r;
        qw.push_back(mp(mp(l, r), it));
    }

    sort(all(qw), [&](pair <pii, int> a, pair <pii, int> b) {
        return a.first.second < b.first.second;
    });

    int pos = 0;

    for (int i = 0; i < n; i++) {
        int l = -1;
        int r = i;

        if (v[i] < 0) {
            while (pos < (int)qw.size() && qw[pos].first.second == i) {
                int l = qw[pos].first.first;
                int r = qw[pos].first.second;

                res[qw[pos].second] = go(l, r);
                pos++;
            }
            continue;
        }

        while (l != r) {
            int m = (l + r + 1) >> 1;
            int res = go(m, i);
            if (res >= v[i]) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }

        if (l != -1) {
            change(l);
        }

        while (pos < (int)qw.size() && qw[pos].first.second == i) {
            int l = qw[pos].first.first;
            int r = qw[pos].first.second;

            res[qw[pos].second] = go(l, r);
            pos++;
        }
    }

    for (int i = 0; i < qq; i++) {
        printf("%d\n", res[i]);
    }
}