// I'll Crush you !
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
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}

int n, a[N];
int p[M];
map<int, vector<pii> > mp;

int la[Log], lf[N], rf[N];

vector<pii> seg[N << 2];
void Add(int id, int l, int r, pii x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		seg[id].pb(x);
		return ;
	}
	int mid = (L + R) >> 1;
	Add(id << 1, l, r, x, L, mid);
	Add(id << 1 | 1, l, r, x, mid, R);
}

void Calc(){
	for(auto [pr, V] : mp){
		//V.insert(V.begin(), {-1, Log - 1});
		//V.pb({n, Log - 1});
		int m = V.size();
		fill(la, la + Log, -1);
		for(int i = 0; i < m; i++){
			lf[i] = *max_element(la + V[i].S, la + Log);
			la[V[i].S] = V[i].F;
		}
		fill(la, la + Log, n);
		for(int i = m - 1; i >= 0; i--){
			rf[i] = *min_element(la + V[i].S + 1, la + Log);
			la[V[i].S] = V[i].F;
		}

		for(int i = 0; i < m; i++){
			int pww = bin_pow(pr, V[i].S);
			Add(1, lf[i] + 1, V[i].F + 1, pii(V[i].F, pww), 0, n);
			Add(1, lf[i] + 1, V[i].F + 1, pii(rf[i], inv(pww)), 0, n);
			//cerr << "! " << pww << ' ' << lf[i] << ' ' << V[i].F << ' ' << rf[i] << '\n';
		}
	}
}

void Build(int id, int L, int R){
	sort(all(seg[id]));
	for(int i = 1; i < seg[id].size(); i++)
		seg[id][i].S = mul(seg[id][i].S, seg[id][i - 1].S);
	if(L + 1 == R) return ;
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);
}

ll Get(int id, int x, int y, int L, int R){
	//debug(seg[id].size());
	ll res = 1;
	if(!seg[id].empty()){
		int idx = lower_bound(all(seg[id]), pii(y, Mod)) - seg[id].begin();
		//cerr << "###### " << idx << '\n';
		if(idx != 0){
			//cerr << "### " << idx << '\n';
			res = mul(res, seg[id][idx - 1].S);
		}
	}
	//cerr << "! " << id << ' ' << x << ' ' << y << ' ' << L << ' ' << R << '\n';
	if(L + 1 == R) return res;

	int mid = (L + R) >> 1;
	if(x < mid){
		res = mul(res, Get(id << 1, x, y, L, mid));
	} else {
		res = mul(res, Get(id << 1 | 1, x, y, mid, R));
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = M - 1; i >= 2; i--)
		for(int j = i; j < M; j += i)
			p[j] = i;
	cin >> n;
	int cnt, pr;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		
		while(a[i] != 1){
			cnt = 0;
			pr = p[a[i]];
			while(a[i] % pr == 0){
				cnt ++;
				a[i] /= pr;
			}
			mp[pr].pb({i, cnt});
		}
	}
	Calc();
	Build(1, 0, n);

	ll last = 0;
	ll q;
	cin >> q;
	ll l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		l = (l + last) % n;
		r = (r + last) % n;
		if(l > r) swap(l, r);
		//cerr << l << ' ' << r << '\n';
		last = Get(1, l, r, 0, n);
		cout << last << '\n';
	}
	return 0;
}

/*
6
2 4 3 6 8 12

*/