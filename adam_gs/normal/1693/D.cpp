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
int T[LIM], gdzie[LIM], mniejszyl[LIM], mniejszyr[LIM], wiekszyl[LIM], wiekszyr[LIM];
int tr[4*LIM], N=1;
ll P[LIM];
int cnt(int l, int r) {
	if(l>r) return INF;
	l+=N; r+=N;
	int ans=min(tr[l], tr[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=min(ans, tr[l+1]);
		if(r%2==1) ans=min(ans, tr[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
void upd(int v, int x) {
	v+=N;
	while(v) {
		tr[v]=min(tr[v], x);
		v/=2;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(N<n) N*=2;
	stack<pair<int,int>>A, B;
	A.push({-INF, -INF});
	B.push({INF, -INF});
	rep(i, n) {
		cin >> T[i]; --T[i];
		gdzie[T[i]]=i;
		P[i]=-1;
		while(T[i]<A.top().st) A.pop();
		while(T[i]>B.top().st) B.pop();
		mniejszyl[i]=A.top().nd;
		wiekszyl[i]=B.top().nd;
		A.push({T[i], i});
		B.push({T[i], i});
	}
	while(A.size()>1) A.pop();
	while(B.size()>1) B.pop();
	for(int i=n-1; i>=0; --i) {
		while(T[i]<A.top().st) A.pop();
		while(T[i]>B.top().st) B.pop();
		mniejszyr[i]=A.top().nd;
		wiekszyr[i]=B.top().nd;
		A.push({T[i], i});
		B.push({T[i], i});
	}
	rep(i, 2*N) tr[i]=INF;
	rep(i, n) {
		int x=wiekszyl[gdzie[i]];
		if(x>0 && cnt(0, x-1)<x) {
			ll p=0, k=x-1;
			while(p<k) {
				int sr=(p+k+1)/2;
				if(cnt(sr, x-1)<x) p=sr; else k=sr-1;
			}
			P[gdzie[i]]=p;
		}
		if(mniejszyr[gdzie[i]]>=0) upd(gdzie[i], mniejszyr[gdzie[i]]);
	}
	rep(i, 2*N) tr[i]=INF;
	for(int i=n-1; i>=0; --i) {
		int x=mniejszyl[gdzie[i]];
		if(x>0 && cnt(0, x-1)<x) {
			ll p=0, k=x-1;
			while(p<k) {
				int sr=(p+k+1)/2;
				if(cnt(sr, x-1)<x) p=sr; else k=sr-1;
			}
			P[gdzie[i]]=max(P[gdzie[i]], p);
		}
		if(wiekszyr[gdzie[i]]>=0) upd(gdzie[i], wiekszyr[gdzie[i]]);
	}
	ll akt=-1, ans=0;
	rep(i, n) {
		akt=max(akt, P[i]);
		ans+=i-akt;
	}
	cout << ans << '\n';
}