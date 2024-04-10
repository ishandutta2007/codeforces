#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
#define int ll 

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, m;
ll a[N];
vector<ll> V[N];
map<ll, ll> mp[N];
set<ll> st[N];

ll Solve(){
	for(int i = 1; i <= m; i++){
		st[a[i] + i].insert(a[i]);
		V[a[i] + 1].pb(i);
	}
	for(int i = 1; i <= n; i++) V[i].pb(0);
	ll ans = 0, wh;
	for(int i = 1; i <= n; i++){
		sort(all(V[i]));
		reverse(all(V[i]));
		for(auto T : V[i]){
			int L = max(1ll, i - (m + 1 - T));
			ll ln = T + i;
			if(st[ln].size() && *st[ln].begin() <= i){
				auto it = st[ln].upper_bound(i);
				it --;
				wh = *it;
				assert(mp[wh + 1][ln - wh]);
				L = mp[wh + 1][ln - wh];
			}
			mp[i][T] = L;
		}
		ans += (i - mp[i][0] + 1);
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(n == 1) return cout << "0\n", 0;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	ll ans = Solve() - n;
	for(int i = 0; i < N; i++) V[i].clear();
	for(int i = 0; i < N; i++) mp[i].clear();
	for(int i = 0; i < N; i++) st[i].clear();
	for(int i = 1; i <= m; i++) a[i] = n + 1 - a[i];
	//reverse(a + 1, a + 1 + m);
	cout << Solve() + ans << '\n';
	return 0;
}
/*
7 10
3 3 3 3 3 3 3 3 3 3

*/