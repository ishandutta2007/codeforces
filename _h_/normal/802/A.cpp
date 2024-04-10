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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vi as(n);
	trav(x, as) cin >> x, --x;
	vector<vi> ls(n, vi(1,n+10));
	rrep(i,0,n) ls[as[i]].push_back(i);
	int ans = 0;
	set<pii> ut;
	vector<bool> in(n);
	trav(x, as){
		if(in[x]){
			pii pa = {-ls[x].back(), x};
			ls[x].pop_back();
			ut.erase(pa);
			ut.insert({-ls[x].back(),x});
			continue;
		}
		++ans;
		if(sz(ut) == k){
			auto it = ut.begin();
			int y = it->second;
			ut.erase(it);
			in[y] = 0;
		}
		in[x] = 1;
		ls[x].pop_back();
		ut.insert({-ls[x].back(), x});
	}
	cout << ans << endl;
}