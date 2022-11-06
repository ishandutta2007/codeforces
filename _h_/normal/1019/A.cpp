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
	
	int n, m;
	cin >> n >> m;

	vector<vi> ls(m);

	rep(_,0,n){
		int p, c;
		cin >> p >> c;
		ls[p-1].push_back(c);
	}
	trav(v, ls){
		sort(all(v));
		reverse(all(v));
	}
	vi os;
	ll ans = 1e15;
	int s = sz(ls[0]);
	rep(t,max(1, s),n+1){
		ll cur = 0;
		int st = s;

		vi rest;
		rep(i,1,m){
			int l = min(sz(ls[i]), t-1);
			rep(j,l,sz(ls[i])){
				cur += ls[i][j];
				++st;
			}
			rep(j,0,l) rest.push_back(ls[i][j]);
		}
		sort(all(rest));
		int ix = 0;
		while(st < t){
			cur += rest[ix++];
			++st;
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}