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
const int LIM=1e5+7, LG=20;
map<int,int>mp;
int tr[4*LIM], sp[LIM][LG], N=1, lewo[LIM], prawo[LIM], nr;
vector<int>V[LIM];
int nwd(int a, int b) {
	if(!a) return b;
	return nwd(b%a, a);
}
int licz(int l, int r) {
	int o=lg(r-l+1);
	return nwd(sp[l][o], sp[r-(1<<o)+1][o]);
}
int cnt(int l, int r) {
	l+=N; r+=N;
	int ans=min(tr[l], tr[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=min(ans, tr[l+1]);
		if(r%2==1) ans=min(ans, tr[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	while(N<n) N*=2;
	rep(i, n) {
		cin >> tr[N+i];
		sp[i][0]=tr[N+i];
		if(!mp[sp[i][0]]) {
			++nr;
			mp[sp[i][0]]=nr;
		}
		V[mp[sp[i][0]]].pb(i);
	}
	for(int i=N-1; i>=0; --i) tr[i]=min(tr[2*i], tr[2*i+1]);
	for(int j=1; j<LG; ++j) {
		rep(i, n) {
			sp[i][j]=nwd(sp[i][j-1], sp[min(n-1, i+(1<<j-1))][j-1]);
		}
	}
	rep(i, n) {
		int p=0, k=i;
		while(p<k) {
			int sr=(p+k)/2;
			if(licz(sr, i)<sp[i][0]) p=sr+1; else k=sr;
		}
		lewo[i]=p;
		p=i; k=n-1;
		while(p<k) {
			int sr=(p+k+1)/2;
			if(licz(i, sr)<sp[i][0]) k=sr-1; else p=sr;
		}
		prawo[i]=p;
	}
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r; --l; --r;
		int mi=cnt(l, r), p=mp[mi];
		auto it1=lower_bound(all(V[p]), l);
		auto it2=upper_bound(all(V[p]), r);
		int ile=it2-it1;
		bool ok=false;
		if(ile>0) {
			int j=*it1;
			if(lewo[j]>l || prawo[j]<r) ile=0;
		}
		cout << r-l+1-ile << '\n';;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}