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
#define N 200000
#define INF 101111111111111
using namespace std;
pll et[N];
ll get(ll se, ll sh, ll ae, ll ah, ll ovt, ll a, ll b){
	ll ct = min(ae-se, ovt/a);
	ovt -= ct*a;
	ll xt = min(ah-sh, ovt/b);
	return ct+xt;
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, t, a, b, ae = 0, ah = 0;
		cin >> n >> t >> a >> b;
		for(ll i =0;i<n;i++){
			cin >> et[i].x;
			if(et[i].x == 0) ae++;
			else ah++;
		}
		for(ll i =0;i<n;i++) cin >> et[i].y;
		sort(et, et+n, [](pll a, pll b){
			return a.y < b.y;
		});
		ll se = 0, sh = 0;
		ll res = 0;
		for(ll i = 0;i<n;i++){
			if(et[i].y > 0){
				ll time = et[i].y-1;
				ll ovt = time - se*a - sh*b;
				if(ovt >= 0) res = max(res, se+sh+get(se, sh, ae, ah, ovt, a, b));
			}
			if(et[i].x == 0) se++;
			else sh++;
		}
		ll ovt = t - ae*a - ah*b;
		if(ovt >= 0) res = max(res, ae+ah);
		cout << res << endl;
	}
}