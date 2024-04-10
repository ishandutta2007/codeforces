#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[26];
ll tr[4*LIM], li[26], N=1;
void upd(int v) {
	v+=N;
	while(v) {
		--tr[v];
		v/=2;
	}
}
ll cnt(int l, int r) {
	l+=N; r+=N;
	ll ans=tr[l];
	if(l!=r) ans+=tr[r];
	while(l/2!=r/2) {
		if(l%2==0) ans+=tr[l+1];
		if(r%2==1) ans+=tr[r-1];
		l/=2; r/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s, t;
	cin >> n >> s; t=s;
	reverse(all(t));
	while(N<n) N*=2;
	rep(i, n) {
		tr[N+i]=1;
		V[s[i]-'a'].pb(i);
	}
	for(int i=N-1; i; --i) tr[i]=tr[2*i]+tr[2*i+1];
	ll ans=0;
	for(auto i : t) {
		upd(V[i-'a'][li[i-'a']]);
		ans+=cnt(0, V[i-'a'][li[i-'a']]);
		++li[i-'a'];
	}
	cout << ans << '\n';
}