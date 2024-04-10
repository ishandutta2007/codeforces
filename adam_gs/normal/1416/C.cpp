#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
ll ilegdy[30][2];
void licz(vector<int>&V, int l) {
	if(l<0) return;
	vector<int>ciag, jeden, zero;
	rep(i, V.size()) if(V[i]&(1<<l)) {
		ciag.pb(1); 
		jeden.pb(V[i]);
	} else {
		ciag.pb(0);
		zero.pb(V[i]);
	}
	ll a=0;
	for(auto i : ciag) if(i) ++a; else ilegdy[l][0]+=a;
	a=0;
	for(auto i : ciag) if(!i) ++a; else ilegdy[l][1]+=a;
	if(jeden.size()) licz(jeden, l-1);
	if(zero.size()) licz(zero, l-1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>V;
	rep(i, n) {
		int a;
		cin >> a;
		V.pb(a);
	}
	licz(V, 29);
	ll ans=0, x=0;
	rep(i, 30) {
		ans+=min(ilegdy[i][0], ilegdy[i][1]);
		if(ilegdy[i][0]>ilegdy[i][1]) {
			x^=(1<<i);
		}
	}
	cout << ans << " " << x << '\n';
}