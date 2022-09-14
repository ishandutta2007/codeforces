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
int cnt[2][3];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        memset(cnt, 0, sizeof cnt);
        int k = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'X') {
                    cnt[0][(i + j) % 3]++;
                    k++;
                }
                else if (s[i][j] == 'O') {
                    cnt[1][(i + j) % 3]++;
                    k++;
                }
            }
        }

        int a = 0;
        int b = 1;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (x == y) {
                    continue;
                }

                if (cnt[0][x] + cnt[1][y] < cnt[0][a] + cnt[1][b]) {
                    a = x;
                    b = y;
                }
            }
        }

        assert(cnt[0][a] + cnt[1][b] <= k / 3);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'X' && (i + j) % 3 == a) {
                    s[i][j] = 'O';
                }
                else if (s[i][j] == 'O' && (i + j) % 3 == b) {
                    s[i][j] = 'X';
                }
            }

            printf("%s\n", s[i]);
        }
    }
}