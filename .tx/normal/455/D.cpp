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

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    int sz = (int) ceil(sqrt(n));
    vector<vector<int> > sq(sz);
    vector<vector<int> > cnt(sz, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        scid(x);
        sq[i / sz].push_back(x);
        cnt[i / sz][x]++;
    }
    scid(q);
    int lastans = 0;
    vector<int> a(n);
    while (q-- > 0) {
        sciiid(t, l, r);
        l = (l + lastans - 1) % n;
        r = (r + lastans - 1) % n;
        if (l > r) {
            swap(l, r);
        }
        if (t == 1) {
            int x;
            for (int i = 0; i < sz; i++) {
                if (sq[i].size() <= r) {
                    r -= sq[i].size();
                    continue;
                }
                x = sq[i][r];
                sq[i].erase(sq[i].begin() + r);
                cnt[i][x]--;
                break;
            }
            for (int i = 0; i < sz; i++) {
                if (sq[i].size() <= l) {
                    l -= sq[i].size();
                    continue;
                }
                sq[i].insert(sq[i].begin() + l, x);
                cnt[i][x]++;
                break;
            }
        } else {
            scid(k);
            k = (k + lastans - 1) % n + 1;
            lastans = 0;
            for (int i = 0; i < sz; i++) {
                if (sq[i].size() <= r) {
                    lastans += cnt[i][k];
                    r -= sq[i].size();
                } else {
                    for (int j = 0; j <= r; j++) {
                        lastans += sq[i][j] == k ? 1 : 0;
                    }
                    break;
                }
            }
            if (l > 0) {
                l--;
                for (int i = 0; i < sz; i++) {
                    if (sq[i].size() <= l) {
                        lastans -= cnt[i][k];
                        l -= sq[i].size();
                    } else {
                        for (int j = 0; j <= l; j++) {
                            lastans -= sq[i][j] == k ? 1 : 0;
                        }
                        break;
                    }
                }
            }
            cout << lastans << "\n";
        }
//        if (q % sz == 0) {
//            int x = 0;
//            for (int i = 0; i < sz; i++) {
//                for (int j : sq[i]) {
//                    a[x++] = j;
//                    cnt[i][j]--;
//                }
//                sq[i].clear();
//            }
//            for (int i = 0; i < n; i++) {
//                sq[i / sz].push_back(a[i]);
//                cnt[i / sz][a[i]]++;
//            }
//        }
    }

    return 0;
}