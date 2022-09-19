#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e3 + 10;
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int num(char c){
	return c - 'a';
}

struct photo{
	int x1, x2, y1, y2;
	char e;
	void in(){
		cin >> x1 >> y1 >> x2 >> y2 >> e;
	}
};

photo P[N];
str a[Maxn];
ll cnt[28][Maxn][Maxn];
ll C[Maxn][Maxn];


ll val[Maxn][Maxn], psval[Maxn][Maxn];



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = '!' + a[i];
	}
	for(int i = 1; i <= k; i++) P[i].in();
	for(int i = 1; i <= k; i++){
		C[P[i].x1][P[i].y1] ++;
		C[P[i].x1][P[i].y2 + 1] --;
		C[P[i].x2 + 1][P[i].y1] --;
		C[P[i].x2 + 1][P[i].y2 + 1] ++;
		
		cnt[num(P[i].e)][P[i].x1][P[i].y1] ++;
		cnt[num(P[i].e)][P[i].x1][P[i].y2 + 1] --;
		cnt[num(P[i].e)][P[i].x2 + 1][P[i].y1] --;
		cnt[num(P[i].e)][P[i].x2 + 1][P[i].y2 + 1] ++;
	}
	for(int al = 0; al < 26; al ++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++) cnt[al][i][j] += (cnt[al][i - 1][j] + cnt[al][i][j - 1] - cnt[al][i - 1][j - 1]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			C[i][j] += (C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1]);
			cnt[num(a[i][j])][i][j] += (k - C[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int al = 0; al < 26; al++) val[i][j] += abs(al - num(a[i][j])) * cnt[al][i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			psval[i][j] = (val[i][j] + psval[i - 1][j] + psval[i][j - 1] - psval[i - 1][j - 1]);
		}
	}

	for(int al = 0; al < 26; al ++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++) cnt[al][i][j] += (cnt[al][i - 1][j] + cnt[al][i][j - 1] - cnt[al][i - 1][j - 1]);
		}
	}

	//cerr << psval[n][m] << '\n';
	ll ans = Inf;
	for(int i = 1; i <= k; i++){
		ll res =  psval[n][m] - (  psval[P[i].x2][P[i].y2] - psval[P[i].x2][P[i].y1 - 1] - psval[P[i].x1 - 1][P[i].y2] + psval[P[i].x1 - 1][P[i].y1 - 1]  );
		//cerr << res << '\n';
		for(int al = 0; al < 26; al++){
			res += abs(num(P[i].e) - al) * ( cnt[al][P[i].x2][P[i].y2] - cnt[al][P[i].x2][P[i].y1 - 1] - cnt[al][P[i].x1 - 1][P[i].y2] + cnt[al][P[i].x1 - 1][P[i].y1 - 1] );
		}
		ans = min(ans, res);
		//cerr << res << '\n';
		//cerr << '\n';
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