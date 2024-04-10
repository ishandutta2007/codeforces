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

const int maxn = (int)2e5 + 10;
pii v[maxn];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll w;
        cin >> n >> w;
        ll st = w;

        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i].first);
            v[i].second = i;
        }

        sort(v, v + n);
        reverse(v, v + n);

        vector <int> g;

        for (int i = 0; i < n; i++) {
            if (v[i].first <= w) {
                w -= v[i].first;
                g.push_back(v[i].second + 1);
            }
        }

        if (2 * (st - w) < st) {
            printf("-1\n");
        }
        else {
            printf("%d\n", (int)g.size());
            sort(all(g));
            for (int x : g) {
                printf("%d ", x);
            }

            printf("\n");
        }
    }
}