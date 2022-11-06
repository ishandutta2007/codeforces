// written by aitch
// on 2019 10/26 at 17:47:34
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

ll solve(ll n, ll p){
	for(ll k = 1; k*(p+1) <= n; ++k){
		if(__builtin_popcountll(n - k*p) <= k)
			return k;
	}
	return -1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n, p;
	cin >> n >> p;
	cout << solve(n,p) << endl;

}