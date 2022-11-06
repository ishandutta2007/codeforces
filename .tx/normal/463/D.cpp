#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int a[11][1111];
int b[11][1111];
int b0[1111];

int p[11][1111];
int d[1111];

int main() {
    sciid(n, k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            sci(a[i][j]);
            --a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        b0[a[0][i]] = i;
    }

//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < n; j++) {
//            b[i][j] = a[i][b0[j]];
//            cerr << b[i][j] << " ";
//        }
//        cerr << endl;
//    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            p[i][a[i][j]] = j;
        }
    }

    d[0] = 1;
    for (int i = 1; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            bool ok = true;
            for (int t = 0; t < k; t++) {
                if (p[t][a[0][j]] > p[t][a[0][i]]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    cout << (*max_element(d, d + n));


    return 0;
}