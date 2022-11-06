#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

pii t[200010];

struct ST {
	int n;
	ST(int n) : n(n) {
		rep(i,0,n) t[i+n] = {i,i};
		rrep(i,1,n) t[i] = t[2*i+1];
	};

	void upd(int pos, int val){
		pii pa = {val, pos};
		for(pos += n; pos; pos /= 2) t[pos] = max(t[pos], pa);
	}

	pii que(int l, int r){
		pii ans(0,0);
		for(l += n, r += n; l < r; l /= 2, r /= 2){
			if(l&1) ans = max(ans, t[l++]);
			if(r&1) ans = max(ans, t[--r]);
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vi> ropes(n+1);
	rep(i,0,m){
		int l,r;
		cin >> l >> r;
		ropes[r].push_back(l);
	}
	int q;
	cin >> q;
	vector<pii> que(q);
	trav(pa, que) cin >> pa.first >> pa.second;
	vector<vi> ls(n+1);
	rep(i,0,q) ls[que[i].second].push_back(i);

	vi ans(q);

	ST st(n+1);

	function<int(int)> calc = [&](int l){
		int l1 = t[n+1+l].first;
		pii pa = st.que(l, l1+1);
		if(pa.first > l1){
			int ans = calc(pa.second);
			st.upd(l, ans);
			return ans;
		} else {
			return l1;
		}
	};

	rep(r,1,n+1){
		trav(l, ropes[r]){
			st.upd(l, r);
		}
		trav(i, ls[r]){
			int l = que[i].first;
			ans[i] = calc(l);
		}
	}
	trav(x, ans) cout << x << endl;
}