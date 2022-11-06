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

	int n;
	cin >> n;

	vector<pii> ac(n);
	trav(pa, ac) cin >> pa.first >> pa.second;
	sort(all(ac));

	ll ans = 0;
	trav(p, ac) ans += p.second;

	int dist = ac[0].first;
	rep(ix,0,n){
		ans += max(0, ac[ix].first - dist);
		dist = max(dist, ac[ix].first + ac[ix].second);
	}

	cout << ans << endl;
}