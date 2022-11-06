#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>
#include <bitset>
#include <unordered_map>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

pair<int, int> a[2222];

int gcd(int a, int b) {
    if (a < 0 || b < 0) {
        return gcd(abs(a), abs(b));
    }
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        sciid(x, y);
        a[i] = {x, y};
    }
    map<lint, bitset<2000> > m;
//    m.reserve(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto& x = a[i];
            auto& y = a[j];
            int aa = y.second - x.second;
            int bb = x.first - y.first;
            int cc = x.first * (x.second - y.second) + x.second * (y.first - x.first);
            if (aa == 0) {
                if (bb < 0) {
                    bb *= -1;
                    cc *= -1;
                }
                int g = bb;
                if (cc != 0) {
                    g = gcd(g, cc);
                }
                bb /= g;
                cc /= g;
            } else {
                if (aa < 0) {
                    aa *= -1;
                    bb *= -1;
                    cc *= -1;
                }
                int g = aa;
                if (bb != 0) {
                    g = gcd(g, bb);
                }
                if (cc != 0) {
                    g = gcd(g, cc);
                }
                aa /= g;
                bb /= g;
                cc /= g;
            }
            lint p = aa;
            p = p * 1000 + bb;
            p = p * 1000000 + cc;
            m[p].set(i, true);
            m[p].set(j, true);
        }
    }
    lint ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (auto& i : m) {
        lint x = i.second.count();
        if (x >= 3) {
            ans -= x * (x - 1) * (x - 2) / 6;
        }
    }
    cout << ans;
    return 0;
}