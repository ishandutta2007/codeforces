// written by _h_
// on 2020 01/04 at 13:05:01
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
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m = n;

	vi mx, mn;

	ll ans = 0;

	rep(_,0,n){
		int l;
		cin >> l;
		vi s(l);
		trav(x, s) cin >> x;
		rep(i,1,l) if(s[i] > s[i-1]){
			ans += m + m - 1;
			--m;
			goto done;
		}
		mx.push_back(s[0]);
		mn.push_back(s.back());
		done: ;
	}
	sort(all(mx));
	sort(all(mn));

	for(int i = 0, j = 0; i < m; ++i){
		while(j < m && mn[j] < mx[i]) ++j;
		ans += j;
	}

	cout << ans << endl;
}