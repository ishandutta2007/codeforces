#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long

#define M 200010

using namespace std;

int n, k, m, Sm[(1 << 20) + 5], Pr[(1 << 20) + 5], L[M], R[M], C[M], P[M];

vector <int> A[1000010], B[1000010];

void add(int a, int b, int p) {
    for(int i = a; i <= 1048576; i += i & -i) {// !!!
        Sm[i] += b;
        Pr[i] += b * p;
    }
}

signed main() {
    scanf("%lld%lld%lld", &n, &k, &m);
    for(int i = 1; i <= m; i++) scanf("%lld%lld%lld%lld", &L[i], &R[i], &C[i], &P[i]), A[L[i]].push_back(i), B[R[i] + 1].push_back(i);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < B[i].size(); j++) add(P[B[i][j]], -C[B[i][j]], P[B[i][j]]);
        for(int j = 0; j < A[i].size(); j++) add(P[A[i][j]], C[A[i][j]], P[A[i][j]]);
        int tmpk = k, nw = 0;
        for(int j = 1 << 19; j >= 1; j >>= 1)
            if(Sm[nw + j] <= tmpk) {
                tmpk -= Sm[nw + j];
                ans += Pr[nw + j];
                nw += j;
            }
        if(Sm[1048576] > k) ans += tmpk * (nw + 1);//!!!
    }
    printf("%lld\n", ans);
    return 0;
}