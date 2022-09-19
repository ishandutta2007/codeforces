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

ll a[6];
vector<ll> si;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i =0;i<6;i++)cin >> a[i];
    sort(a, a + 6);
    ll cnt = 1;
    for(int i =1;i<6;i++){
        if(a[i] == a[i - 1])cnt++;
        else{
            si.pb(cnt);
            cnt = 1;
        }
    }
    si.pb(cnt);
    sort(si.begin(), si.end());
    if(si.size() == 1)cout << "Elephant";
    else if(si.size() == 2 and (si[1] == 4))cout << "Elephant";
    else if(si.size() == 2 and (si[1] == 5))cout << "Bear";
    else if(si.size() == 3 and (si[2] == 4))cout << "Bear";
    else cout << "Alien";
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