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
bool CMP(ll i, ll j){
    return a[i] < a[j];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, k, s = 0,t = 0;;
    cin >> n >> k;
    for(int i = 0;i< n;i++)cin >> a[i];
    for(int i = 0;i< n;i++)b[i] = i;
    sort(b , b + n, CMP);
    for(int i =0;i < n; i++){
        s += a[b[i]];
        if(s <= k) t++;
    }
    cout << t << endl;
    s = 0;
    for(int i =0;i < n; i++){
        s += a[b[i]];
        if(s <= k) cout << b[i] + 1 << " ";
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