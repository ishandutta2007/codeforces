#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(ll i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll digsum(ll x){
	if(x == 0) return 0;
	return x%10 + digsum(x/10);
}

const int mx = 9*18;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,s, ans = 0;
	cin >> n >> s;

	ll lo = min(n+1, s);
	ll hi = min(n+1, s+mx);
	rep(i, lo, hi) if(i-digsum(i) >= s) ++ans;
	ans += n+1-hi;
	cout << ans << endl;
}