#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int P = 998244353;
const int V = 200100;

LL Pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y /= 2;
    }
    return res;
}

struct Node {
    int l, r;
    int L, R;
}tr[V * 4];

int s[V], p[V];
const int oo = 1000000000;
void push(int id) {
    tr[id].L = min(tr[id * 2].L, tr[id * 2 + 1].L);
    tr[id].R = max(tr[id * 2].R, tr[id * 2 + 1].R);
}

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    if (l == r) {
        if (s[l]) {
            tr[id].L = l;
            tr[id].R = l;
        } else {
            tr[id].L = oo;
            tr[id].R = -oo;
        }
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    push(id);
}

void update(int id, int pos) {
    if (tr[id].l == pos && tr[id].r == pos) {
        if (s[tr[id].l]) {
            tr[id].L = pos;
            tr[id].R = pos;
        } else {
            tr[id].L = oo;
            tr[id].R = -oo;
        }
        return;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    if (pos <= mid) update(id * 2, pos);
    else update(id * 2 + 1, pos);
    push(id);
}

int readL(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].L;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return readL(id * 2, l, r);
    else if(l > mid) return readL(id * 2 + 1, l, r);
    else {
        int a = readL(id * 2, l, mid);
        int b = readL(id * 2 + 1, mid + 1, r);
    //printf("RL %d %d %d %d %d\n", id, tr[id].l, tr[id].r, l, r);
        //printf("%d %d\n", a, b);
        return min(a, b);
    }
}

int readR(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].R;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return readR(id * 2, l, r);
    else if(l > mid) return readR(id * 2 + 1, l, r);
    else {
        int a = readR(id * 2, l, mid);
        int b = readR(id * 2 + 1, mid + 1, r);
        return max(a, b);
    }
}

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int S[V], M[V];
int n, Q, x;
int main() {
    while (~scanf("%d%d", &n, &Q)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i]);
            int g = gcd(p[i], 100);
            p[i] = (LL) p[i] / g * Pow(100 / g, P - 2) % P;
        }
        p[n + 1] = 1;
        for (int i = 1; i <= n + 1; ++i) s[i] = 0;
        s[1] = s[n + 1] = 1;
        M[0] = 1;
        for (int i = 1; i <= n + 1; ++i) M[i] = (LL) M[i - 1] * p[i] % P;
        S[0] = 1;
        for (int i = 1; i <= n + 1; ++i) S[i] = (S[i - 1] + M[i]) % P;
        init(1, 1, n + 1);
        int ans = 0;
        ans = (LL) (S[n - 1]) * Pow(M[n], P - 2) % P;
        //for (int i = 1; i <= n; ++i) printf("%d ", S[i] * Pow(M[i], P - 2) % P); puts("");
        //printf("%d\n", Pow(Pow(2, P - 2), P - 2));
        //printf("%d\n", ans);
        while (Q--) {
            scanf("%d", &x);
            int L = readR(1, 1, x - 1);
            int R = readL(1, x + 1, n + 1);
            //printf("lr %d %d %d\n", L, R, n);
            int pl = (LL) (S[x - 2] - (L==1?0:S[L - 2]) + P) * Pow(M[x - 1], P - 2) % P;// * M[L - 1] % P * Pow(M[L - 2], P - 2) % P;
            int pr = (LL) (S[R - 2] - S[x - 2] + P) * Pow(M[R - 1], P - 2) % P;// * M[x - 1] % P * Pow(M[x - 2], P - 2) % P;
            int pa = (LL) (S[R - 2] - (L==1?0:S[L - 2]) + P) * Pow(M[R - 1], P - 2) % P;// * M[L - 1] % P * Pow(M[L - 2], P - 2) % P;
            //printf("P %d %d %d\n", pl, pr, pa);
            if (s[x] == 0) ans = ((LL) ans + pl + pr - pa + P) % P;
            else ans = ((LL) ans + pa - pl - pr + P + P) % P;
            s[x] ^= 1;
            update(1, x);
            printf("%d\n", ans);
        }
    }
    return 0;
}

/*
2 2
50 50
2
2

5 5
10 20 30 40 50
2
3
4
5
3

*/