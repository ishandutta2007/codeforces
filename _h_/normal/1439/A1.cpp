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

void flip(char &x){
	x = '0' + '1' - x;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> ls(n);
	trav(s, ls) cin >> s;
	vector<vi> ans;
	rrep(i,2,n){
		rrep(j,0,m){
			if(ls[i][j]=='1'){
				vi cur = {i, j, i-1, j, i-1, abs(j-1)};
				rep(t,0,3) flip(ls[cur[2*t]][cur[2*t+1]]);
				ans.emplace_back(cur);
			}
		}
	}
	rrep(j,2,m){
		rep(i,0,2){
			if(ls[i][j]=='1'){
				vi cur = {i, j, 0, j-1, 1, j-1};
				rep(t,0,3) flip(ls[cur[2*t]][cur[2*t+1]]);
				ans.emplace_back(cur);
			}
		}
	}
	rep(i,0,2) rep(j,0,2){
		vi cur = {1 ^ i, 0 ^ j,
		          0 ^ i, 1 ^ j,
			  1 ^ i, 1 ^ j};
		int sum = 0;
		rep(t,0,3) sum += (ls[cur[2*t]][cur[2*t+1]] == '1');
		if(sum % 2) ans.emplace_back(cur);
	}
	cout << sz(ans) << endl;
	trav(l, ans){
		trav(x, l) cout << x+1 << " ";
		cout << endl;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	rep(_,0,n) solve();
}