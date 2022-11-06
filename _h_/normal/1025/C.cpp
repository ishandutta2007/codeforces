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
	
	string s;
	cin >> s;

	int n = sz(s);
	s += s;

	int ans = 0;
	for(int i = 1, cur = 1; i < 2*n; ++i){
		if(s[i] != s[i-1]) ++cur;
		else {
			cur = 1;
		}
		ans = max(ans, cur);
	}
	ans = min(ans, n);
	cout << ans << endl;
}