# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int N = 1e5;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

vector <int> adj[xn];
ll q, fac[xn], inv[xn];

int mp[xn];
bool check[xn];

ll ent(ll n, ll k){
	if (n < k) return 0;
	ll a = fac[n], b = inv[k], c = inv[n-k];
	a *= b, a = (a + md) % md;
	a *= c, a = (a + md) % md;
	return a;
}

void Solve(ll n, ll k){
	if (k == 1){
		mp[n] = (n == 1);
		check[n] = true;
		return;
	}
	if (check[n]) return;
	ll ans = ent(n-1, k-1);
	for (int i = 0; i < adj[n].size(); i++){
		ll g = adj[n][i];
		Solve(g, k);
		ans -= mp[g];
		ans = (ans + 100*md) % md;
	}
	mp[n] = ans;
	check[n] = true;
	return;
}
bool cmp(int i, int j){
	return j > i;
}
 
int main(){
	fast_io;
	
	int mx = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 2; j <= sqrt(i); j++){
			if (i%j == 0) adj[i].pb(j);
			else continue;
			if (i/j != j) adj[i].pb(i/j);
		}
		sort(adj[i].begin(), adj[i].end(), cmp);
		mx = max(mx, int(adj[i].size()));
	}
	fac[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= N; i++){
		fac[i] = i * (fac[i-1]);
		fac[i] = (fac[i] + md) % md;
		inv[i] = power(fac[i], md - 2);
	}
	
	cin >> q;
	while (q--){
		ll n, k;
		cin >> n >> k;
		memset(check, false, xn);
		Solve(n, k);
		cout << mp[n] << endl;
	}
	
	
	return 0;
}