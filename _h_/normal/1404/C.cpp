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

struct FT {
	vi t;
	FT(int n){
		t.resize(n+1);
	}

	void upd(int pos, int dif){
		for(++pos; pos < sz(t); pos += pos & -pos)
			t[pos] += dif;
	}
	int que(int to){
		int ans = 0;
		for(; to; to -= to & -to)
			ans += t[to];
		return ans;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, q;
	cin >> n >> q;

	vi as(n);
	trav(a, as) cin >> a;

	vector<vector<pii>> qs(n);
	rep(i,0,q){
		int x, y;
		cin >> x >> y;
		qs[n-1-y].emplace_back(x, i);
	}

	vi ans(q);

	FT ft(n);

	rep(i,0,n){
		if(as[i] <= i+1){
			int lo = -1, hi = i+1;
			while(lo+1 < hi){
				int mi = (lo + hi)/2;
				if(ft.que(mi+1) >= i+1-as[i]) lo = mi;
				else hi = mi;
			}
			if(lo != -1){
				ft.upd(0, 1);
				if(lo+1 < n) ft.upd(lo+1, -1);
			}
		}
		trav(pa, qs[i]){
			ans[pa.second] = ft.que(1+pa.first);
		}
	}
	
	trav(x, ans) cout << x << endl;
}