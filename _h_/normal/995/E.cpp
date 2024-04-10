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

ll mexp(ll a, ll p, ll e){
	ll res = 1;
	while(e){
		if(e&1) res = res * a % p;
		a = a*a % p;
		e /= 2;
	}
	return res;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int u, v, p;
	cin >> u >> v >> p;

	auto f = [&](int x, int dir){
		x = (x+p+dir)%p;
		x = mexp(x, p, p-2);
		return x;
	};

	vi s(1<<20), t(1<<20);

	auto explore = [&](int x, vi &res){
		res[0] = x;
		rep(i,1,1<<20)
			res[i] = f(res[i/2], i%2 ? 1 : -1);
	};

	auto fromNum = [&](int i, vi &res){
		if(i==0) return;
		int e = 31 - __builtin_clz(i);
		rrep(j,0,e+1){
			res.push_back(i&(1<<j) ? 1 : 2);
			res.push_back(3);
		}
	};

	explore(u, s), explore(v, t);

	map<int,int> vis;
	rep(i,0,1<<20) vis[s[i]] = i;

	rep(j,0,1<<20){
		int x = t[j];
		auto it = vis.lower_bound(x);
		if(it==vis.end()) continue;

		if(it->first - x <= 130){
			vi ans;
			int i = it->second;
			fromNum(i, ans);
			rep(_,0,it->first - x) ans.push_back(2);
			vi snd;
			fromNum(j, snd);
			trav(x, snd) if(x <= 2) x = 3-x;
			reverse(all(snd));
			trav(x, snd) ans.push_back(x);

			ll cur = u;
			trav(x, ans){
				if(x==1) cur = (cur+1)%p;
				if(x==2) cur = (cur+p-1)%p;
				if(x==3) cur = mexp(cur,p,p-2);
			}
			assert(cur==v);
			cout << sz(ans) << endl;
			trav(x, ans) cout << x << ' ';
			return 0;
		}
	}
	return 1;
}