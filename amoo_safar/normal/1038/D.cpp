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
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll a[MAXN];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    scanf("%lld", &n);
    for(int i =0;i<n;i++) scanf("%lld", &a[i]);
    if(n == 1){
        printf("%lld", a[0]);
        return 0;
    }
    ll fp = 0;
    ll fn = 0;

    ll ans = 0;
    ll mi;

    for(int i =0;i<n;i++){
        if(a[i] > 0) fp = 1;
        if(a[i] < 0) fn = 1;
    }
    if(fn == 0){
        mi = a[0];
        for(int i =0;i<n;i++){
            ans += a[i];
            mi = min(mi,a[i]);
        }
        printf("%lld", ans - mi - mi);
    } else {
        if(fp == 0){
            mi = abs(a[0]);
            for(int i =0;i<n;i++){
                ans += abs(a[i]);
                mi = min(mi, abs(a[i]));
            }
            printf("%lld", ans - mi - mi);

        } else {
            for(int i =0;i<n;i++) ans += abs(a[i]);
            printf("%lld", ans);
        }
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