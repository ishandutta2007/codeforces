#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<ll> as(n);
	trav(x, as) cin >> x;

	vector<ll> pre(n+1);
	rep(i,0,n) pre[i+1] = pre[i] + as[i];

	ll cur = 0;

	rrep( j, 0, 60){
		ll want = cur + (1LL<<j);

		vector<ll> vis(n+1, 0);
		vis[0] = 1;

		rep(i,0,n) rep(j,i+1,n+1){
			ll dif = pre[j]-pre[i];
			if((dif & want) == want)
				vis[j] |= vis[i]<<1;
		}

		if(vis[n] & (1LL<<k)) cur = want;
	}
	
	cout << cur << endl;
}