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
	
	int n;
	cin >> n;
	vi v(n), l(n), r(n);
	rep(i,0,n) cin >> v[i] >> l[i] >> r[i];
	trav(x,l) --x;
	trav(x,r) --x;
	vi hi(n, 1e9+1), lo(n, -1);
	vector<bool> isroot(n,1);
	rep(i,0,n){
		if(l[i] != -2) isroot[l[i]] = 0;
		if(r[i] != -2) isroot[r[i]] = 0;
	}
	int root;
	stack<int> st;
	rep(i,0,n) if(isroot[i]) root = i;
	st.push(root);
	while(!st.empty()){
		int i = st.top();
		st.pop();
		if(l[i] != -2){
			lo[l[i]] = lo[i];
			hi[l[i]] = min(hi[i], v[i]);
			st.push(l[i]);
		}
		if(r[i] != -2){
			lo[r[i]] = max(lo[i], v[i]);
			hi[r[i]] = hi[i];
			st.push(r[i]);
		}
	}
	int ans = 0;
	set<int> found;
	rep(i,0,n) if(lo[i] < v[i] && v[i] < hi[i]) found.insert(v[i]);
	rep(i,0,n) ans += !found.count(v[i]);
	cout << ans << endl;
}