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
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 9223372036854775807;

pll a[MAXN];
ll b[MAXN];

ll dis = 1500ll;

bool CMP(ll i, ll j){
    if(a[i].S / dis == a[j].S / dis ) {
        if(a[i].F == a[j].F) return a[i].F < a[j].F;
        return a[i].F < a[j].F;
    }
    return a[i].S / dis < a[j].S / dis;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    for(int i = 0; i < n; i++) b[i] = i;
    sort(b, b + n, CMP);
    for(int i =0;i<n;i++) cout << b[i] + 1 << " ";
    return 0;
}



/*
10
32413 2202
32432 1943
343 1332
12 9001
0 0
3215 9999
5235 11111
11111 9988
1000 9188
9999 547546

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