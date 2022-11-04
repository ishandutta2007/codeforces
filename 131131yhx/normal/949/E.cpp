#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

#define int long long

using namespace std;

typedef long long ll;

int n, XX[200010], S[44][100010], tmp[44][100010], F[44][100010], Nxt[44][100010][3], Pr[44][100010][2], Nww;

unsigned X[200010];
bool cmp(int x, int y) {
    return S[Nww][x] > S[Nww][y];
}

#undef int
int main() {
#define int long long
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &XX[i]);
        X[i] = (unsigned) XX[i];
        for(int j = 0; j <= 42; j++) S[j][i] = X[i] & ((1 << j) - 1), tmp[j][i] = i;
    }
    for(int i = 0; i <= 22; i++) {
        Nww = i;
        sort(tmp[i] + 1, tmp[i] + n + 1, cmp);
    }
    for(int i = 0; i <= 22; i++) {
        // use 0
        int s = 0, t = 0;
        for(int j = 1; j <= n; j++)
            if((X[tmp[i][j]] >> i) & 1) s++;
        for(int j = 0; j <= n; j++) {
            if(!s) Nxt[i][j][1] = t; else Nxt[i][j][1] = -1;
            if((X[tmp[i][j + 1]] >> i) & 1) s--, t++; else s++;
        }
        // use -1
        t = 0;
        for(int j = 1; j <= n; j++) {
            if((X[tmp[i][j]] >> i) & 1) t++;
        }
        Nxt[i][0][2] = t;
        for(int j = 1; j <= n; j++) {
            if(!((X[tmp[i][j]] >> i) & 1)) t++;
            Nxt[i][j][2] = t;
        }
        // use 1
        t = 0;
        Nxt[i][0][0] = 0;
        for(int j = 1; j <= n; j++) {
            if((X[tmp[i][j]] >> i) & 1) t++;
            Nxt[i][j][0] = t;
        }
    }
    memset(F, 63, sizeof F);
    F[0][0] = 0;
    for(int i = 0; i <= 21; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k < 3; k++)
                if(Nxt[i][j][k] >= 0 && F[i + 1][Nxt[i][j][k]] > F[i][j] + (k != 1)) {
                    F[i + 1][Nxt[i][j][k]] = F[i][j] + (k != 1);
                    Pr[i + 1][Nxt[i][j][k]][0] = k;
                    Pr[i + 1][Nxt[i][j][k]][1] = j;
                }
    int mn = 1234567, v;
    for(int i = 0; i <= n; i++) if(Nxt[22][i][1] != -1) {
        if(mn > F[22][i]) {
            mn = F[22][i];
            v = i;
        }
    }
    printf("%d\n", F[22][v]);
    for(int i = 21, j = v; i >= 0; i--) {
        int p0 = Pr[i + 1][j][0], p1 = Pr[i + 1][j][1];
        if(p0 == 2) printf("%d ", -1 << i);
        else if(p0 == 0) printf("%d ", 1 << i);
        j = p1;
    }
    return 0;
}