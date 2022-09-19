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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

vector< pll > g[MAXN];

ll vis[MAXN];

ll dp[MAXN];
ll dpfi[MAXN];
ll dpfit[MAXN];

vector<ll> now;
vector<ll> fut;

map< pll, ll > edge;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    fill(dp, dp + MAXN, INF);

    ll n, m, u, v, z;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> z;
        if(u > v) swap(u, v);
        g[u].pb( mp(v, z) );
        g[v].pb( mp(u, z) );
        edge[ mp(u, v) ] = z;
    }

    dp[n] = 0;

    now.pb(n);

    vis[n] = 1;

    while(vis[1] == 0){
        for(auto par : now){
            for(auto node : g[par]){
                if(vis[node.F] == 1) continue;
                if(dp[node.F] >= dp[par] + (1 - node.S)){
                    dpfi[node.F] = par;
                    dpfit[node.F] = node.S;
                    dp[node.F] = dp[par] + (1 - node.S);
                }
                fut.pb(node.F);
            }
        }
        for(auto node : fut) vis[node] = 1;
        now.clear();
        for(auto node : fut) now.pb(node);
        fut.clear();
    }

    //debug(dp[1]);

    ll nod = 1;
    while(nod != n){

        //cout << nod << " " << dpfi[nod] << endl;

        if(dpfit[nod] == 1) edge[ mp(min(nod , dpfi[nod]), max(nod , dpfi[nod])) ] = 0;
        nod = dpfi[nod];
    }
    ll out = dp[1];
    for(map< pll, ll >::const_iterator it = edge.begin(); it != edge.end(); it ++) out += (it -> second);

    cout << out << endl;

    nod = 1;
    while(nod != n){

        //cout << nod << " " << dpfi[nod] << endl;

        if(dpfit[nod] == 0) cout << min(nod , dpfi[nod]) << " " << max(nod , dpfi[nod]) << " 1" << endl;
        nod = dpfi[nod];
    }

    for(map< pll, ll >::const_iterator it = edge.begin(); it != edge.end(); it ++) {
        if(it -> second == 1) cout << (it -> F).F << " " << (it -> F).S << " 0" << endl;
    }

    //cout << dp[1];
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