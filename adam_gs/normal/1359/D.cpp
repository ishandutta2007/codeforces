#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
vector<int>V[65];
int T[LIM], pre[3*LIM], N=1, nast[LIM], popr[LIM], mi[3*LIM];
int cnt(int l, int r) {
	if(l>r) return 0;
	l+=N; r+=N;
	int ans=max(pre[l], pre[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=max(ans, pre[l+1]);
		if(r%2==1) ans=max(ans, pre[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
int cnt2(int l, int r) {
	if(l>r) return 0;
	l+=N; r+=N;
	int ans=min(mi[l], mi[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=min(ans, mi[l+1]);
		if(r%2==1) ans=min(ans, mi[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(N<n) N*=2;
	rep(i, 65) V[i].pb(-LIM);
	rep(i, n) {
		cin >> T[i];
		V[T[i]+30].pb(i);
		pre[N+i]=pre[N+i-1]+T[i];
		mi[N+i]=pre[N+i];
	}
	for(int i=N-1; i; --i) {
		pre[i]=max(pre[2*i], pre[2*i+1]);
		mi[i]=min(mi[2*i], mi[2*i+1]);
	}
	rep(i, 65) V[i].pb(LIM);
	int ans=0;
	rep(i, n) {
		nast[i]=n;
		popr[i]=-1;
		for(int j=T[i]+31; j<65; ++j) {
			auto l=lower_bound(all(V[j]), i);
			nast[i]=min(nast[i], *l);
			--l;
			popr[i]=max(popr[i], *l);
		}
		int l=cnt(i, nast[i]-1)-T[i];
		if(popr[i]==-1) {
			l-=min(cnt2(0, i-1), 0);
		} else l-=cnt2(popr[i], i-1);
		ans=max(ans, l);
	}
	cout << ans << '\n';
}