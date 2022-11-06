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

int cg[111111];
int cn[111111];

char wc[111111];
int wi[111111];

bool cb[111111];

const string OK = "Truth";
const string LIE = "Lie";
const string ND = "Not defined";

int main() {
    sciid(n, m);
    int an = 0;
    for (int i = 0; i < n; i++) {
        char c = 0;
        while (c != '+' && c != '-') {
            scanf("%c", &c);
        }
        scid(x);
        --x;
        if (c == '+') {
            cg[x]++;
        } else {
            cn[x]++;
            an++;
        }
        wc[i] = c;
        wi[i] = x;
    }

    int cc = 0;
    int ls = -1;
    for (int i = 0; i < n; i++) {
        if ((cb[i] = (cg[i] + an - cn[i] == m))) {
            cc++;
            ls = i;
        }
    }

    if (cc == 1) {
        for (int i = 0; i < n; i++) {
            if (wc[i] == '+') {
                if (wi[i] == ls) {
                    cout << OK;
                } else {
                    cout << LIE;
                }
            } else {
                if (wi[i] == ls) {
                    cout << LIE;
                } else {
                    cout << OK;
                }
            }
            cout << "\n";
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (wc[i] == '+') {
            if (cb[wi[i]]) {
                cout << ND;
            } else {
                cout << LIE;
            }
        } else {
            if (cb[wi[i]]) {
                cout << ND;
            } else {
                cout << OK;
            }
        }
        cout << "\n";
    }

    return 0;
}