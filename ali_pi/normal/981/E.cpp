#include <bits/stdc++.h>

using namespace :: std;

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

	int n, q;
	cin >> n >> q;

	vector<pair<pii, int>> ops(q);

	trav(tr, ops){
		int l,r,x;
		cin >> l >> r >> x;
		tr = pair<pii,int>(pii(l, r), x);
	}

	sort(all(ops));

	vi val(n+1, 0);

	val[0] = n;

	trav(tr, ops){
		int l = tr.first.first,
	  	    r = tr.first.second,
		    x = tr.second;


		rrep(i,x,n+1) if(val[i-x] >= l)
			val[i] = max(val[i], min(r, val[i-x]));
	}

	vi ans;
	rep(i,1,n+1) if(val[i]) ans.push_back(i);
	cout << sz(ans) << endl;
	trav(x, ans) cout << x << ' ';
	cout << endl;
}