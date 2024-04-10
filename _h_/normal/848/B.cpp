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

const int mx = 100000;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, w, h;
	cin >> n >> w >> h;
	vi gs(n), ps(n), ts(n);
	rep(i,0,n) cin >> gs[i] >> ps[i] >> ts[i];
	vector<vi> ls(2*mx);
	rep(i,0,n) ls[ps[i]-ts[i]+mx].push_back(i);
	vi who(n);
	vector<pii> ans(n);

	trav(v, ls){
		vi a, b;
		trav(x, v){
			if(gs[x]==1)
				a.push_back(x);
			else
				b.push_back(x);
		}
		sort(all(a), [&](int x, int y){
			return ps[x]<ps[y];
		});
		sort(all(b), [&](int x, int y){
			return ps[x]<ps[y];
		});
		deque<int> ids;
		trav(x, a) ids.push_back(x);
		trav(y, b){
			ids.push_front(y);
			int x = ids.back(); ids.pop_back();
			who[y] = x;
		}
		rep(i,0,sz(a))
			who[a[i]] = ids[i];
	}


	rep(i,0,n){
		pii pa = gs[i]==1 ? pii(ps[i],h) : pii(w, ps[i]);
		ans[who[i]] = pa;
	}
	trav(pa, ans) cout << pa.first << ' ' << pa.second << endl;
}