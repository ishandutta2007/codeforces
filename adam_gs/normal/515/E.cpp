#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=1e5+7;
ll ma[4*LIM], mi[4*LIM], ans[4*LIM], pref[LIM], suf[LIM], H[LIM], N=1;
ll cnt(int l, int r) {
	l+=N; r+=N;
	vector<int>A, B;
	A.pb(l);
	B.pb(r);
	while(l/2!=r/2) {
		if(l%2==0) A.pb(l+1);
		if(r%2==1) B.pb(r-1);
		l/=2; r/=2;
	}
	reverse(all(B));
	for(auto i : B) A.pb(i);
	ll res=-INF, aktmi=INF;
	for(auto i : A) {
		res=max(res, ans[i]);
		if(aktmi<INF) res=max(res, ma[i]-aktmi);
		aktmi=min(aktmi, mi[i]);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(N<n) N*=2;
	rep(i, n) {
		cin >> pref[i+1];
		pref[i+1]+=pref[i];
	}
	for(int i=n-1; i>=0; --i) {
		suf[i]=pref[n]-pref[i];
	}
	rep(i, 2*N) {
		ans[i]=ma[i]=-INF;
		mi[i]=INF;
	}
	rep(i, n) {
		cin >> H[i];
		ma[N+i]=pref[i]+2*H[i];
		mi[N+i]=pref[i]-2*H[i];
		ans[N+i]=-INF;
	}
	for(int i=N-1; i; --i) {
		ma[i]=max(ma[2*i], ma[2*i+1]);
		mi[i]=min(mi[2*i], mi[2*i+1]);
		ans[i]=max(ans[2*i], ans[2*i+1]);
		ans[i]=max(ans[i], ma[2*i+1]-mi[2*i]);
	}
	rep(i, n) {
		pref[i]+=2*H[i];
		suf[i]+=2*H[i];
	}
	rep(i, n-1) pref[i+1]=max(pref[i+1], pref[i]);
	for(int i=n-2; i>=0; --i) suf[i]=max(suf[i], suf[i+1]);
	while(m--) {
		int l, r;
		cin >> l >> r; --l; --r;
		if(l>r) cout << cnt(r+1, l-1) << '\n';
		else {
			ll ans=-INF;
			if(r<n-2) ans=max(ans, cnt(r+1, n-1));
			if(l>1) ans=max(ans, cnt(0, l-1));
			if(l>0 && r<n-1) ans=max(ans, pref[l-1]+suf[r+1]);
			cout << ans << '\n';
		}
	}
}