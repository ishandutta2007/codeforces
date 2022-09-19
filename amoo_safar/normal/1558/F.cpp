// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 998244353;
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const int Sq = 300;

typedef pair<int, int> pii;

int seg[N << 2];
int lz[N << 2];
void Apply(int id, int x){
	seg[id] += x;
	lz[id] += x;
}
void Shift(int id){
	Apply(id << 1, lz[id]);
	Apply(id << 1 | 1, lz[id]);
	lz[id] = 0;
}
void Add(int id, int l, int r, int x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id, x);
		return ;
	}
	int mid = (L + R) >> 1;
	Shift(id);
	Add(id << 1, l, r, x, L, mid);
	Add(id <<1|1,l, r, x, mid, R);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int Get(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return -N;
	if(l <= L && R <= r) return seg[id];
	int mid = (L + R) >> 1;
	Shift(id);
	return max(Get(id << 1, l, r, L, mid), Get(id <<1|1,l, r, mid, R));
}
int p[N];

int Main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		p[v] = i;
	}
	Add(1, 0, n, -N, 0, n);
	// debug(seg[1]);
	for(int i = 0; i < n; i += 2) Add(1, i, i + 1, +1, 0, n);
	for(int i = 0; i <= n;i++) Add(1, i, i + 1, +i, 0, n);
	set<int> st;
	for(int i = 0; i < n; i++) st.insert(i);
	int ans = 0;
	
	for(int i = 1; i < n; i++){
		int pos = p[i];
		Add(1, pos, pos + 1, +N, 0, n);

		st.erase(p[i]);
		int mn = *st.begin();
		Add(1, pos + 1, n, -1, 0, n); 
		Add(1, 0, pos,     +1, 0, n);
		int res = Get(1, mn, n, 0, n);
		// debug(mn);
		// debug(res);
		ans = max(ans, res);
	}
	cout << ans << '\n';
	fill(seg, seg + (4*n), 0);
	fill(lz , lz + (4*n), 0);
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}