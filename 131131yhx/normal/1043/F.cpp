#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#define M 600010

using namespace std;

int n, A[M], Lw[M];

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

vector <int> V[M];

int Num[M], ans = 23333;

signed main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int g = A[1];
    for(int i = 2; i <= n; i++) g = gcd(A[i], g);
    if(g != 1) {
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= n; i++) if(A[i] == 1) {
        puts("1");
        return 0;
    }
    Lw[1] = 0;
    for(int i = 2; i <= 300000; i++) {
        if(!Lw[i]) Lw[i] = i; else continue;
        for(int j = i + i; j <= 300000; j += i)
            if(!Lw[j]) Lw[j] = i;
    }
    for(int i = 1; i <= n; i++) {
        int a = A[i];
        while(a != 1) {
            if(V[i].empty() || V[i].back() != Lw[a]) V[i].push_back(Lw[a]);
            a /= Lw[a];
        }
        int sz = V[i].size();
        for(int j = 0; j < (1 << sz); j++) {
            int tmp = 1;
            for(int k = 0; k < sz; k++) if((j >> k) & 1) tmp *= V[i][k];
            Num[tmp]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        static int F[1 << 6], G[1 << 6], H[1 << 6], Pai[1 << 6];
        int sz = V[i].size();
        memset(F, 63, sizeof F);
        F[0] = 1;
        memset(G, 0, sizeof G);
        memset(H, 0, sizeof H);
        for(int j = 0; j < (1 << sz); j++) {
            int tmp = 1;
            for(int k = 0; k < sz; k++) if((j >> k) & 1) tmp *= V[i][k];
            //Pai[j] = tmp;
            G[j] = Num[tmp];
        }
        for(int j = 0; j < (1 << sz); j++) {
            int sm = 0;
            for(int k = j; k; k = (k - 1) & j)
                sm += (__builtin_popcount(k) & 1 ? 1 : -1) * G[k];
            if(sm < n) H[j] = 1; else H[j] = 0;
        }
        for(int j = 1; j < (1 << sz); j++)
            for(int k = (j - 1) & j; ; k = (k - 1) & j) {
                // no if at the left of the bracket
                if(H[j - k]) F[j] = min(F[j], F[k] + 1);
                if(!k) break;
            }
        ans = min(ans, F[(1 << sz) - 1]);
    }
    printf("%d\n", ans);
    return 0;
}