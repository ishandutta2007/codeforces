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

char ans[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s1, s2, s3, t1, t2, t3, t;

	for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) for(int k = 0; k < 26; k++) s1 += ((char)('a' + i));
	for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) for(int k = 0; k < 26; k++) s2 += ((char)('a' + j));
	for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) for(int k = 0; k < 26; k++) s3 += ((char)('a' + k));
	ll n;
	cin >> t;
	n = t.size();
	cout << "? ";
	for(int i = 0; i <n; i++) cout << s1[i];
	cout << endl;
	cin >> t1;
	
	cout << "? ";
	for(int i = 0; i <n; i++) cout << s2[i];
	cout << endl;
	cin >> t2;
	
	cout << "? ";
	for(int i = 0; i <n; i++) cout << s3[i];
	cout << endl;
	cin >> t3;
	cout << "! ";
	
	for(int i = 0; i< n; i++){
		ans[26 * 26 * (t1[i] - 'a') + 26 * (t2[i] - 'a') + (t3[i] - 'a')] = t[i];
	}
	for(int i = 0; i< n;i++) cout << ans[i];
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