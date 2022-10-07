#include <iostream>
#include <cstdio>


using namespace std;
struct node {
    long double l, r, m, sum;
};

const int maxn = 3e5;
int a[maxn];
int p[maxn];
long double mo[maxn];
node b[maxn * 2];
node q; 

node sum(node a, node b){
    node c; 
    c.sum = a.sum + b.sum;
    c.l = max(a.l, a.sum + b.l);
    c.r = max(b.r, b.sum + a.r);
    c.m = max(max(a.m, b.m), a.r + b.l);
    return c;
}

node getsum(int v, int ll, int rr, int l, int r){
    if (ll > r || l > rr)
        return q;
    if (l <= ll && rr <= r)
        return b[v];
    return sum(getsum(v * 2, ll, (ll + rr) / 2, l, r), getsum(v * 2 + 1, (ll + rr) / 2 + 1, rr, l, r));
}


int main(){
   int n, m, c, i, l, r, step;
    long double ans = 0, k;
    q.m = q.l = q.r = q.sum = 0;
    cin >> n >> m >> c;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n - 1; i++)
        cin >> p[i];
    for (i = 0; i < n - 1; i++)
        mo[i] = (a[i + 1] - a[i]) / 2.0 - c * p[i] / 100.0;
    
    step = 1;
    while (step < n - 1)
        step *= 2;
    for (i = step; i < step + n - 1; i++){
        b[i].sum = mo[i - step];
        if (mo[i - step] > 0)
            b[i].l = b[i].r = b[i].m = mo[i - step];
    }

    for (i = step - 1; i > 0; i--){
        b[i] = sum(b[i * 2], b[i * 2 + 1]);
    }

    cout.precision(15);

    for (i = 0; i < m; i++){
        cin >> l >> r;
        k = getsum(1, 1, step, l, r - 1).m;
        ans += k;
    //  cout << k << endl;
    }
    cout << endl << fixed << ans; 

}