#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

typedef long long ll;

int n, d, b, A[100010], B[100010], C[100010], oriA[100010];

int Abs(int x) {return x < 0 ? -x : x;}

int CC(int x, int w) {
    memcpy(A, oriA, sizeof A);
    memset(B, 0, sizeof B);
    int rl = x, rr = n * b - x, tmp, tl = w, tr = n - w + 1;
    for(int i = 1; i <= n; i++) {
        int s = min(rl, A[i]);
        rl -= s;
        A[i] -= s;
        if(Abs(i - (tl + 1)) <= (tl + 1) * d) B[tl + 1] += s;
        else B[i - (tl + 1) * d] += s;
        while(tl < (n + 1) / 2 && B[tl + 1] >= b) {
            B[tl + 2] += B[tl + 1] - b;
            tl++;
        }
    }
    if(tl != (n + 1) / 2) return -1;
    memset(C, 0, sizeof C);
    for(int i = n; i >= 1;i--) {
        int s = min(rr, A[i]);
        rr -= s;
        A[i] -= s;
        if(Abs(i - (tr - 1)) <= (n - tr + 2) * d) C[tr - 1] += s;
        else C[i + (n - tr + 2) * d] += s;
        while(tr > (n + 1) / 2 + 1 && C[tr - 1] >= b) {
            C[tr - 2] += C[tr - 1] - b;
            tr--;
        }
    }
    if(tr != (n + 1) / 2 + 1) return 1;
    return 0;
}

bool check(int x) {
    for(int l = 0, r = n * b; l <= r; ) {
        int tmp = CC((l + r) / 2, x);
        if(tmp == 0) return 1;
        if(tmp == -1) l = (l + r) / 2 + 1; else r = (l + r) / 2 - 1;
    }
    return 0;
}

#undef int
int main() {
#define int long long
    scanf("%lld%lld%lld", &n, &d, &b);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    memcpy(oriA, A, sizeof A);
    int ans = n / 2 + 1;
    for(int l = 0, r = n / 2; l <= r; ) {
        int md = (l + r) / 2;
        if(check(md)) {
            ans = md;
            r = md - 1;
        } else l = md + 1;
    }
    printf("%lld\n", ans);
    return 0;
}