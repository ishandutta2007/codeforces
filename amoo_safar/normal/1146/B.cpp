#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll cnt[30];
ll nw[30];
ll ok;
void add(ll x){
	if(x == 0){
		if(nw[0] == cnt[0]) ok --;
		nw[0] ++;
		if(nw[0] == cnt[0]) ok ++;
		return ;
	}
	
	if(nw[x] + nw[x] == cnt[x]) ok --;
	nw[x] ++;
	if(nw[x] + nw[x] == cnt[x]) ok ++;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	//cin >> n;
	str s;
	cin >> s;
	n = s.size();
	ll ans = 0;
	for(auto x : s) cnt[x - 'a'] ++;
	ok = 0;
	for(int i = 0; i < 26; i++) if(cnt[i] == 0) ok ++;
	str an = "", f;
	ll fl = 0;
	for(auto x : s){
		add(x - 'a');
		an += x;
		if(ok == 26){
			fl = 1;
			break;
		}
	}
	if(fl == 0) return cout << ":(", 0;
	f = an;
	for(auto x : an) if(x != 'a') f += x;
	//debug(f);
	if(f == s) cout << an;
	else cout << ":(";
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