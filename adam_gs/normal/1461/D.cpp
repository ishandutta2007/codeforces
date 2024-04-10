#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e9+7;
map<ll,int>mp;
void dc(vector<ll>&V) {
	if(!V.size()) return;
	ll sum=0, ma=0, mi=INF;
	for(auto i : V) {
		sum+=i;
		ma=max(ma, i);
		mi=min(mi, i);
	}
	mp[sum]=1;
	if(ma==mi) return;
	ll mid=(ma+mi)/2;
	vector<ll>A, B;
	for(auto i : V) if(i<=mid) A.pb(i); else B.pb(i);
	dc(A);
	dc(B);
}
void solve() {
	mp.clear();
	int n, q;
	cin >> n >> q;
	vector<ll>V;
	while(n--) {
		ll a;
		cin >> a;
		V.pb(a);
	}
	dc(V);
	while(q--) {
		ll x;
		cin >> x;
		cout << (mp[x]?"Yes":"No") << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}