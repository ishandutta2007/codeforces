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
void solve() {
	int n, a, b;
	cin >> n >> a >> b; --a; --b;
	int T[n], odw[n];
	rep(i, n) odw[i]=0;
	T[0]=a;
	odw[a]=1;
	int akt=n-1;
	for(int i=1; i<n/2; ++i) {
		if(akt==b) --akt;
		if(odw[akt]) {
			cout << -1 << '\n';
			return;
		}
		odw[akt]=1;
		T[i]=akt;
		--akt;
	}
	akt=0;
	int ma=0;
	for(int i=n/2; i<n; ++i) {
		while(odw[akt]) ++akt;
		T[i]=akt;
		ma=max(ma, T[i]);
		++akt;
	}
	if(ma!=b) {
		cout << -1 << '\n';
		return;
	}
	rep(i, n) cout << T[i]+1 << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}