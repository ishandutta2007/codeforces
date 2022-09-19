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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int seg[N << 2];
int lz[N << 2];

void Apply(int id, int x, int L, int R){
	seg[id] = x * (R - L);
	lz[id] = x;
}
void Shift(int id, int L, int R){
	if(lz[id] == -1) return ;
	int mid = (L + R ) >> 1;
	Apply(id << 1, lz[id], L, mid);
	Apply(id << 1 |1, lz[id], mid, R);
	lz[id] = -1;
}

void Set(int id, int x, int l, int r, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id, x, L, R);
		return ;
	}
	Shift(id, L, R);
	int mid = (L + R) >> 1;
	Set(id << 1, x, l, r, L, mid);
	Set(id << 1 |1, x, l, r, mid, R);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int Get(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return 0;
	if(l <= L && R <= r) return seg[id];
	Shift(id, L, R);
	int mid = (L + R) >> 1;
	return Get(id << 1, l, r, L, mid) + Get(id << 1 |1, l, r, mid, R);
}


ll k, a[N];

ll lq[N], rq[N];

int Main(){
	int n, q;
	cin >> n >> q;
	str s, f;
	cin >> s >> f;
	for(int i = 0; i < q; i++){
		cin >> lq[i] >> rq[i];
		lq[i] --;
	}
	for(int i = 0; i < n; i++)
		Set(1, f[i] - '0', i, i + 1, 0, N);
	for(int i = q - 1; i >= 0; i--){
		int ln = rq[i] - lq[i];
		int sm = Get(1, lq[i], rq[i], 0, N);
		if(sm + sm == ln)
			return cout << "NO\n", 0;
		if(sm > ln - sm)
			Set(1, 1, lq[i], rq[i], 0, N);
		else
			Set(1, 0, lq[i], rq[i], 0, N);
	}
	for(int i = 0; i < n; i++){
		if(s[i] - '0' != Get(1, i, i + 1, 0, N))
			return cout << "NO\n", 0;
	}
	cout << "YES\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(lz, -1, sizeof lz);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}