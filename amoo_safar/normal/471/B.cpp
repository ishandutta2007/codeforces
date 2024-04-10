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
const ll MAXN = (ll) 2000 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll a1[MAXN];
ll a2[MAXN];
ll a3[MAXN];

bool CMP(ll i, ll j){
    return a[i - 1] < a[j - 1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i =0;i<n;i++)cin >> a[i];
    for(int i =0;i<n;i++) a1[i] = i + 1;
    for(int i =0;i<n;i++) a2[i] = i + 1;
    for(int i =0;i<n;i++) a3[i] = i + 1;
    sort(a1, a1 + n,CMP);
    sort(a2, a2 + n,CMP);
    sort(a3, a3 + n,CMP);
    ll cnt = 0;
    for(int i =1;i<n;i++){
        if(a[a1[i]-1] == a[a1[i-1]-1])cnt ++;
    }
    //debug(cnt);
    if(cnt < 2){
        cout << "NO";
        return 0;
    }
    ll f1 = 0;
    for(int i =1;i<n;i++){
        if(a[a1[i]-1] == a[a1[i-1]-1]){
            if(f1 == 0){
                swap(a1[i],a1[i-1]);
                f1 = 1;
            } else {
                swap(a2[i],a2[i-1]);
                break;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i<n;i++)cout << a1[i] << " ";
    cout << endl;
    for(int i = 0;i<n;i++)cout << a2[i] << " ";
    cout << endl;
    for(int i = 0;i<n;i++)cout << a3[i] << " ";
    cout << endl;
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