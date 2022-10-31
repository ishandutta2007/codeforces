#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 4000040
#define INF 101111111111111
using namespace std;
pll t[N];
ll w[N], n;
bool exists[N];

ll tllp[N];
void push(ll v){
	if(exists[v*2])t[v*2].x += w[v], t[v*2].y+=w[v];
	if(exists[v*2+1])t[v*2+1].x += w[v], t[v*2+1].y += w[v];
	if(exists[v*2]) w[v*2] += w[v];
	if(exists[v*2+1])w[v*2+1] += w[v];
	w[v] = 0;
}
inline pll recount(pll a, pll b){
	return {min(a.x, b.x), max(a.y, b.y)};
}
void build(ll v, ll tl, ll tr){
	exists[v] = true;
	if(tl != tr){
		ll tm = (tl+tr)>>1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = recount(t[v*2], t[v*2+1]);
	}else{
		t[v] = {0, 0};
		tllp[tl] = v;
	}
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll delta){
	if(l <= tl && r >= tr){
		w[v] += delta;
		t[v].x += delta;
		t[v].y += delta;
	}else{
		ll tm = (tl+tr)>>1;
		push(v);
		if(l <= tm && r >= tl  ) update(v*2, tl, tm, l, r, delta); 
		if(l <= tr && r >= tm+1) update(v*2+1, tm+1, tr, l, r, delta); 
		t[v] = recount(t[v*2], t[v*2+1]);
	}
}
pll get(ll v, ll tl, ll tr, ll l, ll r){
	if(l <= tl && r >= tr){
		return t[v];
	}else{
		ll tm = (tl+tr)>>1;
		push(v);
		bool cntd = false;
		pll res = {0, 0};
		if(l <= tm && r >= tl  ) res = get(v*2, tl, tm, l, r), cntd = true; 
		if(l <= tr && r >= tm+1) {
			pll y = get(v*2+1, tm+1, tr, l, r);
			if(cntd) res = recount(res, y);
			else res = y, cntd = true;
		}
		return res;
	}
}
//const ll MAX_LEN = 500005;
char text[500005];
int main(){
	FAST;
	ll n;
	cin >> n;
	string e, s;
	getline(cin, e);
	getline(cin, s);

	ll mc = 1, cc = 1;
	for(ll i = 0;i<n;i++){
		if(s[i] == 'L') mc = max(1ll, mc-1);
		else if(s[i] == 'R') ++mc;
		cc = max(cc, mc);
	}

	ll MAX_LEN = cc;
	build(1, 1, MAX_LEN);
	ll cursor = 1, rxdf = 0;
	for(ll i = 0;i<n;i++){
		if(s[i] == 'L') cursor = max(1ll, cursor-1);
		else if(s[i] == 'R') ++cursor;
		else{
			char old = text[cursor];
			char nw = s[i];
			if(old == '('){
				update(1, 1, MAX_LEN, cursor, MAX_LEN, -1);
				rxdf--;
			}else if(old == ')'){
				update(1, 1, MAX_LEN, cursor, MAX_LEN, 1);
				rxdf++;
			}
			if(nw == '('){
				update(1, 1, MAX_LEN, cursor, MAX_LEN, 1);
				rxdf++;
			}else if(nw == ')'){
				update(1, 1, MAX_LEN, cursor, MAX_LEN, -1);
				rxdf--;
			}
			text[cursor] = nw;
		}
		//pll rs = get(1, 1, MN, 1, MN);
		if(t[1].x >= 0 && rxdf == 0) cout << t[1].y << " ";
		else cout << -1 << " ";
	}
	cout << endl;
}