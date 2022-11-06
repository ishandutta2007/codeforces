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

	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;

	vi s(cl);
	trav(x, s) cin >> x;
	vi e(ce);
	trav(x, e) cin >> x;

	int q;
	cin >> q;

	rep(_, 0, q){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if(x1 == x2){
			cout << abs(y1 - y2) << endl;
			continue;
		}

		int ans = 2e9;

		int lo = -1, hi = cl;
		while(lo+1 < hi){
			int mi = (lo+hi) / 2;
			if(s[mi] >= y1) hi = mi;
			else lo = mi;
		}

		if(hi < cl)
			ans = min(ans, abs(y1 - s[hi]) + abs(s[hi] - y2) + abs(x1 - x2));
		if(lo >= 0)
			ans = min(ans, abs(y1 - s[lo]) + abs(s[lo] - y2) + abs(x1 - x2));

		lo = -1, hi = ce;
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			if(e[mi] >= y1) hi = mi;
			else lo = mi;
		}
	
		int t = (abs(x1-x2) - 1)/v + 1;	
		if(hi < ce)
			ans = min(ans, abs(y1 - e[hi]) + abs(e[hi] - y2) + t);
		if(lo >= 0)
			ans = min(ans, abs(y1 - e[lo]) + abs(e[lo] - y2) + t);
		
		cout << ans << endl;
	
	}
}