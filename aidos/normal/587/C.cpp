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


struct node{
    node * left, * right;
    int cnt;
    node(){
        left = NULL;
        right = NULL;
        cnt = 0;
    }
    node (node * l, node * r){
        left = l;
        right = r;
        cnt = 0;
    }
    node (node * l, node * r, int val){
        left = l;
        right = r;
        cnt = val;
    }
};

node * t[100400];
int n, m, q;
node * build(int l, int r){
    if( l == r){
        return new node();
    }
    else {
        int mid = ( l + r) >> 1;
        return new node(build(l, mid), build(mid + 1, r));
    }
}

vector < int > g[100100],d[100100];
int pa[100100][25];
int lev[100100];
int cnt[100100];

int get_lca(int x, int y){
    if(lev[x] < lev[y]){
        swap(x, y);
    }
    for(int i = 18; i >= 0; i--){
        if( lev[pa[x][i]] >= lev[y]){
            x = pa[x][i];
        }
    }

    if( x == y) return x;
    for(int i = 18; i >= 0; i--){
        if( pa[x][i] != pa[y][i]){
            x = pa[x][i];
            y = pa[y][i];
        }
    }
    return pa[x][0];
}

node * upd(node * x, int l, int r, int pos, int val){
    if( l==r){
        node * cur = new node();
        cur->cnt = x->cnt + val;
        return cur;
    }
    else {
        int mid = ( l + r) >> 1;
        if( pos <= mid){
            return new node(upd(x->left, l, mid, pos, val), x->right, x->cnt + val);
        }
        else {
            return new node( x->left, upd(x->right, mid+1, r, pos, val),x->cnt + val);
        }
    }
}
void go(int v, int p){
    pa[v][0] = p;
    for(int j = 1; j < 20; j++){
        if( pa[v][j-1] > 0){
            pa[v][j] = pa[pa[v][j-1]][j - 1];
        }
    }
    lev[v] = lev[p] + 1;
    t[v] = upd(t[p], 0, m, 0, 0);
    cnt[v] = cnt[p] + d[v].size();
    for(int i = 0; i < d[v].size(); i++){
        int cur = 0;
        t[v] = upd(t[v], 0, m, d[v][i], 1);
    }
    for(int i = 0; i < g[v].size(); i++){
        int c = g[v][i];
        if(c == p) continue;
        go( c, v );
    }
}
int get(node * &a, node * &b, node * &c, node * &d, int l, int r, int cnt){
    if(l == r){
        return l;
    }
    else {
        int mid = ( l + r) >> 1;
        int sum = a->left->cnt + b->left->cnt - c->left->cnt - d->left->cnt;
        if(sum >= cnt) return get(a->left, b->left, c->left, d->left, l, mid, cnt);
        else return get(a->right, b->right, c->right, d->right, mid + 1, r, cnt - sum);
    }
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1, x, y; i < n; i++){
        scanf("%d %d", &x, &y);
        g[x].pb( y );
        g[y].pb( x );
    }
    t[0] = build(0, m);
    for(int i = 1, x; i <= m; i++){
        scanf("%d", &x);
        d[x].pb( i );
    }
    go(1, 0);
    for(int i = 0, v, u,a; i < q; i++){
        scanf("%d %d %d", &v, &u, &a);
        int g = get_lca( v, u);
        a = min(a, cnt[v] + cnt[u] - cnt[g] - cnt[pa[g][0]]);
//          continue;
        printf("%d", a);
        for(int j = 0; j < a; j++){
            printf(" %d", get(t[v], t[u], t[g], t[pa[g][0]], 0, m, j + 1));
        }
        printf("\n");
    }
    



    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}