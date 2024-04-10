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
	
	int n;
	cin >> n;
	vi as(n);
	trav(x, as) cin >> x;
	vector<ll> pre(n+1);
	rep(i,0,n) pre[i+1] = pre[i] + as[i];

	vector<pair<ll,vi>> ps(4);

	rep(i,0,n+1){
		rep(j,0,3){
			ll c = ps[j].first + pre[i]*(j%2 ? -1 : 1);
			vi v = ps[j].second;
			v.push_back(i);
			ps[j+1] = max(ps[j+1], make_pair(c, v));
		}
	}
	trav(x, ps[3].second) cout << x << ' ';
	cout << endl;
}