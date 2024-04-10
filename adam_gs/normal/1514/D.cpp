#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
int jaki[4*LIM], ile[4*LIM], N=1, n, q;
vector<int>V[LIM];
void zmien(int &akt, int &l, int a, int b) {
	if(akt==a) {
		l+=b;
	} else if(l>=b) {
		l-=b;
	} else {
		l=b-l;
		akt=a;
	}
}
int licz(int akt, int l, int r) {
	auto it1=upper_bound(all(V[akt]), r), it2=lower_bound(all(V[akt]), l);
	int p=it1-it2;
	if(p<=(r-l)/2+1) p=-1;
	return p;
}
int znajdz(int a, int b) {
	int l=a+N, r=b+N;
	int akt=0, li=0;
	zmien(akt, li, jaki[l], ile[l]);
	if(l!=r) zmien(akt, li, jaki[r], ile[r]);
	while(l/2!=r/2) {
		if(l%2==0) zmien(akt, li, jaki[l+1], ile[l+1]);
		if(r%2==1) zmien(akt, li, jaki[r-1], ile[r-1]);
		l/=2; r/=2;
	}
	return licz(akt, a, b);
}
void solve() {
	cin >> n >> q;
	while(N<n) N*=2;
	rep(i, n) {
		cin >> jaki[N+i];
		V[jaki[N+i]].pb(i);
		ile[N+i]=1;
	}
	for(int i=N-1; i; --i) {
		if(jaki[2*i]==jaki[2*i+1]) {
			jaki[i]=jaki[2*i];
			ile[i]=ile[2*i]+ile[2*i+1];
		} else if(ile[2*i]>=ile[2*i+1]) {
			jaki[i]=jaki[2*i];
			ile[i]=ile[2*i]-ile[2*i+1];
		} else {
			jaki[i]=jaki[2*i+1];
			ile[i]=ile[2*i+1]-ile[2*i];
		}
	}
	while(q--) {
		int l, r;
		cin >> l >> r; --l; --r;
		int m=znajdz(l, r);
		if(m==-1) {
			cout << 1 << '\n';
			continue;
		}
		int z=(r-l+1)-m;
		cout << 1+(r-l+1)-(2*z+1) << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}