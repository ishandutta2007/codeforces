#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e5) + 10
using namespace std;

int n, x, y;
vector < int > g[MAXN];
vector < pii > gr[MAXN];

int p[MAXN];
int d[MAXN];
int pp[MAXN][20];
int tin[MAXN];
int tout[MAXN];
int lev[MAXN];
int used[MAXN];
int tt[8*MAXN];
int answer[MAXN];

void upd(int k, int val, int v=1, int l = 0, int r = 2 * MAXN){
    if(l == r){
        tt[v] = val;
    }
    else {
        int mid = ( l + r) >> 1;
        if( mid >= k) upd(k, val, v*2, l, mid);
        else upd(k, val, v*2 + 1, mid+1, r);
        tt[v] = tt[v*2] + tt[v*2+1];
    }
}
int query(int l, int r, int v = 1, int tl = 0, int tr=  2 *MAXN){
    if( l >  r) return 0;
    if( tl == l && tr == r) return tt[v];
    int mid = (tl+tr) >> 1;
    return query(l, min(mid, r), v*2, tl, mid) + query(max(l, mid+1), r, v*2 + 1, mid+1, tr);
}


int dfs(int t){
    if( d[t] == -1) return t;
    return dfs(d[t]);
}

int get(int v){
    if( v == p[v] ) return v;
    return p[v] = get(p[v]);
}

vector < int > qu;

bool is_p(int x, int y){
      if (lev[x] < lev[y])
           return 0;
      if( lev[x] == lev[y]) return x == y;
      //cout << x << " " << y << endl;
   
      for (int i = 17; i >= 0; i--)
          if (lev[x] - (1 << i) >= lev[y] && pp[x][i]!=-1)
              x = pp[x][i];
      //cout << x << " " << y << endl;
      if (y == x)
          return 1;
      return 0;
}


int timer = 0;
void dfs2(int x, int deg = 0, int par = -1){
    if( par!=-1){
        pp[x][0] = par;
        for(int i = 1;i<18; i++){
            if(pp[x][i-1]!=-1)
                pp[x][i] = pp[pp[x][i-1]][i-1];
        }
    }
    used[x]  = 1;
    lev[x] = deg;
    tin[x] = timer++;

    for(int i = 0; i < g[x].size(); i++){
        dfs2(g[x][i], deg+1, x);
    }

    tout[x] = timer++;
}





vector < pair < int, pii > > ans;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    
    memset(d, -1, sizeof(d) );
    memset(pp, -1, sizeof(pp));
    memset(answer, -1, sizeof(answer));

    int m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++) p[i] = i;

    for(int i = 0; i < m; i++){
        int t, x, y = -1;
        cin >> t >> x;
        if( t != 2 ) cin >> y;
        else {
            qu.pb(i);
        }
        ans.pb( mp(t, mp(x, y) ));
        if( t == 1 ){
            d[x] = y;
            g[y].pb(x);
            x = get(x);
            y = get(y);
            if( x != y ){
                p[x] = y;
            }
        }
        else if( t == 3){
            answer[i] = 0;
            if( y <= qu.size() ) {
                gr[qu[y-1]].pb(mp( i, x));
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if( !used[i] ) {
            int x = dfs(i);
            dfs2(x, 0, -1);
        }
    }
     

    for(int j = 0; j < m; j++){
        if( ans[j].f == 1) {
            upd(tin[ans[j].s.f], 1);
            upd(tout[ans[j].s.f], -1);
        }
        else if( ans[j].f == 2){
            for(int k = 0; k < gr[j].size(); k++){
                int xx = gr[j][k].f;
                int to = gr[j][k].s;
                //cout << lev[ans[j].s.f] << " " << lev[to] << endl;
                if( is_p(ans[j].s.f, to) && query(tin[to] + 1, tin[ans[j].s.f]) == lev[ans[j].s.f] - lev[to]){
                    answer[xx] = 1;
                }
                /*
                cout  << tin[to]+1 <<  " " << tin[ans[j].s.f] << endl;
                for(int  i = tin[to] + 1; i <= tin[ans[j].s.f]; i++){
                    cout << query(i, i) << endl;
                }
                cout << query(tin[to] + 1, tin[ans[j].s.f]) << endl;
                //cout << j << " " /*<< is_p(ans[j].s.f, to) << endl;// << get(to) << " " << get(ans[j].s.f) << endl;*/
            }
        }
    }

    for(int i = 0; i < m; i++){
        if( answer[i] == -1) continue;
        if( answer[i] ) cout << "YES\n";
        else cout << "NO\n";
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}