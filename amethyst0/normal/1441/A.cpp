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
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10, mod = 998244353;
int a[maxn], b[maxn];
int pos[maxn];

vector <int> v;

int numb(int l, int r) {
    return lower_bound(all(v), r + 1) - lower_bound(all(v), l);
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
            pos[a[i]] = i;
        }

        v.clear();

        for (int i = 0; i < k; i++) {
            scanf("%d", &b[i]);
            b[i]--;
            v.push_back(pos[b[i]]);
        }

        sort(all(v));

        set <int> s;

        int ans = 1;

        for (int i = k - 1; i >= 0; i--) {
            int p = pos[b[i]];

            auto it = s.lower_bound(p);

            int r = n - 1;
            if (it != s.end()) {
                r = (*it) - 1;
            }

            int l = 0;

            if (it != s.begin()) {
                it--;
                l = (*it) + 1;
            }

            int cnt = 0;

            if (numb(p, r) != r - p + 1) {
                cnt++;
            }

            if (numb(l, p) != p - l + 1) {
                cnt++;
            }

            ans = ans * cnt % mod;
            s.insert(p);
        }

        cout << ans << '\n';
    }
}