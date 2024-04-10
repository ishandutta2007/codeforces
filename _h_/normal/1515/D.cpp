#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int n, l, r;
	cin >> n >> l >> r;

	vi ls(n), rs(n);
	rep(_,0,l){
		int c;
		cin >> c;
		++ls[c-1];
	}
	rep(_,0,r){
		int c;
		cin >> c;
		++rs[c-1];
	}
	int ans = 0;
	rep(c,0,n) while(ls[c] && rs[c]){
		--l;
		--r;
		--ls[c];
		--rs[c];
	}
	rep(c,0,n){
		while(ls[c] >= 2 && l > r){
			ls[c] -= 2;
			l -= 2;
			ans++;
		}
		while(rs[c] >= 2 && r > l){
			rs[c] -= 2;
			r -= 2;
			ans++;
		}
	}
	ans += max(l, r);
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}