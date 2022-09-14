#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
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
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;

vector <pii> ans;

void build(int l, int d) {
    int cur = 1;

    while (cur < d) {
        for (int i = l; i < l + d; i += 2 * cur) {
            for (int j = i; j < i + cur; j++) {
                ans.push_back(mp(j, j + cur));
            }
        }

        cur <<= 1;
    }
}

int main() {
    int n;

    cin >> n;

    vector <pii> v;
    int p = 0;

    for (int i = 0; i < 20; i++) {
        if ((n >> i) & 1) {
            v.push_back(mp(p, 1 << i));
            p += (1 << i);
        }
    }

    p = v.back().first;
    vector <int> w;

    for (int i = 0; i < (int)v[0].second; i++) {
        w.push_back(v[0].first + i);
    }

    for (pii f : v) {
        build(f.first, f.second);
    }

    for (int i = 0; i < (int)v.size() - 2; i++) {
        int x = (int)w.size();
        int y = v[i + 1].second;

        int lp = p;

        while (x < y) {
            vector <int> h;
            for (int j : w) {
                ans.push_back(mp(j, p));
                h.push_back(p++);
            }

            for (int a : h) {
                w.push_back(a);
            }

            x *= 2;
        }

        for (int j = 0; j < x; j++) {
            ans.push_back(mp(w[j], v[i + 1].first + j));
            w.push_back(v[i + 1].first + j);
        }
    }

    cout << ans.size() << '\n';

    for (pii a : ans) {
        printf("%d %d\n", a.first + 1, a.second + 1);
    }
}