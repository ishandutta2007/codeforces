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
vector<pair<pair<int,int>,int>>stos;
vector<pair<int,int>>tr[4*LIM];
pair<int,pair<int,int>>T[LIM];
int nxt[LIM][2], F[LIM], ile[LIM], N=1, n, m, last;
map<pair<int,int>,int>mp;
void upd(int l, int r, pair<int,int>x) {
	if(l>r) return;
	l+=N; r+=N;
	tr[l].pb(x);
	if(l!=r) tr[r].pb(x);
	while(l/2!=r/2) {
		if(l%2==0) tr[l+1].pb(x);
		if(r%2==1) tr[r-1].pb(x);
		l/=2; r/=2;
	}
}
int fnd(int x) {
	if(F[x]==x) return x;
	return fnd(F[x]);
}
void uni(int a, int b) {
	a=fnd(a);
	b=fnd(b);
	if(a==b) {
		stos.pb({{-1, -1}, -1});
		return;
	}
	if(ile[a]>ile[b]) swap(a, b);
	stos.pb({{a, b}, ile[b]});
	ile[b]+=ile[a];
	F[a]=b;
}
void usun() {
	auto x=stos.back(); stos.pop_back();
	if(x.st.st==-1) return;
	F[x.st.st]=x.st.st;
	ile[x.st.nd]=x.nd;
}
void solve(int v) {
	for(auto i : tr[v]) uni(i.st, i.nd);
	if(v<N) {
		solve(2*v);
		solve(2*v+1);
	} else if(v-N<m) {
		pair<int,int>a=T[v-N].nd, b={(a.st+1)%n, (a.nd+1)%n};
		if(b.st>b.nd) swap(b.st, b.nd);
		if(T[v-N].st==1) {
			if(!last) {
				if(mp[b]) upd(v-N+1, nxt[v-N][1], b);
				if(!mp[a]) upd(v-N+1, nxt[v-N][0], a);
				mp[a]^=1;
			} else {
				if(mp[a]) upd(v-N+1, nxt[v-N][0], a);
				if(!mp[b]) upd(v-N+1, nxt[v-N][1], b);
				mp[b]^=1;
			}
		} else {
			if(last) a=b;
			last=fnd(a.st)==fnd(a.nd);
			cout << last;
		}
	}
	rep(i, tr[v].size()) usun();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while(N<m) N*=2;
	rep(i, n) {
		F[i]=i;
		ile[i]=1;
	}
	rep(i, m) {
		cin >> T[i].st >> T[i].nd.st >> T[i].nd.nd;
		--T[i].nd.st; --T[i].nd.nd;
		if(T[i].nd.st>T[i].nd.nd) swap(T[i].nd.st, T[i].nd.nd);
	}
	if(n==2) {
		int ok=0;
		rep(i, m) if(T[i].st==1) ok^=1; else cout << ok;
		cout << '\n';
		return 0;
	}
	for(int i=m-1; i>=0; --i) if(T[i].st==1) {
		if(mp[T[i].nd]) nxt[i][0]=mp[T[i].nd];
		else nxt[i][0]=m-1;
		auto x=T[i].nd; x={(x.st+1)%n, (x.nd+1)%n};
		if(x.st>x.nd) swap(x.st, x.nd);
		if(mp[x]) nxt[i][1]=mp[x];
		else nxt[i][1]=m-1;
		mp[T[i].nd]=i;
		mp[x]=i;
	}
	mp.clear();
	solve(1);
	cout << '\n';
}