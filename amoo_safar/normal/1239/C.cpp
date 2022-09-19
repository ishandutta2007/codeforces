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
const int Maxn = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int seg[Maxn << 2];
void change(int id, int i, int x, int L, int R){
	if((i < L) || (R <= i)) return ;
	if((L + 1 == R) && (L == i)){
		seg[id] = x;
		return ;
	}
	
	int mid = (L + R) >> 1;
	change(id << 1, i, x, L, mid);
	change(id << 1 | 1, i, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
int get(int id, int l, int r, int L, int R){
	if((r <= L) || (R <= l)) return Maxn;
	if((l <= L) && (R <= r)) return seg[id];
	int mid = (L + R) >> 1;
	return min(get(id << 1, l, r, L, mid), get(id << 1 | 1, l, r, mid, R));
}

ll a[Maxn], ans[Maxn];
vector<pll> V;
ll p = 0, P;
ll T = 0;
queue<ll> q;
set<ll> inq;
set<pll> S; 

void coc(ll al){
	T = max(T, al);
	while(V[p].F <= T){
		change(1, V[p].S, V[p].S, 1, Maxn);
		p ++;
	}
}

bool opp(){
	ll mx = *inq.begin();
	ll tg = get(1, 1, mx, 1, Maxn);
	if(tg == Maxn) return false;
	change(1, tg, Maxn, 1, Maxn);
	//cerr << tg << ' ' << T << '\n';
	q.push(tg);
	inq.insert(tg);
	if(q.size() == 1){
		ans[tg] = T + P;
	} else {
		ans[tg] = max(T + P, ans[q.front()] + (((ll) q.size()) - 1LL) * P); 
	}
	S.insert({ans[tg], 1});
	S.insert({ans[tg], 2});
	coc(T + 1);
	return true;
}

void ppp(){
	if(q.size() == 0) return ;
	ll fr = q.front();
	q.pop();
	//cerr << fr << '\n';
	inq.erase(fr);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fill(seg, seg + 4*Maxn, Maxn);
	inq.insert(Maxn);
	
	
	ll n;
	cin >> n >> P;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		V.pb({a[i], i});
		S.insert({a[i], 2});
		
	}
	sort(all(V));
	V.pb({Inf, -1});
	
	pll ev;
	while(S.size()){
		ev = *S.begin();	
		S.erase(ev);
		
		//cerr << ev.F << ' ' << p << '\n';
		coc(ev.F);
		if(ev.S == 2){
			opp();
		} else {
			ppp();
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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