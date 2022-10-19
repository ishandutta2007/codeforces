#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 200005;
const ll INF = 2e9 + 2;

struct node {
    node *l, *r;
    ll x;
    ll sum;
    node() {
        l = r = NULL;
        x = INF;
        sum = INF;
    }
};

int L, R;
ll X;
ll SUM;

void update (node *&t, int l, int r){
    if (t == NULL)
        t = new node();
    if (max (l, L) >= min (r, R))
        return;
    if (l + 1 == r){
        t->x = X;
        return;
    }
    int mid = l + r >> 1;
    update (t->l, l, mid);
    update (t->r, mid, r);
    t->x = min (t->l->x, t->r->x);
    t->sum = min (min (t->l->sum, t->r->sum), t->l->x + t->r->x);
}


void query (node *t, int l, int r){
    if (t == NULL)
        return;
    if (max (l, L) >= min (r, R))
        return;
    if (L <= l && r <= R){
        SUM = min (SUM, t->sum);
        SUM = min (SUM, t->x + X);
        X = min (X, t->x);
        return;
    }
    int mid = l + r >> 1;
    query (t->l, l, mid);
    query (t->r, mid, r);
}

node *root[10];

int n, m;
int a[N];
int x, i, j, t, ind, val, l, r, ans;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    scanf ("%d %d", &n, &m);
    for (i = 1; i <= n; i++){
        scanf ("%lld", &x);
        a[i] = x;
        L = i;
        R = i + 1;
        for (j = 0; j < 9; j++){
            if (x % 10 != 0){
                X = a[i];
                update (root[j], 1, n + 1);
            }
            x /= 10;
        }
    }
    while (m--){
        scanf ("%d", &t);
        if (t == 1){
            scanf ("%d %d", &ind, &val);
            a[ind] = val;
            x = a[ind];
            for (j = 0; j < 9; j++){
                L = ind;
                R = ind + 1;
                if (x % 10 != 0)
                    X = a[ind];
                else
                    X = INF;
                update (root[j], 1, n + 1);
                x /= 10;
            }
            continue;
        }
        scanf ("%d %d", &l, &r);
        L = l;
        R = r + 1;
        ans = INF;
        for (i = 0; i < 9; i++){
            X = INF;
            SUM = INF;
            query (root[i], 1, n + 1);
            if (SUM < ans)
                ans = SUM;
        }
        if (ans >= INF)
            ans = -1;
        printf ("%d\n", ans);
    }
    return 0;
}