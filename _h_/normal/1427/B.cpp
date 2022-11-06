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

ll solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(k >= count(all(s), 'L')){
		return 2 * n-1;
	}
	if(count(all(s), 'W') == 0) return max(0, 2 * k - 1);

	int ans = 2*k + count(all(s), 'W');
	rep(i,1,n) ans += s[i] == 'W' && s[i-1] == 'W';

	vi ls;

	int cur = n+10;
	rep(i,0,n){
		if(s[i] == 'W'){
			if(cur){
				ls.push_back(cur);
				cur = 0;
			}
		} else {
			++cur;
		}
	}
	sort(all(ls));
	int i = 0;
	while(i < sz(ls) && k >= ls[i]){
		k -= ls[i];
		++i;
	}
	return ans + i;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	rep(_,0,n) cout << solve() << endl;
}