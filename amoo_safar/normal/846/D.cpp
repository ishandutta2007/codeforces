#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
 
const ld PI = 3.14159265359;
 
const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 5e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN][MAXN];
ll mn[MAXN][MAXN];
deque<ll> deq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(a, 31, sizeof a);
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	ll x, y, t;
	for(int i = 0;i<q;i++){
		cin >> x >> y >> t;
		a[x][y] = t;
	}
	for(int i = 1; i <= n; i++){
		while(deq.size()) deq.pop_back();
		for(int j = 1; j < k; j++){
			while(deq.size() && a[i][deq.back()] <= a[i][j]) deq.pop_back();
			deq.pb(j);
		}
		for(int j = k; j <= m; j++){
			if(deq.front() == j - k) deq.pop_front();
			while(deq.size() && a[i][deq.back()] <= a[i][j]) deq.pop_back();
			deq.pb(j);
			mn[i][j] = a[i][deq.front()];
		}
	}
	ll mx, ans = INF;
	for(int i = k; i <= n; i++)
		for(int j = k; j <= m; j++){
			mx = 0;
			for(int l2 = i - k + 1; l2 <= i; l2++){
				mx = max(mx, mn[l2][j]);
			}
			ans = min(ans, mx);
		}
	if(ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

////////////////////////////////////////////// please don't use anti-hash anti-random tests;