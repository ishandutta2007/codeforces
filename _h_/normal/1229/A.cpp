// written by aitch
// on 2019 09/23 at 17:44:31
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

	map<ll, vector<ll>> ls;

	vector<pair<ll,int>> ps(n);
	rep(i,0,n) cin >> ps[i].first;
	rep(i,0,n) cin >> ps[i].second;

	sort(all(ps));
	
	vector<bool> alive(n, false);

	rep(i,1,n) if(ps[i].first == ps[i-1].first)
		rep(j,0,i+1)
			if( (ps[j].first & ~ps[i].first) == 0)
				alive[j] = true;
	ll ans = 0;
	rep(i,0,n) if(alive[i]) ans += ps[i].second;
	cout << ans << endl;
}