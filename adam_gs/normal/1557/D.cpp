#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
int tr[1<<21], jaki[1<<21], lazy[1<<21], lazy2[1<<21], N=1;
int lst[LIM], uzyte[LIM];
vector<int>skal;
vector<pair<int,int>>V[LIM];
map<int,int>mp;
void spl(int v) {
	if(lazy[v]>tr[2*v]) {
		tr[2*v]=lazy[v];
		jaki[2*v]=lazy2[v];
	}
	if(lazy[v]>tr[2*v+1]) {
		tr[2*v+1]=lazy[v];
		jaki[2*v+1]=lazy2[v];
	}
	if(lazy[v]>lazy[2*v]) {
		lazy[2*v]=lazy[v];
		lazy2[2*v]=lazy2[v];
	}
	if(lazy[v]>lazy[2*v+1]) {
		lazy[2*v+1]=lazy[v];
		lazy2[2*v+1]=lazy2[v];
	}
	lazy[v]=lazy2[v]=0;
}
void upd(int v, int l, int r, int a, int b, int x, int y) {
	if(b<l || a>r) return;
	if(a<=l && r<=b) {
		if(x>tr[v]) {
			tr[v]=x;
			jaki[v]=y;
		}
		if(x>lazy[v]) {
			lazy[v]=x;
			lazy2[v]=y;
		}
		return;
	}
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	upd(2*v, l, mid, a, b, x, y);
	upd(2*v+1, mid+1, r, a, b, x, y);
	if(tr[2*v]>tr[2*v+1]) {
		tr[v]=tr[2*v];
		jaki[v]=jaki[2*v];
	} else {
		tr[v]=tr[2*v+1];
		jaki[v]=jaki[2*v+1];
	}
}
pair<int,int>cnt(int v, int l, int r, int a, int b) {
	if(b<l || a>r) return {0, 0};
	if(a<=l && r<=b) return {tr[v], jaki[v]};
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	pair<int,int>ans1=cnt(2*v, l, mid, a, b);
	pair<int,int>ans2=cnt(2*v+1, mid+1, r, a, b);
	if(tr[2*v]>tr[2*v+1]) {
		tr[v]=tr[2*v];
		jaki[v]=jaki[2*v];
	} else {
		tr[v]=tr[2*v+1];
		jaki[v]=jaki[2*v+1];
	}
	return max(ans1, ans2);
}
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c; --a;
		skal.pb(b);
		skal.pb(c);
		V[a].pb({b, c});
	}
	sort(all(skal));
	int l=0;
	for(int i=1; i<skal.size(); ++i) {
		if(skal[i]!=skal[i-1]) {
			++l;
			mp[skal[i]]=l;
		}
	}
	while(N<=l) N*=2;
	int ans=0, ostatni=-1;
	rep(i, n) {
		int ma=0;
		lst[i]=-1;
		for(auto j : V[i]) {
			int a=mp[j.st], b=mp[j.nd];
			pair<int,int>p=cnt(1, 0, N-1, a, b);
			if(p.st>ma) {
				ma=p.st;
				lst[i]=p.nd;
			}
		}
		++ma;
		if(ma>ans) {
			ans=ma;
			ostatni=i;
		}
		for(auto j : V[i]) {
			int a=mp[j.st], b=mp[j.nd];
			upd(1, 0, N-1, a, b, ma, i);
		}
	}
	cout << n-ans << '\n';
	while(ostatni!=-1) {
		uzyte[ostatni]=1;
		ostatni=lst[ostatni];
	}
	rep(i, n) if(!uzyte[i]) cout << i+1 << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	while(_--) solve();
}