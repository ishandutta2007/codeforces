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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 30;

ll s[MAXN], t[MAXN], n;
ll ind[MAXN], d[MAXN];

bool CMP(ll i, ll j){
	return s[i] < s[j];
}

vector< pair<pll, ll> > ans;

set<pll> st;

void fix(ll i, ll j){
	ll del = min(-d[j], d[i]);
	ans.pb({{i, j}, del});
	d[j] += del;
	d[i] -= del;
}

map<ll, ll> mp;

vector<ll> pos, neg;

void OK(){
	while(pos.size() > 0){
		if(d[pos.back()] == 0) pos.pop_back();
		else break;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		ind[i] = i;
		st.insert({s[i], i});
	}
	for(int i = 1; i <= n; i++){
		cin >> t[i];
	}
	sort(t + 1, t + n + 1);
	sort(ind + 1, ind + n + 1, CMP);
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; i++) mp[i] = ind[i];
	//for(int i = 1; i <= n; i++) cerr << t[i] << " \n"[i == n]; 
	for(int i = 1; i <= n; i++) d[i] = t[i] - s[i];
	//for(int i = 1; i <= n; i++) cerr << d[i] << " \n"[i == n];
		
	for(int i = 1; i <= n; i++){
		OK();
		if(d[i] > 0) pos.pb(i);
		else {
			while(pos.size() && d[i] < 0){
				fix(pos.back(), i);
				OK();
			}
		}
	}
	for(int i = 1; i <= n; i++) if(d[i] != 0) return cout << "NO\n", 0;
	/*cout << "YES\n";
	for(auto x : ans) cout << x.F.F << " " << x.F.S << " " << x.S << '\n'; 
	cout << "\n\n";
	
	
	cerr << st.size() << '\n';
	cerr << "san\n";*/
	//sort(s + 1, s + n + 1);
	//for(int i = 1; i <= n; i++) cout << s[i] << " ";
	//cout << '\n';
	cout << "YES\n";
	cout << ans.size() << '\n';
	for(auto x : ans) cout << mp[x.F.F] << " " << mp[x.F.S] << " " << x.S << '\n'; 
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