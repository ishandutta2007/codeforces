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
#define pss pair <short, short>
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 5, maxm = 100;
int v[maxn];

int cnt[maxm];
int posit = 0;

int num[maxn + 1][maxm];

int last[2 * maxn];

int main() {
    int n;
    cin >> n;
    //n = (int)2e5;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        //v[i] = rand() % 100 + 1;
        v[i]--;
        cnt[v[i]]++;
    }

    int x = 0;

    for (int i = 0; i < maxm; i++) {
        if (cnt[i] > cnt[x]) {
            x = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i - 1] == x) {
            for (int j = 0; j < maxm; j++) {
                num[i][j] = num[i - 1][j] + 1;
            }
        }
        else {
            memcpy(num[i], num[i - 1], sizeof num[i]);
            num[i][v[i - 1]]--;
        }
    }

    int ans = 0;

    for (int i = 0; i < maxm; i++) {
        if (i == x) {
            continue;
        }

        memset(last, -1, sizeof last);
        last[maxn] = 0;

        for (int j = 1; j <= n; j++) {
            int d = num[j][i] + maxn;
            if (last[d] != -1) {
                ans = max(ans, j - last[d]);
            }
            else {
                last[d] = j;
            }
        }
    }

    cout << ans << '\n';
}