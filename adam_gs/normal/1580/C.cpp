#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, K=400;
int ile[K][K], pref[2*LIM], x[LIM], y[LIM], kiedy[LIM], akt;
void dodaj(int t, int r) {
	kiedy[r]=t;
	if(x[r]+y[r]<K) {
		for(int i=t+x[r]; i<t+x[r]+y[r]; ++i) {
			++ile[x[r]+y[r]][i%(x[r]+y[r])];
		}
	} else {
		for(int i=t; i<LIM; i+=x[r]+y[r]) {
			if(i+x[r]<LIM) ++pref[i+x[r]];
			if(i+x[r]+y[r]<LIM) --pref[i+x[r]+y[r]];
		}
	}
}
void usun(int a, int r) {
	int t=kiedy[r];
	kiedy[r]=-1;
	if(x[r]+y[r]<K) {
		for(int i=t+x[r]; i<t+x[r]+y[r]; ++i) {
			--ile[x[r]+y[r]][i%(x[r]+y[r])];
		}
	} else {
		for(int i=t; i<LIM; i+=x[r]+y[r]) {
			if(i+x[r]<a && a<=i+x[r]+y[r]) --akt;
			if(i+x[r]<LIM) --pref[i+x[r]];
			if(i+x[r]+y[r]<LIM) ++pref[i+x[r]+y[r]];
		}
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		cin >> x[i] >> y[i];
		kiedy[i]=-1;
	}
	rep(i, m) {
		int op, r;
		cin >> op >> r; --r;
		if(op==1) dodaj(i, r);
		else usun(i, r);
		akt+=pref[i];
		int p=0;
		for(int j=1; j<K; ++j) {
			p+=ile[j][i%j];
		}
		cout << akt+p << '\n';
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}