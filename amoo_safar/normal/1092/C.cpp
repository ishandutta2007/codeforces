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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll n;
str s[MAXN], s2[MAXN];
//set<str> pre;
map<str, ll> mp;


bool check(str st){
	//debug(st);
	mp.clear();
	for(int i = 0 ; i < n + n - 2; i++){
		mp[s[i]] ++;
	}
	str pr = "";
	for(int i = 0;i<n-1;i++){
		pr += st[i];
		mp[pr]--;
		if(mp[pr] < 0) return false;
	}
	pr = "";
	for(int i = n - 1;i>=1;i--){
		pr = st[i] + pr;
		mp[pr]--;
		if(mp[pr] < 0) return false;
	}
	return true;
}

bool CMP( str t, str s){
	return t.size()< s.size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	str t, big = "", big2 = "";
	for(int i = 0;i<n + n - 2; i++){
		cin >> t;
		s[i] = t;
		s2[i] = t;
		if(t.size() == big.size()) big2 = t;
		if(t.size() > big.size()) big = t;
	}
	if(n == 2) return cout << "PS\n" , 0;
	sort(s, s + n + n - 2, CMP);
	str out="";
	if(check(s[0] + s[n+n-3])) out = s[0] + s[n+n-3];
	if(check(s[0] + s[n+n-4])) out = s[0] + s[n+n-4];
	if(check(s[1] + s[n+n-3])) out = s[1] + s[n+n-3];
	if(check(s[1] + s[n+n-4])) out = s[1] + s[n+n-4];
	//debug(out);
	mp.clear();
	str pr = "", ans = "";
	for(int i = 0;i < n - 1;i++){
		pr += out[i];
		mp[pr] = 1;
		//debug(pr);
		//pre.insert(pr);
	}
	ll p = 0;
	for(int i = 0;i < n + n - 2; i++){
		if(mp[s2[i]] == 1){
			ans = ans + "P";
			p++;
			mp[s2[i]] = 0;
			//pre.erase(s[i]);
		} else ans = ans + "S";
	}
	cout << ans;
	
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