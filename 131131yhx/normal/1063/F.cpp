#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#define M 1000010

using namespace std;

char ch[M];

int n, F[M], SA[M], RA[M], C[M], C1[M], C2[M], H[M], Hx[21][M], Log[M];

void getSA() {
    int *A = C1, *B = C2;
    for(int i = 1; i <= n; i++) C[A[i] = ch[i]]++;
    for(int i = 1; i <= 128; i++) C[i] += C[i - 1];
    for(int i = n; i >= 1; i--) SA[C[ch[i]]--] = i;
    int m = 128;
    for(int b = 1; m != n + 1; b *= 2) {
        int t = 0;
        for(int i = n; i > n - b; i--) B[++t] = i;
        for(int i = 1; i <= n; i++) if(SA[i] > b) B[++t] = SA[i] - b;
        for(int i = 1; i <= m; i++) C[i] = 0;
        for(int i = 1; i <= n; i++) C[A[i]]++;
        for(int i = 1; i <= m; i++) C[i] += C[i - 1];
        for(int i = n; i >= 1; i--) SA[C[A[B[i]]]--] = B[i];
        swap(A, B), m = 1;
        for(int i = 1; i <= n; i++)
            A[SA[i]] = (B[SA[i]] == B[SA[i + 1]] && B[SA[i] + b] == B[SA[i + 1] + b]) ? m : m++;
    }
    for(int i = 1; i <= n; i++) RA[SA[i]] = i;
    for(int i = 1; i <= n; i++) if(RA[i] != n) {
        H[i] = max(H[i - 1] - 1, 0);
        int j = SA[RA[i] + 1];
        while(ch[i + H[i]] == ch[j + H[i]]) H[i]++;
    }
    for(int i = 1; i <= n; i++) Hx[0][i] = H[SA[i]];
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j + (1 << i) <= n + 1; j++)
            Hx[i][j] = min(Hx[i - 1][j], Hx[i - 1][j + (1 << i - 1)]);
}

int rmq(int x, int y) {
    int b = Log[y - x];
    return min(Hx[b][x], Hx[b][y - (1 << b)]);
}

int getl(int x, int h) {
    int tmpx;
    for(int i = 20; i >= 0; i--)
        if((tmpx = x - (1 << i)) >= 1 && Hx[i][tmpx] >= h) x = tmpx;
    return x;
}

int getr(int x, int h) {
    for(int i = 20; i >= 0; i--)
        if(Hx[i][x] >= h) x += 1 << i;
    return x;

}

int Mx[1 << 21];

int getmax(int L, int R) {
    L = (L + (1 << 20)) - 2;
    R = (R + (1 << 20));
    int ans = 0;
    while((L ^ R) != 1) {
        if(!(L & 1)) ans = max(ans, Mx[L ^ 1]);
        if( (R & 1)) ans = max(ans, Mx[R ^ 1]);
        L >>= 1;
        R >>= 1;
    }
    return ans;
}

void add(int x, int y) {
    x += (1 << 20) - 1;
    while(x) {
        Mx[x] = max(Mx[x], y);
        x >>= 1;
    }
}

void add(int x) {
    add(RA[x], F[x]);
}

bool check(int l, int r) {
    int L = getl(RA[l], r - l), R = getr(RA[l], r - l);
    if(getmax(L, R) >= r - l) return 1;
    L = getl(RA[l + 1], r - l), R = getr(RA[l + 1], r - l);
    if(getmax(L, R) >= r - l) return 1;
    return 0;
}

int main() {
    for(int i = 1; (1 << i) < M; i++) Log[1 << i] = i;
    for(int i = 1; i < M; i++) if(!Log[i]) Log[i] = Log[i - 1];
    scanf("%d%s", &n, ch + 1);
    getSA();
    int r = n, ans = 0;
    for(int l = n; l >= 1; l--) {
        while(r > l && !check(l, r)) {
            add(r);
            r--;
        }
        F[l] = r - l + 1;
        ans = max(ans, F[l]);
    }
    printf("%d\n", ans);
    return 0;
}