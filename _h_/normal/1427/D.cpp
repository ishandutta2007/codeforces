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

	vi c(n);
	trav(x, c) cin >> x;

	vector<vi> ans;

	if(c[0] == 1){
		ans.resize(n - n % 2); // even length
	} else {
		ans.resize(n - (n+1)%2); // odd length
		reverse(all(c));
	}
	rep(i,0,sz(ans)){
		int j = i;
		while(c[j] != i+1) ++j;
		reverse(c.begin()+i, c.begin()+j+1);
		rep(_,0,i) ans[i].push_back(1);
		ans[i].push_back(j+1-i);
		rep(_,j+1,n) ans[i].push_back(1);
		if((i+sz(ans))%2) reverse(all(ans[i]));
	}
	cout << sz(ans) << endl;
	trav(v, ans){
		cout << sz(v) << " ";
		trav(x, v) cout << x << " ";
		cout << endl;
	}
}