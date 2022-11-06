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

struct FT {
	vi t;
	FT(int n){
		t.resize(n+1);
	}

	void upd(int pos, int dif){
		for(++pos; pos < sz(t); pos += pos&-pos)
			t[pos] += dif;
	}

	int que(int r){
		int ans = 0;
		for(; r; r -= r&-r)
			ans += t[r];
		return ans;
	}
};

int tonum(char c){
	if(c == 'A') return 0;
	if(c == 'T') return 1;
	if(c == 'G') return 2;
	return 3;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int n;
	cin >> s >> n;
	vector<vector<vector<FT>>> f(4, vector<vector<FT>>(10));
	rep(t,0,4) rep(i,1,11){
		f[t][i-1].resize(i, FT(sz(s)/i+1));
	}
	rep(i,0,sz(s)){
		rep(j,1,11)
			f[tonum(s[i])][j-1][i%j].upd(i/j, 1);
	}
	rep(_,0,n){
		int t;
		cin >> t;
		if(t == 1){
			int i;
			char c;
			cin >> i >> c;
			--i;
			rep(j,1,11)
				f[tonum(s[i])][j-1][i%j].upd(i/j, -1);
			s[i] = c;
			rep(j,1,11)
				f[tonum(s[i])][j-1][i%j].upd(i/j,  1);
		} else {
			int l,r;
			string e;
			cin >> l >> r >> e;
			--l;
			int ans = 0, j = sz(e);
			rep(k,0,min(j, r-l)){
				int fst = (k+l)/j, len = (r-l)/j + (k < (r-l)%j);
				ans += f[tonum(e[k])][j-1][(k+l)%j].que(fst+len)
				     - f[tonum(e[k])][j-1][(k+l)%j].que(fst);
			}
			cout << ans << endl;
		}
	}
}