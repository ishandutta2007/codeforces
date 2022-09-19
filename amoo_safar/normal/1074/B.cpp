#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll in1[MAXN], a[MAXN], b[MAXN], vis[MAXN], in2[MAXN];

vector<ll> g[MAXN];

ll n, m;

queue<ll> bf;
void check(ll nod){
	ll v;
	cout << "A " << nod << endl;
	cin >> v;
	if(in2[v] == 1){
		cout << "C " << nod << endl;
	} else {
		cout << "C -1" << endl;
	}
}
void solve(){
	memset(in1, 0, sizeof in1);
	memset(in2, 0, sizeof in2);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(vis, 0, sizeof vis);
	for(int i = 0;i < MAXN;i++) g[i].clear();
	while(bf.size() > 0) bf.pop();
	
	cin >> n;
	ll u, v;
	for(int i = 0;i<n-1;i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll k1,k2;
	cin >> k1;
	for(int i = 0; i < k1;i++){
		cin >> v;
		in1[v] = 1;
	}
	cin >> k2;
	for(int i = 0;i<k2;i++){
		cin >> a[i];
		in2[a[i]] = 1;
	}
	cout << "B " << a[0] << endl;
	ll no;
	cin >> no;
	bf.push(no);
	vis[no] = 1;
	while( bf.size() > 0){
		if(in1[bf.front()] == 1){
			check(bf.front());
			return ;
		}
		for(auto adj : g[bf.front()]){
			if(vis[adj] == 0){
				vis[adj] = 1;
				bf.push(adj);
			}
		}
		bf.pop();
	}
	
	
	cout << "C -1" << endl;
	return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T;
	cin >> T;
	while(T--) solve();

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