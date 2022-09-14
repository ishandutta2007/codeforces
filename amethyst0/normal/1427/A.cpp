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

const int maxn = 55;
int v[maxn];

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n;
        scanf("%d", &n);

        int sum = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            sum += v[i];
        }

        if (sum == 0) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        for (int i = 0; i < n; i++) {
            if ((sum > 0 && v[i] > 0) || (sum < 0 && v[i] < 0)) {
                printf("%d ", v[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if ((sum > 0 && v[i] <= 0) || (sum < 0 && v[i] >= 0)) {
                printf("%d ", v[i]);
            }
        }

        printf("\n");
    }
}