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
	int n, m;
	cin >> n >> m;
	vector<vi> as(n, vi(n));
	trav(v, as) trav(x, v) cin >> x;

	vi wf = {0, 1, 2}, shift(3, 0);

	string s;
	cin >> s;
	trav(c, s){
		if(c == 'R'){
			++shift[1];
		}
		if(c == 'L'){
			--shift[1];
		}
		if(c == 'U'){
			--shift[0];	
		}
		if(c == 'D'){
			++shift[0];
		}
		if(c == 'I'){
			swap(shift[1], shift[2]);
			swap(wf[1], wf[2]);
		}
		if(c == 'C'){
			swap(shift[0], shift[2]);
			swap(wf[0], wf[2]);
		}
	}
	vector<vi> ans(n, vi(n));

	rep(i,0,n) rep(j,0,n){
		vi ijk = {i+1, j+1, as[i][j]};
		vi res(3);
		rep(t,0,3){
			res[t] = (ijk[wf[t]] + shift[t])%n;
			if(res[t] <= 0) res[t] += n;
		}
		ans[res[0]-1][res[1]-1] = res[2];
	}
	rep(i,0,n) rep(j,0,n) cout << ans[i][j] << (j+1==n ? '\n' : ' ');
	cout << endl;
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