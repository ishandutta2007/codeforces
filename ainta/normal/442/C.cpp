#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 524288
int n, w[500010], q[2000010], h, t, a, b, o[500010];
long long Res;
struct IndexTree{
    int l, r;
}IT[SZ * 2 + 1];
void UDT(int x)
{
    IT[x].l = IT[x * 2].l;
    IT[x].r = IT[x * 2 + 1].r;
    if (!IT[x].l)IT[x].l = IT[x * 2 + 1].l;
    if (!IT[x].r)IT[x].r = IT[x * 2].r;
}
int Left(int a, int b){
    a += SZ, b += SZ;
    int r = n + 1;
    while (a <= b){
        if (IT[a].l && r > IT[a].l)r = IT[a].l;
        if (IT[b].l && r > IT[b].l)r = IT[b].l;
        a = (a + 1) >> 1, b = (b - 1) >> 1;
    }
    return r;
}
int Right(int a, int b){
    a += SZ, b += SZ;
    int r = 0;
    while (a <= b){
        if (IT[a].r && r < IT[a].r)r = IT[a].r;
        if (IT[b].r && r < IT[b].r)r = IT[b].r;
        a = (a + 1) >> 1, b = (b - 1) >> 1;
    }
    return r;
}
void Do(int x){
    int a = Right(1, x - 1);
    int b = Left(x + 1, n);
    if (w[a] >= w[x] && w[b] >= w[x]){
        q[++t] = x;
        o[x] = t;
    }
}
int main()
{
    int i, x, tp, aa, bb;
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        IT[SZ + i].l = IT[SZ + i].r = i;
    }
    for (i = 1; i <= n; i++){
        if (i > 1 && i < n && w[i - 1] >= w[i] && w[i + 1] >= w[i]){
            q[++t] = i;
            o[i] = t;
        }
    }
    for (i = SZ - 1; i >= 1; i--)UDT(i);
    while (h < t){
        x = q[++h];
        if (o[x] != h)continue;
        a = Right(1, x - 1);
        b = Left(x + 1, n);
        Res += min(w[a], w[b]);
        w[x] = 0;
        IT[SZ + x].l = IT[SZ + x].r = 0;
        tp = SZ + x;
        while (tp != 1){
            tp /= 2;
            UDT(tp);
        }
        if (a != 1 && a != n){
            Do(a);
        }
        if (b != 1 && b != n){
            Do(b);
        }
    }
    int m1 = 0, m2 = 0;
    for (i = 1; i <= n; i++){
        if (w[i])Res += w[i];
        if (m1 < w[i])m2 = m1, m1 = w[i];
        else if (m2 < w[i])m2 = w[i];
    }
    Res -= m1 + m2;
    printf("%lld\n", Res);
}