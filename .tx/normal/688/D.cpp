#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int f[1111111];
int to[1111111];

int allc[1111111];
int cc[1111111];
vector<int> wasc;

void fillcc(int x) {
    if (x < 2) {
        return;
    }
    const int fx = f[x];
    if (cc[fx] == 0) {
        wasc.push_back(fx);
    }
    cc[fx]++;
    fillcc(to[x]);
}

int main() {
    f[1] = 1;
    for (int i = 2; i < 1111111; i++) {
        if (f[i] == 0) {
            f[i] = i;
            for (int j = i + i; j < 1111111; j += i) {
                if (f[j] == 0) {
                    f[j] = i;
                    to[j] = j / i;
                }
            }
        }
    }

    sciid(n, k);
    for (int i = 0; i < n; i++) {
        scid(x);
        fillcc(x);
        for (int c : wasc) {
            allc[c] = max(allc[c], cc[c]);
            cc[c] = 0;
        }
        wasc.clear();
    }

    fillcc(k);
    for (int i : wasc) {
        if (cc[i] > allc[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";


    return 0;
}