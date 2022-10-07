#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1e5;
struct node{
    long double upd;
};
struct tree{
    int a, h, l, r;
};
struct mushroom{
    int a, p;
};

node a[maxn * 4];
tree b[maxn];
mushroom c[maxn];
int n, m;

void push(int i){
    a[i * 2].upd *= a[i].upd;
    a[i * 2 + 1].upd *= a[i].upd;
    a[i].upd = 1;
}
/*
long long getsum(int v, int l, int r, int ll, int rr){
    if (l > rr || ll > r)
        return 0;
    if (ll <= l && r <= rr)
        return a[v].sum;
    push(v);
    return getsum(v * 2, l, (l + r) / 2, ll, rr) +
           getsum(v * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
}
*/
void modify(int v, int l, int r, int ll, int rr, long double delta){
    if (l > rr || ll > r)
        return;
    if (ll <= l && r <= rr){
        a[v].upd *= delta;
        return;
    }
    push(v);
    modify(v * 2, l, (l + r) / 2, ll, rr, delta);
    modify(v * 2 + 1, (l + r) / 2 + 1, r, ll, rr, delta);
}

bool f (mushroom a, mushroom b){
    if (a.a < b.a || (a.a == b.a && a.p > b.p))
        return 1;
    return 0;
}

int binl (int k){
    int l = -1;
    int r = m - 1;
    while (r - l > 1)
        if (c[(l + r) / 2].a >= k)
            r = (l + r) / 2;
        else
            l = (l + r)  / 2;
    return r;
}
int binr (int k){
    int l = 0;
    int r = m;
    while (r - l > 1)
        if (c[(l + r) / 2].a > k)
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    return l;
}


int main()
{
   int step, i, l, r;
    long double res = 0;
    scanf("%d%d\n", &n, &m);
    step = 1;
    while (step < m)
        step *= 2;
    for (i = 0; i < n; i++)
        cin >> b[i].a >> b[i].h >> b[i].l >> b[i].r;
    for (i = 0; i < m; i++)
        cin >> c[i].a >> c[i].p;

    for (i = 1; i < step * 2; i++)
        a[i].upd = 1;
    sort(c, c + m, f);

    for (i = 0; i < n; i++){
        l = binl(b[i].a - b[i].h);
        r = binr(b[i].a - 1);
        if ( !(b[i].a - b[i].h > c[m - 1].a || b[i].a - 1 < c[0].a))
            modify(1, 1, step, l + 1, r + 1, (100 - b[i].l) / 100.0);
        l = binl(b[i].a + 1);
        r = binr(b[i].a + b[i].h);
        if ( !(b[i].a + 1 > c[m - 1].a || b[i].a + b[i].h < c[0].a))
            modify(1, 1, step, l + 1, r + 1, (100 - b[i].r) / 100.0);
    }
    for (i = 1; i < step; i++)
        push(i);
    for (i = 0; i < m; i++)
        res += a[i + step].upd * c[i].p;
    cout.precision(15);
    cout << fixed << res;
    return 0;
}