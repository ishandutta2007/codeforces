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

void fail(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	if(k >= 1e7) fail();
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	ll hi = n/(k*(k+1)/2);
	ll rek = -1;
	for(ll d = 1; d*d <= n; ++d) if(n%d == 0){
		if(d <= hi) rek = max(rek, d);
		if(n/d <= hi) rek = max(rek, n/d);
	}
	if(rek == -1) fail();
	for(ll cur = rek, i = 1; i < k; ++i, cur += rek){
		cout << cur << ' ';
		n -= cur;
	}
	cout << n << endl;
}