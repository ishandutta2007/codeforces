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

void fail(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vi ls(m);
	trav(x, ls) cin >> x;

	ll sum = 0;
	trav(x, ls) sum += x;
	if(sum < n) fail();

	vi ps(m);

	rep(i,0,m){
		sum -= ls[i];
		if(sum+ls[i] <= n-i){
			ps[i] = sum+1;
		} else {
			ps[i] = n-i - ls[i] + 1;
			if(ps[i] <= 0) fail();
		}
	}
	trav(x, ps) cout << x << " ";
	cout << endl;
}