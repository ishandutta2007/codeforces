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

ll md = 998244353;

struct node {
	int fr, to;
	node *l, *r;
	ll sum = 0;
	ll tomul = 1, toadd = 0;

	node(int _fr, int _to){
		fr = _fr;
		to = _to;
		int mi = (fr+to)/2;
		if(fr+1 < to){
			l = new node(fr, mi);
			r = new node(mi, to);
		} else {
			l = r = 0;
		}
	}

	void mul(ll f){
		tomul = tomul*f % md;
		toadd = toadd*f % md;
		sum   = sum  *f % md;
	}

	void add(ll t){
		toadd = (toadd + t) % md;
		sum   = (sum + (to-fr)*t)%md;
	}

	void push(){
		if(tomul==1 && toadd==0) return;
		if(!l) return;
		
		l->mul(tomul), r->mul(tomul);
		l->add(toadd), r->add(toadd);

		tomul = 1, toadd = 0;
	}

	void mulran(ll f, int lo, int hi){
		if(lo==hi) return;
		if(lo >= to || hi <= fr) return;
		if(lo <= fr && to <= hi){
			mul(f);
			return;
		}
		push();
		l->mulran(f,lo, hi);
		r->mulran(f,lo, hi);
		sum = (l->sum + r->sum) % md;
	}

	void addran(ll t, int lo, int hi){
		if(lo==hi) return;
		if(lo >= to || hi <= fr) return;
		if(lo <= fr && to <= hi){
			add(t);
			return;
		}
		push();
		l->addran(t,lo, hi);
		r->addran(t,lo, hi);
		sum = (l->sum + r->sum) % md;
	}
	
	ll query(int lo, int hi){
		if(lo==hi) return 0;
		if(lo >= to || hi <= fr) return 0LL;
		if(lo <= fr && to <= hi) return sum;
		push();
		return l->query(lo, hi) + r->query(lo, hi);
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<set<pii>> ls(n);
	rep(i,0,n){
		ls[i].insert(pii(0,1));
		ls[i].insert(pii(n+1,n+2));
	}
	node segt(1, n+1);

	rep(_,0,q){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			--x, ++r;

			auto it = ls[x].upper_bound(pii(l,l));
			--it;
			if(it->second <= l) ++it;

			vector<pii> ps;
			while(it->first < r){
				ps.push_back(*it);
				auto nxt = it;
				++nxt;
				ls[x].erase(it);
				it = nxt;
			}

			int lo = l, hi = r;
			if(!ps.empty()){
				if(ps[0].first < l){
					lo = ps[0].first;
					ps[0].first = l;
				}
				if(ps.back().second > r){
					hi = ps.back().second;
					ps.back().second = r;
				}

				trav(pa, ps)
					segt.mulran(2, pa.first, pa.second);

				segt.addran(1, l, ps[0].first);
				rep(i,1,sz(ps))
					segt.addran(1, ps[i-1].second, ps[i].first);
				segt.addran(1, ps.back().second, r);
			} else {
				segt.addran(1, l, r);
			}

			ls[x].insert(pii(lo, hi));
		} else {
			int l, r;
			cin >> l >> r;

			ll ans = segt.query(l, r+1);
			ans %= md;
			if(ans < 0) ans += md;

			cout << ans << endl;
		}
	}
}