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
const ll MAXN = (ll) (1ll << 16) + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll v[MAXN];
ll s[MAXN];

vector<ll> now;
vector<ll> fut;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i] >> s[i];
    ll ds = 0;
    for(int i = 0; i < n;i++){
        if(v[i] == 1) now.pb(i);
        ds += v[i];
    }
    cout << ds / 2 << endl;
    while(now.size() != 0){
        for(auto node : now){
            if(v[node] == 0) continue;
            cout << node << " " << s[node] << endl;
            v[node] --;
            v[s[node]] --;
            s[s[node]] ^= node;
            if(v[s[node]] == 1) fut.pb(s[node]);
        }

        now.clear();
        for(auto node : fut) now.pb(node);
        fut.clear();
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