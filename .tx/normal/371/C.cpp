#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    init_cin();
    string s;
    cin >> s;
    int sb = 0, ss = 0, sc = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            sb++;
        } else if (s[i] == 'S') {
            ss++;
        } else {
            sc++;
        }
    }
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    lint p;
    cin >> p;
    lint l = 0;
    lint r = 1e15;
    while (l + 1 < r) {
        lint m = (l + r) / 2;
        lint bb = max(0LL, m * sb - nb);
        lint bs = max(0LL, m * ss - ns);
        lint bc = max(0LL, m * sc - nc);
        if (bb * pb + bs * ps + bc * pc > p) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
    return 0;
}