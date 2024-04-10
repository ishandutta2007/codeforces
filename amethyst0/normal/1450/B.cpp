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

const int maxn = 110;
pii v[maxn];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &v[i].first, &v[i].second);
        }

        bool ok = false;

        for (int i = 0; i < n; i++) {
            bool can = true;

            for (int j = 0; j < n; j++) {
                if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) > k) {
                    can = false;
                }
            }

            ok |= can;
        }

        if (ok) {
            printf("1\n");
        }
        else {
            printf("-1\n");
        }
    }
}