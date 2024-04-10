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

const ll Mod = 1000000007LL;
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll seg[N << 2], lz[N << 2];
void Apply(int id, ll x){
	seg[id] += x;
	lz[id] += x;
}
void Shift(int id){
	Apply(id << 1, lz[id]);
	Apply(id << 1|1, lz[id]);
	lz[id] = 0;
}
void Add(int id, int l, int r, ll x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id, x);
		return ;
	}
	Shift(id);
	int mid = (L + R) >> 1;
	Add(id << 1, l, r, x, L, mid);
	Add(id<<1|1, l, r, x, mid, R);
	seg[id] = max(seg[id << 1], seg[id<<1|1]);
}

int a[N];
ll b[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	a[0] = -1;
	Add(1, 0, N, -Inf, 0, N);
	// debug(seg[0]);
	Add(1, 1, 2, Inf, 0, N);
	vector<int> V = {0};
	int m;
	ll dp;
	for(int i = 1; i <= n; i++){
		while(a[V.back()] > a[i]){
			m = V.size();
			Add(1, V[m - 2] + 1 , V[m - 1] + 1, -b[V [m-1] ], 0, N);
			V.pop_back();
		}
		Add(1, V.back() + 1, i + 1, b[i], 0, N);
		V.pb(i);
		dp = seg[1];
		// debug(dp);
		Add(1, i + 1, i + 2, Inf + dp, 0, N);
	}
	cout << dp << '\n';
	return 0;
}