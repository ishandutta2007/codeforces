#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, INF=1e9+7;
ll lewo[LIM], tr[4*LIM], N;
ll cnt(int l, int r) {
	l+=N; r+=N;
	ll ans=min(tr[l], tr[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=min(ans, tr[l+1]);
		if(r%2==1) ans=min(ans, tr[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
bool check(vector<ll>V) {
	int n=V.size();
	N=1;
	while(N<=n) N*=2;
	vector<pair<int,int>>S;
	S.pb({INF, -1});
	tr[N]=0;
	rep(i, n) {
		tr[N+i+1]=tr[N+i]+V[i];
		while(S.back().st<=V[i]) S.pop_back();
		lewo[i]=S.back().nd+1;
		S.pb({V[i], i});
	}
	for(int i=N-1; i; --i) tr[i]=min(tr[2*i], tr[2*i+1]);
	rep(i, n-1) if(V[i+1]>0) {
		ll a=tr[N+i+1]-cnt(lewo[i+1], i+1);
		if(a>0) return false;
	}
	return true;
}
void solve() {
	int n;
	cin >> n;
	vector<ll>V;
	while(n--) {
		ll a;
		cin >> a;
		V.pb(a);
	}
	if(!check(V)) {
		cout << "NO\n";
		return;
	}
	reverse(all(V));
	cout << (check(V)?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}