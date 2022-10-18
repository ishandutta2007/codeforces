#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42, logn = 20;
const int inf = 1e9;

int bpow(int x, int n, int m) {
    return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}

int par[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

bool uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a != b) {
        par[b] = a;
        return 1;
    }
    return 0;
}
#define count agkak
int count;
int a[maxn];
int l;

void upd(int p, int d) {
    count -= a[p] > l;
    a[p] += d;
    count += a[p] > l;
    if(a[p] > l) {
        if(a[p - 1] > l) count -= uni(p - 1, p);
        if(a[p + 1] > l) count -= uni(p, p + 1);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    int n, m;
    cin >> n >> m >> l;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        upd(i + 1, t);
    }
    while(m--) {
        int t;
        cin >> t;
        if(t == 0) {
            cout << count << endl;
        } else {
            int p, d;
            cin >> p >> d;
            upd(p, d);
        }
    }
    return 0;
}