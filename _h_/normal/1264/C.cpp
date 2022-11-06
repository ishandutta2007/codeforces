// written by aitch
// on 2019 12/05 at 14:35:01
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll md = 998244353;

ll mexp(ll a, ll e){
	ll res = 1;
	do {
		if(e & 1) res = res * a % md;
		a = a * a % md;
	} while(e >>= 1);
	return res;
}

ll inv(ll a){
	return mexp(a, md-2);
}

vector<ll> p;

pll comp(pll f, pll g){
	return pll(f.first * g.first % md, 
		  (f.second * g.first + g.second)%md);
}

struct Node {
	int fr, to, mi;
	Node *l, *r;
	pll ab;
	Node(int _fr, int _to) : fr(_fr), to(_to) {
		mi = (fr + to)/2;
		if(fr+1 < to){
			l = new Node(fr, mi);
			r = new Node(mi, to);
			ab = comp(l->ab, r->ab);
		} else {
			l = r = 0;
			ab = pll(inv(p[fr]), inv(p[fr]));
		}
	}

	pll que(int lo, int hi){
		if(lo <= fr && to <= hi)
			return ab;
		if(lo >= to || hi <= fr)
			return pll(1,0);
		return comp(l->que(lo,hi), r->que(lo,hi));
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll hun = inv(100);

	int n, q;
	cin >> n >> q;

	p.resize(n);
	trav(x, p) cin >> x, x = x * hun % md;

	set<int> checks;
	checks.insert(0);
	checks.insert(n);

	Node root(0,n);
	
	ll ans = root.que(0,n).second;
	rep(_,0,q){
		int u;
		cin >> u;
		--u;
		if(checks.count(u)){
			checks.erase(u);
			auto iter = checks.lower_bound(u);
			int jt = *iter;
			--iter;
			int it = *iter;
			ans = (ans - root.que(it,u).second
				   - root.que(u,jt).second
				   + root.que(it,jt).second )%md;
			if(ans < 0) ans += md;
			cout << ans << endl;
		} else {
			auto iter = checks.lower_bound(u);
			int jt = *iter;
			--iter;
			int it = *iter;
			checks.insert(u);
			ans = (ans + root.que(it,u).second
				   + root.que(u,jt).second
				   - root.que(it,jt).second )%md;
			if(ans < 0) ans += md;
			cout << ans << endl;
		}
	}
	_Exit(0);
}