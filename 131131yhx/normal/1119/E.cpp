#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define PII pair <int, int>
#define x first
#define y second
#define int long long

using namespace std;

int n, A[300010], Sm[300010], R[300010], Rans[300010];

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for(int i = n; i >= 1; i--) {
        int nw = R[i + 1], a = Rans[i + 1];
        if(A[i] & 1) {
            nw += A[i] / 2;
            if(!nw) R[i] = nw, Rans[i] = a;
            else R[i] = nw - 1, Rans[i] = a + 1;
        } else {
            R[i] = nw + A[i] / 2, Rans[i] = a;
        }
    }
    for(int i = 1; i <= n; i++) Sm[i] = Sm[i - 1] + A[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int lf = Sm[i - 1], ri = R[i + 1], a = Rans[i + 1];
        for(int l = 0, r = A[i]; l <= r; ) {
            int md = (l + r) / 2;
            ans = max(ans, a + min(lf + md, ri + (A[i] - md) / 2));
            if(lf + md < ri + (A[i] - md) / 2) l = md + 1; else r = md - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}