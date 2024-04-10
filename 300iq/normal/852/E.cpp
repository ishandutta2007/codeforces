#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define size(n) ( int( n.size() ) )
#define sqr(n) ( (n) * (n) )
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5, mod = 1e9 + 7;
vector < int > g[N];
int parent[N], f[N][2][2][2], posInV[N];
vector < int > pr[N][2], sf[N][2];

void dfs1( int v ){
    f[v][0][0][0] = 1;
    f[v][1][1][0] = 1;
    f[v][0][1][0] = 1;
    f[v][1][0][0] = 1;
    if ( ( ( size(g[v]) == 1 ) && ( v != 1 ) ) || ( ( v == 1 ) && ( size(g[v]) == 0 ) ) ){
        f[v][0][1][0] = 0;
        f[v][1][0][0] = 0;
        return;
    }
    pr[v][0].pb(1);
    pr[v][1].pb(1);
    sf[v][0].pb(1);
    sf[v][1].pb(1);
    int cntEdges = 0;
    for ( int j = 0; j < size(g[v]); j++ ){
        int u = g[v][j];
        if ( u != parent[v] ){
            cntEdges++;
            parent[u] = v;
            dfs1(u);
            posInV[u] = size( pr[v][0] );

            pr[v][0].pb( ( pr[v][0].back() * 1ll * ( f[u][0][1][0] + f[u][0][0][0] ) ) % mod );
            pr[v][1].pb( ( pr[v][1].back() * 1ll * ( f[u][1][0][0] + f[u][1][1][0] ) ) % mod );

            f[v][0][1][0] = ( f[v][0][1][0] * 1ll * ( f[u][1][0][0] + f[u][1][1][0] ) ) % mod;
            f[v][0][0][0] = ( f[v][0][0][0] * 1ll * ( f[u][0][0][0] + f[u][0][1][0] ) ) % mod;

            f[v][1][1][0] = ( f[v][1][1][0] * 1ll * ( f[u][0][0][0] + f[u][0][1][0] ) ) % mod;
            f[v][1][0][0] = ( f[v][1][0][0] * 1ll * ( f[u][1][0][0] + f[u][1][1][0] ) ) % mod;
        }
    }
    for ( int j = size(g[v]) - 1; j >= 0; j-- ){
        int u = g[v][j];
        if ( u != parent[v] ){
            sf[v][0].pb( ( sf[v][0].back() * 1ll * ( f[u][0][0][0] + f[u][0][1][0] ) ) % mod );
            sf[v][1].pb( ( sf[v][1].back() * 1ll * ( f[u][1][0][0] + f[u][1][1][0] ) ) % mod );
        }
    }
}

void dfs2( int v ){
    int u = parent[v];
    if ( u != 0 ){
        if ( ( u == 1 ) && ( size(g[u]) != 1 ) ){
            f[v][0][0][1] = ( pr[u][0][ posInV[v] - 1 ] * 1ll * sf[u][0][ size(pr[u][0]) - posInV[v] - 1 ] ) % mod;
            f[v][0][0][1] = ( f[v][0][0][1] + pr[u][1][ posInV[v] - 1 ] * 1ll * sf[u][1][ size(pr[u][1]) - posInV[v] - 1 ] ) % mod;
            f[v][0][1][1] = ( pr[u][1][ posInV[v] - 1 ] * 1ll * sf[u][1][ size(pr[u][1]) - posInV[v] - 1 ] ) % mod;
            f[v][0][1][1] = ( f[v][0][1][1] + pr[u][0][ posInV[v] - 1 ] * 1ll * sf[u][0][ size(pr[u][0]) - posInV[v] - 1 ] ) % mod;
            //1
            f[v][1][0][1] = ( pr[u][1][ posInV[v] - 1 ] * 1ll * sf[u][1][ size(pr[u][1]) - posInV[v] - 1 ] ) % mod;
            f[v][1][0][1] = ( f[v][1][0][1] + pr[u][0][ posInV[v] - 1 ] * 1ll * sf[u][0][ size(pr[u][0]) - posInV[v] - 1 ] ) % mod;
            f[v][1][1][1]  = ( pr[u][0][ posInV[v] - 1 ] * 1ll * sf[u][0][ size(pr[u][0]) - posInV[v] - 1 ] ) % mod;
            f[v][1][1][1]  = ( f[v][1][1][1] + pr[u][1][ posInV[v] - 1 ] * 1ll * sf[u][1][ size(pr[u][1]) - posInV[v] - 1 ] ) % mod;

        }
        else{
            f[v][0][0][1] = ( pr[u][0][ posInV[v] - 1 ] * 1ll * sf[u][0][ size(pr[u][0]) - posInV[v] - 1 ] ) % mod;
            f[v][0][0][1] = ( f[v][0][0][1] * 1ll * ( f[u][0][0][1] + f[u][0][1][1] ) ) % mod;
            f[v][0][1][1] = ( pr[u][1][ posInV[v] - 1 ] * 1ll * sf[u][1][ size(pr[u][1]) - posInV[v] - 1 ] ) % mod;
            f[v][0][1][1] = ( f[v][0][1][1] * 1ll * ( f[u][1][0][1] + f[u][1][1][1] ) ) % mod;
            //1
            f[v][1][0][1] = ( pr[u][1][ posInV[v] - 1 ] * 1ll * sf[u][1][ size(pr[u][1]) - posInV[v] - 1 ] ) % mod;
            f[v][1][0][1] = ( f[v][1][0][1] * 1ll * ( f[u][1][0][1] + f[u][1][1][1] ) ) % mod;
            f[v][1][1][1]  = ( pr[u][0][ posInV[v] - 1 ] * 1ll * sf[u][0][ size(pr[u][0]) - posInV[v] - 1 ] ) % mod;
            f[v][1][1][1]  = ( f[v][1][1][1]  * 1ll * ( f[u][0][1][1] + f[u][0][0][1] ) ) % mod;
        }

    }
    else{
        f[v][0][0][1] = 1;
        f[v][1][1][1] = 1;
        f[v][0][1][1] = 0;
        f[v][1][0][1] = 0;
    }
    for ( int j = 0; j < size(g[v]); j++ ){
        int u = g[v][j];
        if ( u != parent[v] ){
            parent[u] = v;
            dfs2(u);
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n - 1; i++ ){
        int v, u;
        scanf("%d %d",&v,&u);
        g[v].pb(u);
        g[u].pb(v);
    }
    dfs1(1);
    dfs2(1);
    int ans = 0;
    for ( int i = 1; i <= n; i++ ){
        for ( int j = 0; j <= 1; j++ ){
            if ( i == 1 ){
                ans = ( ans + f[i][0][j][0] ) % mod;
            }
            else
            if ( size(g[i]) == 1 ){
                ans = ( ans + f[i][0][j][1] ) % mod;
            }
            else{
                ans = ( ans + f[i][0][j][1] * 1ll * f[i][0][j][0] ) % mod;
            }
        }
    }
    printf("%d",ans);
    return 0;
}