#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <bitset>
#define P 998244353
#define PI pair <int, int>
#define f first
#define s second
#define M 777777

using namespace std;

typedef long long ll;

int n;

vector <int> V(0);

int A[M], mn, mx, l0 = 0, o = 0;

int B[M], S[M];

int Tr[M];

void add(int x, int v) {
    for(int i = x; i <= 524287; i += i & -i) Tr[i] += v;
}

int ask(int x) {
    int ans = 0;
    for(int i = x; i; i -= i & -i) ans += Tr[i];
    return ans;
}

int getv(int *A, int x) {
    return A[x] - ask(x);
}

void getlr(int *A, int x, int lb, int rb, int &l, int &r) {
    l = x, r = x;
    int nwv = getv(A, x);
    r = 0;
    int accu = 0;
    for(int i = 18; i >= 0; i--) {
        int tmp = r + (1 << i);
        if(tmp <= rb && (tmp < lb || (A[tmp] - (accu + Tr[tmp]) <= nwv))) r = tmp, accu += Tr[tmp];
    }
    l = 0, accu = 0;
    for(int i = 18; i >= 0; i--) {
        int tmp = l + (1 << i);
        if(tmp <= rb && (tmp < lb || (A[tmp] - (accu + Tr[tmp]) < nwv))) l = tmp, accu += Tr[tmp];
    }
    l++;
}

int Do(int x, bool b = 0) {
    if(x < 0 || x > n) return -1;
    static int A[M];
    for(int i = 1; i <= n; i++) A[i] = ::A[i];
    A[n + 1] = x;
    n++;
    sort(A + 1, A + n + 1);
    memset(Tr, 0, sizeof Tr);
    memset(S, 0, sizeof S);
    int lb = 0;
    for(int i = n; i >= 1; i--) {
        int x = getv(A, i);
        if(x == 0) break;
        int l, r;
        while(lb < i && getv(A, lb + 1) == 0) lb++;
        if(lb >= i - 1) break;
        getlr(A, (i - 1) - x + 1, lb + 1, i - 1, l, r);
        if(i - lb - 1 <= x) {
            add(lb + 1, 1);
            add(i, -1);
            S[i] = i - lb - 1;
        } else {
            int res = x - ((i - 1) - r);
            S[i] = x;
            add(r + 1, 1);
            add(i, -1);
            add(l, 1);
            add(l + res, -1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += getv(A, i) - S[i];
    n--;
    return ans;
}

signed main() {
    scanf("%d", &n);
    mn = n + 1, mx = -1;
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for(int i = 1; i <= n; i++) o ^= A[i] & 1;
    int L = 0, R = (o == 0 ? n / 2 : (n - 1) / 2);
    int a = Do(L * 2 + o), b = Do(R * 2 + o);
    for(int i = L * 2 + a + o; i <= R * 2 - b + o; i += 2) printf("%d ", i);
    if(L * 2 + a + o > R * 2 - b + o) puts("-1");
    return 0;
}