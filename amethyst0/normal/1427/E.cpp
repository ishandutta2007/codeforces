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
typedef long double ld;
#define uint unsigned int

const int maxlog = 61;

vector <pair <int, ll> > cur;

vector <pll> ans;

bool add(ll x, bool nd = true) {
    for (auto[b, y] : cur) {
        if ((x >> b) & 1) {
            ans.push_back(mp(x, y));
            x ^= y;
        }
    }

    if (x == 0) {
        return false;
    }

    if (nd) {
        int b = maxlog - 1;

        while (!((x >> b) & 1)) {
            b--;
        }

        for (auto &[f, y] : cur) {
            if ((y >> b) & 1) {
                ans.push_back(mp(y, x));
                y ^= x;
            }
        }

        cur.push_back(mp(b, x));
    }

    return true;
}

vector <pair <char, pll> > res;

int main() {
    int x;
    cin >> x;

    ll z = x;

    for (int i = 0; i < 30; i++) {
        res.push_back(mp('+', mp(z, z)));
        z *= 2;
    }

    for (int i = 1; i <= (int)1e7; i++) {
        ans.clear();
        if (add((ll)i * x)) {
            ll cur = 0;

            for (int j = 0; j < 30; j++) {
                if ((i >> j) & 1) {
                    if (cur != 0) {
                        res.push_back(mp('+', mp(cur, (ll)x * (1ll << j))));
                    }

                    cur += (ll)x * (1ll << j);
                }
            }

            for (pll f : ans) {
                res.push_back(mp('^', f));
            }

            if (!add(1, false)) {
                break;
            }
        }
    }

    cout << res.size() << '\n';

    for (auto g : res) {
        printf("%lld %c %lld\n", g.second.first, g.first, g.second.second);
    }
}