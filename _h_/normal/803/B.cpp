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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	set<int> s;
	s.insert(-n-10);
	s.insert(n+n+10);
	rep(i,0,n){
		int x;
		cin >> x;
		if(x == 0) s.insert(i);
	}
	rep(i,0,n){
		int ans = n+n;
		auto it = s.lower_bound(i);
		ans = min(ans, *it-i);
		--it;
		ans = min(ans, i-*it);
		cout << ans << ' ';
	}
	cout << endl;
}