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

static const int N = 111111;
int a[N];
int p[N];


int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            p[i] = b.size();
            b.push_back(a[i]);
        } else {
            p[i] = b.size() - 1;
        }
    }

    n = b.size();
    vector<int> t(n);
    vector<int> ps(n);
    for (int i = 1; i + 1 < n; i++) {
        ps[i] = ps[i - 1];
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) {
            ps[i]++;
        }
    }

    while (m-- > 0) {
        sciid(l, r);
        --l; --r;
        l = p[l];
        r = p[r];
        if (r - l <= 1) {
            cout << "Yes\n";
            continue;
        }
        int ct = ps[r - 1] - ps[l];
        cout << (ct == 0 ? "Yes" : "No") << "\n";
    }


    return 0;
}