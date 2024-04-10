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
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp[MAXN];
ll dpx[MAXN];

ll a[MAXN];

deque<ll> de;
stack<ll> s;

ll mk[MAXN];
ll lb[MAXN];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);

    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

    for(int i = 0; i < k - 1; i++){
        while(de.size() != 0){
            if(a[de.back()] <= a[i]) de.pop_back();
            else break;
        }
        de.pb(i);
    }
    for(int i = k - 1;i < n;i++){
        while(de.size() != 0){
            if(a[de.back()] <= a[i]) de.pop_back();
            else break;
        }
        de.pb(i);
        if(i - de.front() >= k ) de.pop_front();
        mk[i] = de.front();
    }

    /*for(int i = 0; i < n; i++) printf("%lld ", mk[i]);
    printf("\n");*/

    de.clear();

    for(int i = 0; i < n; i++){

        while(de.size() != 0){
            if(a[de.back()] <= a[i]) de.pop_back();
            else break;
        }

        if(de.size() == 0) lb[i] = -1;
        else lb[i] = de.back();

        de.pb(i);
    }

    /*for(int i = 0; i < n; i++) printf("%lld ", lb[i]);
    printf("\n");*/

    ll nex, cnt, pa;

    for(int i = k - 1; i < n; i++){
        //dpx[i] = a[mk[i]];
        nex = lb[mk[i]];
        if(nex == -1){
            dpx[i] = ( (a[mk[i]]) * (i / (k - 1)) ) % MOD;
        } else {
            cnt = i - nex - 1;
            pa = cnt / (k - 1);
            dpx[i] = ( dpx[i - (pa * (k - 1))] + ( (a[mk[i]]) * pa ) ) % MOD;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + dpx[i]) % MOD;
    printf("%lld", ans);

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