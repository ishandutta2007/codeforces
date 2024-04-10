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

const int maxn = (int)2e5 + 10;
char s[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    int t;

    cin >> t;

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);

        vector <int> cnt;

        int pos = 0;

        int tot = 0;

        while (pos < n && s[pos] == 'L') {
            pos++;
            tot++;
        }

        int sc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (i == 0 || s[i - 1] != 'W') {
                    sc++;
                }
                else {
                    sc += 2;
                }
            }
        }

        if (pos != n) {
            int cur = 0;
            for (int i = pos; i < n; i++) {
                if (s[i] == 'L') {
                    tot++;
                    cur++;
                }
                else {
                    if (cur != 0) {
                        cnt.push_back(cur);
                        cur = 0;
                    }
                }
            }
        }

        k = min(k, tot);

        if (k == 0) {
            printf("%d\n", sc);
            continue;
        }

        if (sc == 0) {
            printf("%d\n", 2 * k - 1);
            continue;
        }

        sort(all(cnt));

        int ans = sc;
        ans += 2 * k;
        for (int x : cnt) {
            if (x <= k) {
                k -= x;
                ans++;
            }
        }

        printf("%d\n", ans);
    }
}