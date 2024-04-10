#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int n;
	cin >> n;

	vector<vector<ll>> ls(60);

	rep(_,0,n){
		ll b;
		cin >> b;

		int i = 0;
		while(b >= (1LL<<(i+1))) ++i;
		ls[i].push_back(b);
	}
	vector<ll> ans;

	ll cur = 0;

	rep(_,0,n){
		rep(i,0,60) if( (cur & (1LL<<i)) == 0 && !ls[i].empty()){
			ll b = ls[i].back();
			ls[i].pop_back();
			ans.push_back(b);
			cur ^= b;
			goto good;
		}
		cout << "No" << endl;
		return 0;
		
		good: ;
	}
	cout << "Yes" << endl;
	trav(x, ans) cout << x << ' ';
	cout << endl;

}