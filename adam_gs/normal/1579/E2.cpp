#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int tr[4*LIM], N;
void upd(int v) {
	v+=N;
	while(v) {
		++tr[v];
		v/=2;
	}
}
int cnt(int l, int r) {
	if(l>r) return 0;
	l+=N; r+=N;
	int ans=tr[l];
	if(l!=r) ans+=tr[r];
	while(l/2!=r/2) {
		if(l%2==0) ans+=tr[l+1];
		if(r%2==1) ans+=tr[r-1];
		l/=2; r/=2;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	int T[n];
	vector<int>skal;
	rep(i, n) {
		cin >> T[i];
		skal.pb(T[i]);
	}
	sort(all(skal));
	map<int,int>mp;
	int akt=0;
	for(auto i : skal) if(!mp[i]) {
		++akt;
		mp[i]=akt;
	}
	N=1;
	while(N<=akt) N*=2;
	rep(i, 2*N) tr[i]=0;
	int ans=0;
	rep(i, n) {
		ans+=min(cnt(1, mp[T[i]]-1), cnt(mp[T[i]]+1, N-1));
		upd(mp[T[i]]);
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}