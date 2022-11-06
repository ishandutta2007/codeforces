#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int r, c, k;
	cin >> r >> c >> k;

	vector<string> ss(r);
	trav(s, ss) cin >> s;
	int tot = 0;
	trav(s, ss) tot += count(all(s), 'R');
	vi vs(k,tot/k);
	rep(i,0,tot%k) ++vs[i];
	vector<string> ans(r, string(c,'?'));
	int i = 0, cur = 0;
	rep(x,0,r){
		rep(y0,0,c){
			int y = x%2 ? y0 : c-1-y0;
			cur += ss[x][y] == 'R';
			if(cur > vs[i]){
				cur = 1;
				i++;
			}
			ans[x][y] = (i<26 ? 'a'+i : i < 52 ? 'A'+i-26 : '0'+i-52);
		}
	}
	trav(s, ans) cout << s << endl;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}