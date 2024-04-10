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
	
	ll n, k;
	cin >> n >> k;

	ll hi = k-1, lo = k-n;
	lo = max(lo, 1LL);
	hi = min(hi, n);

	ll ans = hi-lo+1;
	ans = max(ans, 0LL);
	ans /= 2;

	cout << ans << endl;
}