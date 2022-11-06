#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mx = 5001;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	vector<bool> ispr(mx, true);
	vi primes;
	rep(p,2,mx) if(ispr[p]){
		primes.push_back(p);
		for(int q = p * p; q < mx; q += p)
			ispr[q] = false;
	}

	int n;
	cin >> n;

	vi cnt(mx);
	rep(_,0,n){
		int k;
		cin >> k;
		++cnt[k];
	}
	vector<vi> emb(mx, vi(sz(primes)));
	rep(i,0,sz(primes)) rep(k,0,mx){
		int q = primes[i];
		do {
			emb[k][i] += k / q;
			q *= primes[i];
		} while(q <= k);
	}
	vi pre(mx+1);
	rep(k,0,mx) pre[k+1] = pre[k] + cnt[k];
	vector<vector<ll>> sum(sz(primes)+1, vector<ll>(mx+1));
	rep(i,0,sz(primes)) rep(k,0,mx)
		sum[i+1][k+1] = sum[i+1][k] + sum[i][k+1] - sum[i][k]
				+ ll(cnt[k]) * emb[k][i];

	auto rect = [&](int i1, int i2, int k1, int k2){
		return sum[i2][k2]
		     - sum[i1][k2]
		     - sum[i2][k1]
		     + sum[i1][k1];
	};

	function<ll(int,int,int)> rek = [&](int fr, int to, int i){
		if(i == -1) return 0LL;
		ll ans = rect(0, i+1, fr, to);
		ll miss = n - (pre[to] - pre[fr]);
		for(int ix = fr; ix < to;){
			ll e = emb[ix][i];
			int jx = ix+1;
			while(jx < to && emb[jx][i] == e) ++jx;
			ll cur = rect(0,i, fr,ix)
				+rect(0,i, jx,to);
			cur +=  rect(i,i+1, jx,to) - e*(pre[to]-pre[jx]);
			cur += -rect(i,i+1, fr,ix) + e*(pre[ix]-pre[fr]);
			cur += e * miss;
			ans = min(ans, cur + rek(ix,jx,i-1));
			ix = jx;
		}
		return ans;
	};
	cout << rek(0, mx, sz(primes)-1) << endl;
}