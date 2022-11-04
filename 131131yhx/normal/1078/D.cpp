#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 262144

using namespace std;

int n, A[M], L[21][M], R[21][M], MnL[21][M], MxR[21][M];

void build(int T) {
    memset(MnL[T], 63, sizeof MnL[T]);
    memset(MxR[T], 200, sizeof MxR[T]);
    for(int i = 1; i <= n; i++) MnL[T][i + 131072] = L[T][i], MxR[T][i + 131072] = R[T][i];
    for(int i = 131071; i >= 1; i--) {
        MnL[T][i] = min(MnL[T][i * 2], MnL[T][i * 2 + 1]);
        MxR[T][i] = max(MxR[T][i * 2], MxR[T][i * 2 + 1]);
    }
}

void solve(int T, int l, int r, int &mn, int &mx) {
    l += 131071, r += 131073;
    while((l ^ r) ^ 1) {
        if((l & 1) == 0) mn = min(mn, MnL[T][l ^ 1]), mx = max(mx, MxR[T][l ^ 1]);
        if((r & 1) == 1) mn = min(mn, MnL[T][r ^ 1]), mx = max(mx, MxR[T][r ^ 1]);
        l >>= 1, r >>= 1;
    }
}

void extend(int T, int l, int r, int &lx, int &rx) {
    lx = n * 3, rx = n * -3;
    if(r - l + 1 < n) {
        if(l >= 1 && r <= n) solve(T, l, r, lx, rx);
        else if(r > n) {
            r = (r - 1) % n + 1;
            int al = n * 3, ar = n * -3, bl = n * 3, br = n * -3;
            solve(T, l, n, al, ar);
            solve(T, 1, r, bl, br);
            bl += n, br += n;
            lx = min(al, bl), rx = max(ar, br);
        } else {
            l += n;
            int al = n * 3, ar = n * -3, bl = n * 3, br = n * -3;
            solve(T, l, n, al, ar);
            solve(T, 1, r, bl, br);
            al -= n, ar -= n;
            lx = min(al, bl), rx = max(ar, br);
        }
    } else swap(lx, rx);
    if(rx - lx + 1 >= n) rx = n, lx = 1;
}

int main() {
    scanf("%d", &n);
    if(n == 1) {
        puts("0");
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        L[0][i] = i - A[i], R[0][i] = i + A[i];
    }
    for(int T = 0; T < 17; T++) {
        build(T);
        for(int i = 1; i <= n; i++) extend(T, L[T][i], R[T][i], L[T + 1][i], R[T + 1][i]);
    }
    for(int i = 1; i <= n; i++) {
        int l = i, r = i, ans = 0;
        for(int T = 16; T >= 0; T--) {
            int nxl, nxr;
            extend(T, l, r, nxl, nxr);
            if(nxr - nxl + 1 < n) {
                l = nxl, r = nxr;
                ans += 1 << T;
            }
        }
        printf("%d%c", ans + 1, " \n"[i == n]);
    }
    return 0;
}