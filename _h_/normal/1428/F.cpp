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

struct FT {
	vi t;
	FT(int n){
		t.resize(n+1);
	}
	void upd(int pos, int dif){
		for(++pos; pos < sz(t); pos += pos & -pos)
			t[pos] += dif;
	}
	int que(int pos){
		int ans = 0;
		for(; pos; pos -= pos & -pos)
			ans += t[pos];
		return ans;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	string s;
	cin >> n >> s;

	int prevzero = n;

	ll cursum = 0, ans = 0;

	FT ft(n);

	rrep(i,0,n){
		if(s[i] == '0'){
			prevzero = i;
		} else {
			int len = prevzero - i;			

			int lo = prevzero, hi = n+1;
			while(lo+1 < hi){
				int mi = (lo + hi) / 2;
				if(ft.que(mi) >= len) hi = mi;
				else lo = mi;
			}
			cursum += hi-i-1;
			ft.upd(i, 1);
			ft.upd(hi-1, -1);
		}
		ans += cursum;
	}
	cout << ans << endl;
}