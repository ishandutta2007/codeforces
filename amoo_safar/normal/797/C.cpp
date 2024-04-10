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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll cnt[26];
vector<char> t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();
	for(int i = 0;i<n;i++){
		cnt[s[i]-'a']++;
	}
	str u="";
	ll ind;
	char c;
	ll i = 0;
	while(i < n){
		//debug(i);
		ind = -1;
		for(int j = 0;j<26;j++){
			if(cnt[j] > 0){
				ind = j;
				break;
			}
		}
		c = (char)('a' + ind);
		if(t.size() != 0){
			if(t.back() <= c){
				u += t.back();
				t.pop_back();
				continue;
			}
		}
		//debug(i);
		while(s[i] != c){
			t.pb(s[i]);
			cnt[s[i]-'a']--;
			i++;
		}
		u += s[i];
		cnt[s[i]-'a']--;
		i++;
	}
	while(t.size()!= 0){
		u += t.back();
		t.pop_back();
	}
	cout << u;
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