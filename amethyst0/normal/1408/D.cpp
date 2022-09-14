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

const int maxn = 2010;
pair <int, int> a[maxn], b[maxn];

const int maxc = (int)1e6 + 10;
int res[maxc];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &b[i].first, &b[i].second);
    }

    sort(a, a + n);
    sort(b, b + m);

    vector <pii> g;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i].first <= b[j].first && a[i].second <= b[j].second) {
                g.push_back(mp(b[j].first - a[i].first, b[j].second - a[i].second));
            }
        }
    }

    memset(res, -1, sizeof res);

    for (pii f : g) {
        res[f.first] = max(res[f.first], f.second);
    }

    for (int i = maxc - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    int ans = (int)1e9;

    for (int i = 0; i < maxc; i++) {
        ans = min(ans, i + res[i] + 1);
    }

    cout << ans << '\n';
}