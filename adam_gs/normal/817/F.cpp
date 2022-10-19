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
const int LIM=4e5+7;
map<ll,ll>mp, invmp;
ll tr[4*LIM], ustaw[4*LIM], zmien[4*LIM], N=1;
ll typ[LIM], lewo[LIM], prawo[LIM];
vector<ll>skal;
void spl_ustaw(int v) {
	zmien[2*v]=0;
	zmien[2*v+1]=0;
	tr[2*v]=ustaw[v]/2;
	tr[2*v+1]=ustaw[v]/2;
	ustaw[2*v]=ustaw[v]/2;
	ustaw[2*v+1]=ustaw[v]/2;
	ustaw[v]=-1;
}
void spl_zmien(int v, int x) {
	tr[2*v]=x/2-tr[2*v];
	tr[2*v+1]=x/2-tr[2*v+1];
	zmien[2*v]^=1;
	zmien[2*v+1]^=1;
	zmien[v]=0;
}
void upd1(int v, int l, int r, int a, int b, int x) {
	if(l>b || r<a) return;
	if(a<=l && r<=b) {
		ustaw[v]=x*(r-l+1);
		zmien[v]=0;
		tr[v]=(r-l+1)*x;
		return;
	}
	if(ustaw[v]!=-1) spl_ustaw(v);
	if(zmien[v]) spl_zmien(v, r-l+1);
	int mid=(l+r)/2;
	upd1(2*v, l, mid, a, b, x);
	upd1(2*v+1, mid+1, r, a, b, x);
	tr[v]=tr[2*v]+tr[2*v+1];
}
void upd2(int v, int l, int r, int a, int b) {
	if(l>b || r<a) return;
	if(a<=l && r<=b) {
		zmien[v]^=1;
		tr[v]=r-l+1-tr[v];
		return;
	}
	if(ustaw[v]!=-1) spl_ustaw(v);
	if(zmien[v]) spl_zmien(v, r-l+1);
	int mid=(l+r)/2;
	upd2(2*v, l, mid, a, b);
	upd2(2*v+1, mid+1, r, a, b);
	tr[v]=tr[2*v]+tr[2*v+1];
}
int cnt(int v, int l, int r) {
	if(l==r) return l;
	if(ustaw[v]!=-1) spl_ustaw(v);
	if(zmien[v]) spl_zmien(v, r-l+1);
	int mid=(l+r)/2, ans;
	if(tr[2*v]==(r-l+1)/2) ans=cnt(2*v+1, mid+1, r);
	else ans=cnt(2*v, l, mid);
	tr[v]=tr[2*v]+tr[2*v+1];
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		cin >> typ[i] >> lewo[i] >> prawo[i];
		skal.pb(lewo[i]);
		skal.pb(prawo[i]);
		if(lewo[i]>1) skal.pb(lewo[i]-1);
		skal.pb(prawo[i]+1);
	}
	sort(all(skal));
	invmp[0]=skal[0];
	int akt=1;
	for(int i=1; i<skal.size(); ++i) {
		if(skal[i]!=skal[i-1]) {
			mp[skal[i]]=akt;
			invmp[akt]=skal[i];
			++akt;
		}
	}
	while(N<akt) N*=2;
	rep(i, 2*N) ustaw[i]=-1;
	rep(i, n) {
		int l=mp[lewo[i]], r=mp[prawo[i]];
		if(typ[i]==1) {
			upd1(1, 0, N-1, l, r, 1);
		} else if(typ[i]==2) {
			upd1(1, 0, N-1, l, r, 0);
		} else {
			upd2(1, 0, N-1, l, r);
		}
		cout << invmp[cnt(1, 0, N-1)-1]+1 << '\n';
	}
}