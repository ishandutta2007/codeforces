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

const int mx = 1e6;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int good = 0;
	vi ls(mx), rs(mx);

	rep(_,0,n){
		string s;
		cin >> s;

		int cur = 0, mn = 0;
		trav(c, s){
			cur += c=='(' ? 1 : -1;
			mn = min(mn, cur);
		}
		if(mn == 0 && cur == 0) ++good;
		else if(mn == 0) ++ls[cur];
		else if(mn == cur) ++rs[-cur];
	}

	int ans = 0;
	ans += good/2;
	rep(i,1,mx) ans += min(ls[i], rs[i]);

	cout << ans << endl;
}