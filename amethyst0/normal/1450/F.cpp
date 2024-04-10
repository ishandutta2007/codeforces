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
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
int v[maxn];
int cnt[maxn];

int cost(int l, int r, int x) {
    if (v[l] == x && v[r] == x) {
        return 1;
    }

    if (v[l] != x && v[r] != x) {
        return -1;
    }

    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            v[i]--;
            cnt[i] = 0;
        }

        vector <pii> g;

        int l = 0;

        for (int i = 1; i < n; i++) {
            if (v[i] == v[i - 1]) {
                g.push_back(mp(l, i - 1));
                l = i;
            }
        }

        g.push_back(mp(l, n - 1));

        for (auto[l, r] : g) {
            if (v[l] == v[r]) {
                cnt[v[l]]++;
            }
        }

        pii best = mp(0, 0);

        for (int i = 0; i < n; i++) {
            best = max(best, mp(cnt[i], i));
        }

        int x = best.second;

        int tot = best.first - 1;

        for (auto[l, r] : g) {
            if (v[l] != x && v[r] != x) {
                tot--;
            }
        }

        if (tot <= 0) {
            printf("%d\n", (int)g.size() - 1);
            continue;
        }

        int numb = (int)g.size() - 1;

        for (auto[l, r] : g) {
            int pos = l;
            while (tot > 0) {
                bool ok = false;

                for (int i = l; i < r; i++) {
                    if (cost(l, i, x) + cost(i + 1, r, x) - cost(l, r, x) < 0) {
                        numb++;
                        ok = true;
                        l = i + 1;
                        tot += cost(l, i, x) + cost(i + 1, r, x) - cost(l, r, x);
                        break;
                    }
                }

                if (!ok) {
                    break;
                }
            }
        }

        if (tot > 0) {
            printf("-1\n");
            continue;
        }

        printf("%d\n", numb);
    }
}