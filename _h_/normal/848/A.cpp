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

const int mx = 2000;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	if(k == 0){
		cout << "a" << endl;
		return 0;
	}
	vi cost(mx);
	rep(i,2,mx){
		cost[i] = cost[i-1] + i-1;
	}
	auto calc = [&](int k, vi &res){
		while(k){
			int i = upper_bound(all(cost), k)-cost.begin()-1;
			res.push_back(i);
			k -= cost[i];
		}
	};
	vi ans;
	calc(k, ans);
	string s;
	rep(i,0,sz(ans)){
		char c = 'a'+i;
		rep(_,0,ans[i]) s.push_back(c);
	}
	cout << s << endl;
}