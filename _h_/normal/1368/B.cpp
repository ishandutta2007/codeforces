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

	ll n;
	cin >> n;

	vi cs(10, 1);
	ll p = 1;
	int ix = 0;
	while(p < n){
		p /= cs[ix];
		cs[ix]++;
		p *= cs[ix];
		ix = (ix + 1) % 10;
	}
	string cf = "codeforces";
	rep(i,0,10){
		rep(_,0,cs[i]) cout << cf[i];
	}
	cout << endl;
}