// written by aitch
// on 2019 10/16 at 15:35:00
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

	int n;
	cin >> n;

	vector<vi> vs(n, vi(3));
	trav(v, vs) trav(x, v) cin >> x;

	vi ps(n);
	iota(all(ps), 0);
	sort(all(ps), [&](int i, int j){return vs[i] < vs[j];});

	vector<pii> ans;

	rrep(t,0,3){
		vi nx;
		for(int ix = 0; ix < sz(ps);){
			if(ix+1 == sz(ps)){
				nx.push_back(ps[ix]);
				break;
			}
			bool good = true;
			int a = ps[ix], b = ps[ix+1];
			vi u = vs[a], v = vs[b];
			rep(i,0,t) if(u[i] != v[i]) good = false;
			if(good){
				ans.emplace_back(a,b);		
				ix += 2;
			} else {
				nx.push_back(ps[ix]);
				++ix;
			}
		}
		ps = nx;
	}
	trav(pa, ans) cout << pa.first+1 << ' ' << pa.second+1 << endl;
}