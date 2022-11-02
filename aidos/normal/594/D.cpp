#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

int a[1000100];
vector < int > g[1000100];
int binpow(int n, int m){
    if( m == 0) return 1;
    if( m & 1) return binpow(n, m - 1) * 1ll * n % mod;
    return binpow( n *1ll * n % mod, m / 2);
}

int get(int v, int l, int r, int p){
//  push(v, l, r);
    if( l == r) return a[v];
    int mid = ( l + r) >> 1;
    if( p <= mid) return get(v * 2, l, mid, p) * 1ll * a[v] % mod;
    return get(v * 2 + 1, mid + 1, r, p) * 1ll * a[v] % mod;
}

void upd(int v, int l, int r, int tl, int tr, int val){
    //push(v, l, r);
    if( tl > tr) return;
    if( l == tl && tr == r) {
        a[v] = a[v] * 1ll * val % mod;
        return;
    }
    int mid = (l+ r) >> 1;
    upd(v * 2, l, mid, tl, min(tr, mid), val);
    upd(v * 2+1, mid+1, r, max(tl, mid+1), tr, val);
}

int x[200200];
vector < pii > t[200200];

int ans[200200];
int fi[1000200];
int n;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 2; i < 1000100; i++){
        if(g[i].size() == 0){
            for(int j = i; j < 1000100; j += i)
                g[j].pb( i );
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }

    for(int i = 0; i < 1000100; i++)
        a[i] = 1;
    int q;
    scanf("%d", &q);
    for(int i = 0, l, r;  i < q; i++){
        scanf("%d %d", &l, &r);
        t[r - 1].pb(mp(l - 1, i ));
    }
    memset(fi, -1, sizeof fi);
    for(int i = 0; i < n; i++){
        upd( 1, 0, n - 1, 0, i, x[i]);
        for(int tt : g[x[i]]){
            upd(1, 0, n - 1, fi[tt] + 1, i, binpow(tt, mod - 2));
            upd(1, 0, n - 1, fi[tt] + 1, i, tt - 1);
            fi[tt] = i;
        }
        for(pii tt : t[i]){
            ans[tt.s] = get(1, 0, n - 1, tt.f);
        }
    }
    for(int i = 0; i < q; i++){
        printf("%d\n", ans[i]);
    }
    

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}