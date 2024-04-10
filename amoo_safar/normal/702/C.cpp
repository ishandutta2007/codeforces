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

ll a[MAXN];
ll b[MAXN];
ll an[MAXN];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m;
    cin >> n >> m;
    fill(an, an + n, INF);
    for(int i = 0;i<n;i++) cin >> a[i];
    for(int i = 0;i<m;i++) cin >> b[i + 1];
    b[m + 1] = INF;
    b[0] = -INF;
    ll j = 0;
    ll ans = 0,anss;

    for(int k = 0;k < n;k++){
        while(a[k] > b[j + 1]) j++;
        anss = min(b[j+1] - a[k],a[k] - b[j]);
        ans = max(anss, ans);
    }
    cout << ans;
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