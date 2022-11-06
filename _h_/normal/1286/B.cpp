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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi p(n), c(n);
	rep(i,0,n) cin >> p[i] >> c[i];
	trav(x, p) --x;
	int root = 0;
	rep(i,0,n) if(p[i] == -1) root = i;

	vector<vi> ch(n);
	rep(i,0,n) if(i != root) ch[p[i]].push_back(i);

	function<vi(int)> dfs = [&](int v){
		vi ans;
		if(c[v] == 0) ans.push_back(v);
		trav(u, ch[v]){
			auto ls = dfs(u);
			trav(x, ls){
				ans.push_back(x);
				if(sz(ans) == c[v]) ans.push_back(v);
			}
		}
		if(c[v] > sz(ans)){
			cout << "NO" << endl;
			exit(0);
		}
		return ans;
	};
	auto ls = dfs(root);

	vi ans(n);
	rep(i,0,n) ans[ls[i]] = i+1;
	cout << "YES" << endl;
	trav(x, ans) cout << x << " ";
	cout << endl;
}