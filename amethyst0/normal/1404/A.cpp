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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)3e5 + 10;
char s[maxn];

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf(" %s", s);
        bool ok = true;

        for (int i = 0; i < k; i++) {
            int ans = -1;

            for (int j = i; j < n; j += k) {
                if (s[j] != '?') {
                    if (ans == -1) {
                        ans = s[j] - '0';
                    }
                    else if (ans != s[j] - '0'){
                        ok = false;
                    }
                }
            }

            if (ans != -1) {
                for (int j = i; j < n; j += k) {
                    s[j] = ans + '0';
                }
            }
        }

        if (!ok) {
            printf("NO\n");
            continue;
        }

        int a = 0, b = 0, c = 0;

        for (int i = 0; i < k; i++) {
            if (s[i] == '?') {
                c++;
            }
            else if (s[i] == '0') {
                a++;
            }
            else {
                b++;
            }
        }

        if (a + c >= b && b + c >= a) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}