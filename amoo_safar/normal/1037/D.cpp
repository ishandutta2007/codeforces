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

vector<ll> g[MAXN];

vector<ll> now;
vector<ll> fut;

ll vis[MAXN];
ll vi[MAXN];

bool CMP(ll i, ll j){
    return vis[i] < vis[j];
}

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
    for(int i =0;i<n;i++){
        cin >> a[i];
        a[i] --;
        vis[a[i]] = i;
    }
    for(int i =0;i < n; i++){
        sort(g[i].begin(), g[i].end(), CMP);
    }

    if(a[0]!=0){
        cout << "No";
        return 0;
    }

    ll j = 1;
    ll f = 1;

    now.pb(0);
    vi[0] = 1;
    while(now.size() != 0){
        for(auto par : now){
            for(auto node : g[par]){

                if(vi[node] == 1) continue;
                if(a[j] != node) {
                    f = 0;
                    //cout << j;
                }
                fut.pb(node);
                vi[node] = 1;
                j ++;
            }
        }

        now.clear();
        for(auto node : fut) now.pb(node);
        fut.clear();
    }
    if(f == 0)cout << "No";
    else cout << "Yes";
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