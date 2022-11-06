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

void claim(int d){
	cout << "! " << d << endl;
}

void reset(){
	cout << "R" << endl;
}

bool seen(int c){
	cout << "? " << c << endl;
	char r;
	cin >> r;
	return r=='Y';
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;
	if(k == 1 && n > 1) k = 2;

	function<vi(int,int)> getreps = [&](int fr, int to){
		if(to-fr == k){
			vi ans;
			reset();
			rep(i,fr,to) if(!seen(i)) ans.push_back(i);
			return ans;
		}
		int mi = (fr+to)/2;
		vi a = getreps(fr, mi), b = getreps(mi, to);
		vector<vi> as, bs;
		trav(x, a){
			if(as.empty() || sz(as.back()) == k/2)
				as.push_back(vi());
			as.back().push_back(x);
		}
		trav(x, b){
			if(bs.empty() || sz(bs.back()) == k/2)
				bs.push_back(vi());
			bs.back().push_back(x);
		}
		vector<vi> vis(sz(as), vi(sz(bs)));
		set<int> dupl;
		auto psh = [&](vi &cs){
			trav(x, cs){
				if(seen(x)) dupl.insert(x);
			}
			rep(_,0,k/2 - sz(cs)) seen(cs.back());
		};
		function<void(int)> go = [&](int l){
			psh(as[l]);
			rep(r,0,sz(bs)) if(!vis[l][r]){
				vis[l][r] = true;
				psh(bs[r]);
				rep(l1,0,sz(as)) if(!vis[l1][r]){
					vis[l1][r] = true;
					go(l1);
				}
				return;
			}
		};
		rep(l,0,sz(as)) rep(r,0,sz(bs)) if(!vis[l][r]){
			reset();
			vis[l][r] = true;
			psh(bs[r]);
			go(l);
		}
		vi ans;
		trav(x, a) if(!dupl.count(x)) ans.push_back(x);
		trav(x, b) if(!dupl.count(x)) ans.push_back(x);
		return ans;
	};

	vi ls = getreps(1, n+1);
	claim(sz(ls));
}