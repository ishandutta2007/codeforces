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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

set<char> st;

str s;

bool check(str t){
	for(int i = 0, j = t.size() - 1; i < j; i++, j--){
		if(t[i] != t[j]) return false;
	}
	return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	ll n = s.size();
	for(int i = 0; i< n/2;i++) st.insert(s[i]);
	if(st.size() <= 1) return cout << "Impossible", 0;
	str r = "";
	for(int i = 1; i < n - 1; i++){
		r = "";
		for(int j = i; j<n;j++) r+= s[j];
		for(int j = 0; j< i; j++) r += s[j];
		if(check(r) && s != r) return cout << 1, 0;
		//debug(r);
	}
	cout << 2;
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