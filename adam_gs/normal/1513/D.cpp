#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (a?31-__builtin_clz(a):0)
const int LIM=2e5+7, LG=20;
ll tr[LIM][LG], T[LIM], mi[4*LIM], N=1;
ll nwd(ll a, ll b) {
	if(!a) return b;
	return nwd(b%a, a);
}
ll cnt(int l, int r) {
	int x=lg(r-l+1);
	return nwd(tr[l][x], tr[r-(1<<x)+1][x]);
}
void upd(int l, int r, ll x) {
	l+=N; r+=N;
	mi[l]=min(mi[l], x);
	mi[r]=min(mi[r], x);
	while(l/2!=r/2) {
		if(l%2==0) mi[l+1]=min(mi[l+1], x);
		if(r%2==1) mi[r-1]=min(mi[r-1], x);
		l/=2; r/=2;
	}
}
void solve() {
	int n;
   	ll x;
	cin >> n >> x;
	while(N<n) N*=2;
	rep(i, 2*N) mi[i+1]=x;
	rep(i, n) {
		cin >> T[i];
		tr[i][0]=T[i];
	}
	for(int i=1; i<LG; ++i) {
		rep(j, n) {
			tr[j][i]=nwd(tr[j][i-1], tr[min(j+(1<<i-1), n-1)][i-1]);
		}
	}
	rep(i, n) {
		int p=0, k=i;
		while(p<k) {
			int sr=(p+k)/2;
			if(cnt(sr, i)==T[i]) k=sr; else p=sr+1;
		}
		int pocz=p;
		p=i; k=n-1;
		while(p<k) {
			int sr=(p+k+1)/2;
			if(cnt(i, sr)==T[i]) p=sr; else k=sr-1;
		}
		if(pocz!=p) upd(pocz, p-1, T[i]);
	}
	ll ans=0;
	rep(i, n-1) {
		ll p=i+N, akt=x;
		while(p>1) {
			akt=min(akt, mi[p]);
			p/=2;
		}
		ans+=akt;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}