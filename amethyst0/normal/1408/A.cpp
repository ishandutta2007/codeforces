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

const int maxn = 110;
int a[maxn], b[maxn], c[maxn];
int ans[maxn];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
        }

        ans[0] = a[0];

        for (int i = 1; i < n - 1; i++) {
            if (a[i] != ans[i - 1]) {
                ans[i] = a[i];
            }
            else {
                ans[i] = b[i];
            }
        }

        if (a[n - 1] != ans[0] && a[n - 1] != ans[n - 2]) {
            ans[n - 1] = a[n - 1];
        }
        else if (b[n - 1] != ans[0] && b[n - 1] != ans[n - 2]) {
            ans[n - 1] = b[n - 1];
        }
        else {
            ans[n - 1] = c[n - 1];
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }

        printf("\n");
    }
}