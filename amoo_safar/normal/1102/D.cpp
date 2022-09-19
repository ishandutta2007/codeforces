#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

//vector<ll> c1, c2, c0;
ll cnt[3];
ll cn[3];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	str s;
	cin >> n >> s;
	ll m = n/3;
	ll c1 = 0;
	ll c2 = 0;
	ll c3 = 0;
	for(int i = 0;i<n;i++){
		cnt[s[i] - '0'] ++;
	}
	ll f;
	for(int i = 0; i < n; i++){
		
		f = -1;
		for(int j = 0; j < (s[i]-'0');j++){
			if(cnt[j] < m and cnt[s[i]-'0'] > m){
				f = j;
				break;
			}
		}
		if(f!=-1){
			cout << ((char) (f + '0'));
			cnt[s[i]-'0']--;
			cnt[f]++;
			cn[f] ++;
		} else if( (cnt[s[i]-'0'] <= m) or ((cnt[s[i]-'0'] > m) and (cnt[s[i]-'0'] - (cn[s[i]-'0'] + 1) >= (cnt[s[i]-'0'] - m) ) )){
			//debug(cn[s[i]-'0']);
			cout << s[i];
			cn[s[i]-'0']++;
		} else {
			f = -1;
			for(int j = (s[i]-'0') + 1; j < 3;j++){
				if(cnt[j] < m and cnt[s[i]-'0'] > m){
					f = j;
					break;
				}
			}
			cout << ((char) (f + '0'));
			cnt[s[i]-'0']--;
			cnt[f]++;
			cn[f] ++;
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