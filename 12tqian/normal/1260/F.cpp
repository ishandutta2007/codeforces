#include<bits/stdc++.h>
using namespace std;
int n ;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7 ;
vector<int> E[maxn];
vector<int> in[maxn] , out[maxn];
int cm = 0;
int l[maxn] , dfn = 0 , dep[maxn];
int g[maxn];
int siz[maxn] , top[maxn] , h[maxn] , f[maxn];
///-----segment tree
struct seg
{
    int l , r;
    int sum , add ;
}Node[maxn * 4];

void build(int u,int l,int r)
{
    Node[u].l = l , Node[u].r = r;
    Node[u].sum = Node[u].add = 0;
    if(l == r) return ;
    build(u<<1 , l , (l + r >> 1));
    build(u<<1|1 , (l + r >>1) + 1 , r);
    return ;
}
void pd(int u)
{
    Node[u].sum = (1LL*Node[u].add*(Node[u].r - Node[u].l + 1) + Node[u].sum) % mod ;
    if(Node[u].l == Node[u].r) {
        Node[u].add = 0 ;return ;
    }
    (Node[u<<1].add += Node[u].add ) %= mod;
    (Node[u<<1|1].add += Node[u].add ) %= mod;
    Node[u].add = 0 ; return ;
}
void modify(int u,int l,int r,int v)
{
    if(Node[u].l == l && Node[u].r == r) {
        (Node[u].add += v ) %= mod;
        pd(u) ; return ;
        return ;
    }
    pd(u) ;
    if(Node[u<<1].r >= r) {modify(u<<1 , l , r , v) ; pd(u<<1|1);}
    else if(Node[u<<1|1].l <= l) {modify(u<<1|1 , l , r , v) ; pd(u<<1) ;}
    else {
        modify(u<<1 , l , Node[u<<1].r , v) ;
        modify(u<<1|1 , Node[u<<1|1].l , r , v);
    }
    Node[u].sum = (Node[u<<1].sum + Node[u<<1|1].sum) % mod;
    return ;
}
int query(int u,int l,int r)
{
    pd(u) ;
    if(Node[u].l == l && Node[u].r == r) return Node[u].sum ;
    if(Node[u<<1].r >= r) return query(u<<1 , l , r) ;
    else if(Node[u<<1|1].l <= l) return query(u<<1|1 , l , r);
    else return (query(u<<1 , l , Node[u<<1].r) + query(u<<1|1 , Node[u<<1|1].l , r)) % mod;
}
///---segment tree end
void dfs(int fa,int u,int d)
{
    f[u] = fa;
    dep[u] = d;siz[u] = 1;h[u] = -1;
    for(int i = 0;i < E[u].size();i++) {
        if(E[u][i] != fa) {
            dfs(u , E[u][i] , d + 1) ;siz[u] += siz[E[u][i]];
            if(h[u] == -1 || siz[E[u][i]] > siz[E[u][h[u]]]) h[u] = i;
        }
    }
    return ;
}
void dfs2(int fa,int u)
{
    l[u] = ++dfn;
    if(h[u] != -1) {
        top[E[u][h[u]]] = top[u] ;
        dfs2(u , E[u][h[u]]);
    }
    for(int i = 0;i < E[u].size();i++) {
        if(E[u][i] != fa && i != h[u]) {
            top[E[u][i]] = E[u][i] ;
            dfs2(u , E[u][i]) ;
        }
    }
    return ;
}
int fpow(int a,int b)
{
    int ans = 1;
    while(b) {
        if(b & 1) ans = (1LL * ans * a) % mod;
        a = (1LL * a * a) % mod ;b >>= 1;
    }
    return ans;
}
void add(int u,int v)
{
    while(u) {
        modify(1 , l[top[u]] , l[u] , v) ;
        u = f[top[u]] ;
    }
    return ;
}
int cal(int u)
{
    int ans = mod - query(1 , 1 , 1);
    while(u) {
        ans = (ans + query(1 , l[top[u]] , l[u])) % mod;
        u = f[top[u]] ;
    }
    return ans;
}
int main()
{
    scanf("%d",&n) ;
    int P = 1;
    for(int i = 1;i <= n;i++) {
        int l , r;scanf("%d%d",&l,&r) ;
        in[l].push_back(i) ;
        out[r + 1].push_back(i) ; cm = max(cm , r);
        g[i] = fpow(r - l + 1 , mod - 2) ;
        P = 1LL * P * (r - l + 1) % mod;
    }
    for(int i = 1;i < n;i++) {
        int u , v;scanf("%d%d",&u,&v) ;
        E[u].push_back(v) ; E[v].push_back(u) ;
    }
    dfs(0 , 1 , 0) ; top[1] = 1;
    dfs2(0 , 1) ;
    build(1 , 1 , n) ;
    int ans = 0 , cur = 0;
    int d1 = 0 , d2 = 0 , u , d3 = 0;
    for(int i = 1;i <= cm;i++) {
        for(int j = 0;j < out[i].size();j++) {
            u = out[i][j] ;
            d1 = (d1 - 1LL * dep[u] * g[u] % mod + mod) % mod;
            d2 = (d2 - g[u] + mod) % mod ;
            d3 = (d3 - 1LL*dep[u]*g[u] % mod * g[u] % mod + mod) % mod;
            add(u , mod - g[u]) ;
            cur = (cur - 1LL * g[u] * cal(u) % mod + mod) % mod;
        }
        for(int j = 0;j < in[i].size();j++) {
            u = in[i][j] ;
            d1 = (d1 + 1LL * dep[u] * g[u]) % mod;
            d2 = (d2 + g[u]) % mod;
            d3 = (d3 + 1LL*dep[u]*g[u]%mod*g[u]) % mod;
            cur = (cur + 1LL * g[u] * cal(u)) % mod;
            add(u , g[u]) ;
        }
        ans = (ans + 1LL * d1 * d2%mod - 2LL*cur - d3) % mod;
        ans = (ans + mod) % mod;
    }
    ans = 1LL * ans * P % mod;
    printf("%d\n",ans);
    return 0;
}