#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <iostream>
#include <ctime>
#define M 2000010
#define int long long
#define sit set <int>::iterator
#define P 1000000007

using namespace std;

int n, k, A[M], F[M], L[M], R[M], Sz[M], ans = 0, rt = 1;

void DFS(int x) {
    if(!x) return;
    DFS(L[x]);
    DFS(R[x]);
    Sz[x] = Sz[L[x]] + Sz[R[x]] + 1;
}

int calc(int s) {
    if(s < 0) return 0;//!!!
    int t = (s - 1) / (k - 1);
    return (s * t - (k - 1 + (k - 1) * t) * t / 2) % P;
}

signed main() {
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for(int i = 2; i <= n; i++) {
        int j = i - 1;
        while(j && A[j] < A[i]) j = F[j];
        if(!j) {
            L[i] = rt;
            rt = i;
        } else {
            int l = R[j];
            R[j] = i;
            L[i] = l;
            F[l] = i;
            F[i] = j;
        }
    }
    DFS(rt);
    for(int i = 1; i <= n; i++) {
        int sm = calc(Sz[i]) - calc(Sz[L[i]]) - calc(Sz[R[i]]);
        ans = (ans + sm * A[i]) % P;
    }
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}