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

const int maxn = (int)3e5 + 10;
int v[maxn];
int r[maxn];
int l[maxn];

const int inf = (int)1e9;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        scanf("%d", &n);

        set <int> s;

        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }

        vector <int> g;

        for (int i = n - 1; i >= 0; i--) {
            while (!g.empty() && v[g.back()] >= v[i]) {
                g.pop_back();
            }

            if (!g.empty()) {
                r[i] = g.back();
            }
            else {
                r[i] = n;
            }

            g.push_back(i);
        }

        g.clear();

        for (int i = 0; i < n; i++) {
            while (!g.empty() && v[g.back()] > v[i]) {
                g.pop_back();
            }

            if (!g.empty()) {
                l[i] = g.back();
            }
            else {
                l[i] = -1;
            }

            g.push_back(i);
        }

        int lm = 0;
        int rm = n - 1;

        if ((int)s.size() == n) {
            printf("1");
        }
        else {
            printf("0");
        }

        s.clear();

        multiset <int> seg;

        for (int i = 0; i < n; i++) {
            seg.insert(v[i]);
        }

        int tot = 0;

        string f;

        for (int k = n; k >= 2; k--) {
            while (lm < n && r[lm] - lm >= k) {
                seg.erase(seg.find(v[lm]));
                s.insert(v[lm]);
                tot++;
                lm++;
            }

            while (rm >= 0 && rm - l[rm] >= k) {
                seg.erase(seg.find(v[rm]));
                s.insert(v[rm]);
                tot++;
                rm--;
            }

            assert(!seg.empty());

            if (rm - lm + 1 == k) {
                int x = *seg.begin();

                if (!s.count(x) && x <= n - k + 1 && (int)s.size() == n - k && (s.empty() || *s.rbegin() <= n - k + 1)) {
                    f.push_back('1');
                }
                else {
                    f.push_back('0');
                }
            }
            else if (rm - lm + 1 == k - 1) {
                if ((int)s.size() == n - k + 1 && (s.empty() || *s.rbegin() <= n - k + 1)) {
                    f.push_back('1');
                }
                else {
                    f.push_back('0');
                }
            }
            else {
                f.push_back('0');
            }
        }

        reverse(all(f));
        for (char c : f) {
            printf("%c", c);
        }

        printf("\n");
    }
}