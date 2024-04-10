#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (b);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

bool solve(){
	int n;
	cin >> n;
	vi ix(n);
	rep(i,0,n){
		int val;
		cin >> val;
		ix[val-1] = i;
	}
	vector<bool> vis(n+1, false);
	vis[n] = true;
	int nx = n;
	trav(i, ix){
		if(!vis[nx] && i != nx) return false;
		vis[i] = true;
		nx = i+1;
	}
	return true;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) cout << (solve() ? "Yes" : "No") << endl;
}