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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;

	ll x, y;
	cin >> x >> y;
	if(x > y){
		swap(x, y);
		reverse(all(s));
	}

	vector<ll> cost(2);
	ll cur = 0;
	trav(c, s){
		if(c == '1'){
			cur += cost[1];
			cost[0] += y;
		} else {
			cur += cost[0];
			cost[1] += x;
		}
	}
	ll ans = cur;
	rrep(i,0,sz(s)){
		if(s[i] == '0') cost[1] += y - x;
		if(s[i] == '1') cost[0] += x - y;
		if(s[i] == '?'){
			cost[1] -= x;
			cur -= cost[0];
			cur += cost[1];
			cost[0] += x;
		}
		ans = min(ans, cur);
	}	
	cout << ans << endl;
}