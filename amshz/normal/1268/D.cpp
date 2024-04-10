/* There's someone in my head but it's not me */ 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
 
const int N = 2e3 + 10, MOD = 998244353;
int D[N], M[N], ord[N], n; char S[N][N]; 
 
void swap(int v) {
    for (int i = 0; i < n; i++) {
        if (i == v) continue;
        if (S[v][i] == '1') {
            D[i]++, D[v]--; 
            S[v][i] = '0', S[i][v] = '1';
        } else {
            D[i]--, D[v]++;
            S[v][i] = '1', S[i][v] = '0';
        }
    }
}
 
int SCC() {
    sort(ord, ord + n, [&] (int u, int v) { return D[u] > D[v]; });
    int d = 0;
    for (int i = 1; i < n; i++) {
        d += D[ord[i - 1]];
        if (d == (n - i) * i + i * (i - 1) / 2) return 0;
    }
    return 1;
}
 
int main() {
    scanf("%d", &n); 
    iota(ord, ord + n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%s", S[i]);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (S[i][j] == '1') D[i]++;
        }
    }
    if (n <= 10) {
        int ret = n, ans = 0;
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) 
                if (i & (1 << j)) swap(j);
            if (SCC()) {
                if (__builtin_popcount(i) < ret) ret = __builtin_popcount(i), ans = 0;
                if (__builtin_popcount(i) == ret) ans++;
            }
            for (int j = 0; j < n; j++) 
                if (i & (1 << j)) swap(j);
        }
        if (!ans) return !printf("-1\n");
        int fac = 1;
        for (int i = 1; i <= ret; i++) 
            fac = 1ll * fac * i % MOD;
        printf("%d %lld\n", ret, 1ll * fac * ans % MOD);
        return 0;
    }
    if (SCC()) return !printf("0 1\n");
    int c = 0;
    for (int i = 0; i < n; i++) {
        swap(i);
        c += SCC();
        swap(i);
    }
    printf("%d %d\n", 1, c);
    return 0;
}