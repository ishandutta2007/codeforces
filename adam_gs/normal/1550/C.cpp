#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7, INF=1e9+7;
int tr[4*LIM], T[LIM], N;
int lw[LIM], lm[LIM], pw[LIM], pm[LIM];
void upd(int l, int r, int x) {
	l+=N; r+=N;
	tr[l]=min(tr[l], x);
	tr[r]=min(tr[r], x);
	while(l/2!=r/2) {
		if(l%2==0) tr[l+1]=min(tr[l+1], x);
		if(r%2==1) tr[r-1]=min(tr[r-1], x);
		l/=2; r/=2;
	}
}
ll cnt(int v) {
	v+=N;
	int ans=tr[v];
	while(v) {
		ans=min(ans, tr[v]);
		v/=2;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	N=1;
	while(N<n) N*=2;
	rep(i, 2*N) tr[i]=n-1;
	rep(i, n) cin >> T[i];
	stack<pair<int,int>>q1, q2;
	q1.push({INF, n});
	q2.push({-INF, n});
	for(int i=n-1; i>=0; --i) {
		while(q1.top().st<T[i]) q1.pop();
		pw[i]=q1.top().nd;
		q1.push({T[i], i});
		while(q2.top().st>T[i]) q2.pop();
		pm[i]=q2.top().nd;
		q2.push({T[i], i});
	}
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	q1.push({INF, -1});
	q2.push({-INF, -1});
	rep(i, n) {
		while(q1.top().st<T[i]) q1.pop();
		lw[i]=q1.top().nd;
		q1.push({T[i], i});
		while(q2.top().st>T[i]) q2.pop();
		lm[i]=q2.top().nd;
		q2.push({T[i], i});
	}
	rep(i, n) {
		if(lw[i]>-1) {
			upd(0, lw[i], pm[i]-1);
		}
		if(lm[i]>-1) {
			upd(0, lm[i], pw[i]-1);
		}
	}
	ll ans=0;
	rep(i, n) {
		ans+=cnt(i)-i+1;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}