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
const ll Log = 8;
const ll M = (1 << Log) + 10;

ll mx[M], dp[N][M], L, R;
vector<ll> V, V2;
vector<pll> E[N];
ll mp[N], l[N], r[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		r[i] ++;
		V.pb(l[i]);
		V.pb(r[i]);

	}
	sort(all(V));
	V.resize(unique(all(V)) - V.begin());
	ll L, R;
	for(int i = 0; i < n; i++){
		L = lower_bound(all(V), l[i]) - V.begin();
		R = lower_bound(all(V), r[i]) - V.begin();
		for(int j = L; j < R; j++) E[j].pb({r[i], i});
	}
	ll nn = V.size() - 1;
	for(int i = 0; i < N; i++) fill(dp[i], dp[i] + M, -Inf);
	ll ans = 0;
	for(int j = 0; j < 1 << (E[0].size()); j++){
		if(__builtin_popcount(j) % 2 == 1) dp[0][j] = V[1] - V[0];
		else dp[0][j] = 0;
		ans = max(ans, dp[0][j]);
	}
	for(int i = 1; i < nn; i++){
		ll mk = 0;
		for(int j = 0; j < E[i - 1].size(); j++){
			if(E[i - 1][j].F != V[i]) mk |= (1 << j);
			mp[E[i - 1][j].S] = j;
		}
		fill(mx, mx + M, -Inf);
		for(int j = 0; j < 1<<(E[i - 1].size()); j++) mx[j & mk] = max(mx[j & mk], dp[i - 1][j]);
	

		for(int j = 0; j < 1<<(E[i].size()); j++){
			int rq = 0;
			for(int jj = 0; jj < E[i].size(); jj++){
				if((j >> jj & 1) && (V[i] != l[E[i][jj].S])){
					rq |= (1 << mp[E[i][jj].S]);
				}
			}
			dp[i][j] = mx[rq];
			if(__builtin_popcount(j) % 2 == 1) dp[i][j] += V[i + 1] - V[i];
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}