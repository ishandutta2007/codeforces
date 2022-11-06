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

	int t;
	cin >> t;

	rep(_,0,t){
		int n;
		string s;
		cin >> n >> s;
		int ans;
		if(count(all(s), '<') == 0
		|| count(all(s), '>') == 0) ans = n;
		else {
			s.push_back(s[0]);
			ans = 0;
			rep(i,0,n)
				ans += (s[i]=='-') || (s[i+1]=='-');
		}
		cout << ans << endl;
	}
}