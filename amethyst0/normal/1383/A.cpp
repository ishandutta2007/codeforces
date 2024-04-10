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
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
char s[maxn], t[maxn];
bitset <maxn> b[20], c[20];

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        scanf("%s %s", s, t);

        for (int i = 0; i < 20; i++) {
            b[i].reset();
            c[i].reset();
        }

        for (int i = 0; i < n; i++) {
            b[s[i] - 'a'][i] = 1;
            c[t[i] - 'a'][i] = 1;
        }

        int ans = 0;

        for (int i = 0; i < 20; i++) {
            if (!((b[i] & c[i]) == c[i])) {
                ans = -1;
                break;
            }

            for (int j = i + 1; j < 20; j++) {
                if ((c[j] & b[i]).count()) {
                    b[j] |= b[i];
                    ans++;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}