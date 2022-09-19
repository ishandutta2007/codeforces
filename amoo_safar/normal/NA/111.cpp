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

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;



ll a[MAXN];
ll b[MAXN];
ll po, ii, jj, cnt = 0;
void merg(ll l, ll mid, ll r){
    //cerr << "start" << endl;
    //for(int i = l; i <= r; i++) cerr << a[i] << " ";
    //cerr << endl;
    po = 0;
    ii = l;
    jj = mid + 1;
    while((ii <= mid) and (jj <= r)){
        if(a[ii] > a[jj]){
            b[po] = a[jj];
            jj ++;
            cnt = cnt + (mid - ii + 1);
        } else {
            b[po] = a[ii];
            ii ++;
        }
        po++;
        //cout << ii << " " << jj << "   ";
    }
    //cout << endl;
    for(int i = ii; i <= mid; i++){
        b[po] = a[i];
        po++;
    }
    for(int i = jj; i <= r; i++){
        b[po] = a[i];
        po++;
    }
    //cout << po << " " << l << " " << r << " " << mid << endl;
    //for(int i = 0; i < po; i++) cerr << b[i] << " ";
    //cerr << endl;
    for(int i = 0;i < po;i++){
        a[l + i] = b[i];
        //cout << b[i] << " ";
    }
    //cout << endl;
}
void merge_sort(ll l, ll r){
    if(l == r)return ;
    merge_sort(l,(l + r)/2);
    merge_sort((l + r)/2 + 1,r);
    merg(l,(l + r)/2,r);
}

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    merge_sort(0, n-1);
    //for(int i =0;i<n;i++)cout << a[i] << " ";
    //cout << cnt << endl;
    if(cnt % 2 == n % 2) cout << "Petr";
    else cout << "Um_nik";
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