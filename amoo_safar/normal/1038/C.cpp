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
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll b[MAXN];

bool CMP(ll a,ll b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i =0;i<n;i++)  cin >> a[i];
    for(int i =0;i<n;i++)  cin >> b[i];
    sort(a,a+n,CMP);
    sort(b,b+n,CMP);
    ll p1 = 0,p2 = 0;
    ll i = 0,j = 0;
    for(int k = 0; k < 2*n;k++){
        //debug(i);
        //debug(j);
        if(k%2 == 0){
            if(i == n) j++;
            else{
                if(j == n){
                    p1 += a[i];
                    i++;
                } else {
                    if(a[i] > b[j]){
                        p1+=a[i];
                        i++;
                    }else j++;
                }
            }
        } else {
            if(j == n) i++;
            else{
                if(i == n){
                    p2 += b[j];
                    j++;
                } else {
                    if(b[j] > a[i]){
                        p2 += b[j];
                        j++;
                    } else i++;
                }
            }
        }
    }
    //debug(p1);
    //debug(p2);
    cout << p1 - p2;
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