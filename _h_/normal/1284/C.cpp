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

	int n, m;
	cin >> n >> m;

	vector<ll> fs(n+1, 1);
	rep(i,1,n+1) fs[i] = fs[i-1] * i % m;

	ll ans = 0;
	rep(d,1,n+1){
		ll x = n+1 - d;
		x = x * x % m;
		x = x * fs[d] % m;
		x = x * fs[n-d] % m;
		ans = (ans + x) % m;
	}
	cout << ans << endl;
}