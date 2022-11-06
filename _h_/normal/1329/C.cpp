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

void solve(){
	int h, g;
	cin >> h >> g;
	vi as(1<<h);
	rep(i,1,1<<h) cin >> as[i];

	function<void(int)> fop = [&](int i){
		int j = 2*i >= (1<<h) ? 0 :
			as[2*i] > as[2*i+1] ? 2*i : 2*i+1;
		as[i] = as[j];
		if(as[j] != 0) fop(j);
	};
	function<int(int)> pof = [&](int i){
		int j = 2*i >= (1<<h) ? 0 :
			as[2*i] > as[2*i+1] ? 2*i : 2*i+1;
		if(as[j] != 0) return pof(j);
		else return i;
	};

	vi ans;
	rep(i,1,1<<g) while(pof(i) >= (1<<g)){
		ans.push_back(i);
		fop(i);
	}
	ll sum = 0;
	rep(i,1,1<<g) sum += as[i];
	cout << sum << endl;
	trav(x, ans) cout << x << " ";
	cout << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}