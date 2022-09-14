#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <unordered_map>
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
int a[maxn];

const ld eps = 1e-9;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        ld lm = 0;
        ld rm = (int)1e9 + 10;

        for (int i = 0; i < 500; i++) {
            ld m = (lm + rm) / 2;
            ld px = 0;
            ld s = 1;

            ld tm = m;

            for (int j = 0; j < n; j++) {
                if ((a[j] - px) / s < tm) {
                    tm -= (a[j] - px) / s;
                    px = a[j];
                    s++;
                }
                else {
                    px += tm * s;
                    tm = 0;
                    break;
                }
            }

            px += tm * s;

            tm = m;
            ld py = l;
            s = 1;

            for (int j = n - 1; j >= 0; j--) {
                if ((py - a[j]) / s < tm) {
                    tm -= (py - a[j]) / s;
                    py = a[j];
                    s++;
                }
                else {
                    py -= tm * s;
                    tm = 0;
                    break;
                }
            }

            py -= tm * s;

            if (px < py) {
                lm = m;
            }
            else {
                rm = m;
            }
        }

        printf("%.10lf\n", (double)lm);
    }
}