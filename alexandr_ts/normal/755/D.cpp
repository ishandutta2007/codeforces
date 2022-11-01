#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;


int d[4 * N];
int a[N];

void build(int v, int tl, int tr) {
    if (tr > tl) {
        build(2 * v, tl, (tl + tr) / 2);
        build(2 * v + 1, (tl + tr) / 2 + 1, tr);
        d[v] = d[2 * v] + d[2 * v + 1];
    }
    else
        d[v] = a[tl];
}

int sum(int v, int tl, int tr, int l, int r) {
    int tm = (tl + tr) / 2;
    if (tl > r || tr < l)
        return 0;
    if (tl >= l && tr <= r)
        return d[v];
    return sum(2 * v, tl, tm, l, r) + sum(2 * v + 1, tm + 1, tr, l, r);
}

void add(int v, int tl, int tr, int pos, int x) {
    int tm = (tl + tr) / 2;
    if (tl > pos || tr < pos)
        return;
    if (tl == tr) {
        d[v] += x;
        return;
    }
    if(tm < pos)
        add(2 * v + 1, tm + 1, tr, pos, x);
    else
        add(2 * v, tl, tm, pos, x);
    d[v] = d[2 * v] + d[2 * v + 1];
    return;
}


int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k > n / 2)
        k = n - k;
    ll ans = 1;
    //a[0] = 0;
    //b[0] = 0;
    frab(i, 1, n + 1)
        a[i] = (a[i - 1] + k) % n;
    frab(i, 0, n) {
        ans++;
        int cur = a[i];
        //b[a[i]]++;
        add(1, 0, n, a[i], 1);
        int l = a[i];
        int r = a[i + 1];
        l = (l + 1) % n;
        r = (r - 1 + n) % n;
        if (l <= r)
            ans += sum(1, 0, n, l, r);
        else {
            ans += sum(1, 0, n, 0, r);
            ans += sum(1, 0, n, l, n);
        }
        add(1, 0, n, a[i + 1], 1);
        //b[a[i + 1]]++;
        //if (i % 10000 == 0)
            cout << ans << " ";
    }
    //cout << ans;


}