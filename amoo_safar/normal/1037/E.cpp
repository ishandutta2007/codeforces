#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

set< ll > ans;
set< ll > g[MAXN];
vector< pll > q;

vector< ll > anss;

queue< ll > bfsq;
ll vis[MAXN];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m, k, u, v;
    scanf("%lld", &n);
    scanf("%lld", &m);
    scanf("%lld", &k);

    ll an = n;
    //debug(n);
    //printf("%lld\n", n);
    for(int i = 0; i < m; i++){
        scanf("%lld", &u);
        scanf("%lld", &v);
        u --;
        v --;
        g[u].insert(v);
        g[v].insert(u);
        q.pb( mp( u, v ) );
    }

    for(int i = 0; i < n; i++) ans.insert(i);

    for(int i = 0; i < n; i++){
        if(g[i].size() < k){
            bfsq.push(i);
            vis[i] = 1;
        }
    }

    //debug(n);

    while(bfsq.size() != 0){
        for(auto adj : g[bfsq.front()]){
            g[adj].erase(bfsq.front());
            if(g[adj].size() < k){
                if(vis[adj] == 0) bfsq.push(adj);
                vis[adj] = 1;
            }
        }
        ans.erase(bfsq.front());
        //debug(bfsq.front());
        bfsq.pop();
        an --;
    }
    anss.pb(an);
    //printf("%lld\n", an);

    for(int i = 0; i < m; i++){
        u = q.back().F;
        v = q.back().S;
        //debug(u);
        //debug(v);
        if( (vis[u] == 1) or (vis[v] == 1) ){
            //printf("%lld\n", an);
            anss.pb(an);
            q.pop_back();
            continue;
        }
        g[u].erase(v);
        g[v].erase(u);

        //debug(g[u].size());
        //debug(g[v].size());

        if(g[u].size() < k){
            bfsq.push(u);
            vis[u] = 1;
        }
        if(g[v].size() < k){
            bfsq.push(v);
            vis[v] = 1;
        }


        while(bfsq.size() != 0){
            for(auto adj : g[bfsq.front()]){
                g[adj].erase(bfsq.front());
                if(g[adj].size() < k){
                    if(vis[adj] == 0) bfsq.push(adj);
                    vis[adj] = 1;
                }
            }
            ans.erase(bfsq.front());
            //debug(bfsq.front());
            bfsq.pop();
            an --;
        }

        //printf("%lld\n", an);
        anss.pb(an);
        q.pop_back();
    }

    anss.pop_back();

    for(int i = 0; i < m; i++){
        printf("%lld\n", anss.back());
        anss.pop_back();
    }

    return 0;
}



/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/