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
	
	int n, m, q;
	cin >> n >> m >> q;
	if(m > n){
		rep(_,0,q) cout << 0 << endl;
		return 0;
	}

	string s, t;
	cin >> s >> t;

	vi pre(n-m+2);

	rep(i,0,n-m+1){
		int same = s.substr(i, m) == t ? 1 : 0;
		pre[i+1] = pre[i] + same;
	}
	rep(_,0,q){
		int l, r;
		cin >> l >> r;
		--l, --r;
		r = max(l, r-m+2);
		cout << pre[r]-pre[l] << endl;
	}
}