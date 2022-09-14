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

const int maxn = 310;
char s[maxn][maxn];
int cnt[3];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'X') {
                    cnt[(i + j) % 3]++;
                }
            }
        }

        int b = 0;
        for (int i = 1; i < 3; i++) {
            if (cnt[i] < cnt[b]) {
                b = i;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'X' && (i + j) % 3 == b) {
                    s[i][j] = 'O';
                }
            }

            printf("%s\n", s[i]);
        }
    }
}