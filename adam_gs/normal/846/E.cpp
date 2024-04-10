#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const __int128 INF=1e18+7;
const int LIM=1e5+7;
__int128 mam[LIM], chce[LIM], K[LIM];
int oc[LIM];
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		ll a;
		cin >> a;
		mam[i]=a;
	}
	rep(i, n) {
		ll a;
		cin >> a;
		chce[i]=a;
	}
	rep(i, n-1) {
		ll a, b;
		cin >> a >> b; --a;
		oc[i+1]=a;
		K[i+1]=b;
	}
	for(int i=n-1; i; --i) {
		if(mam[i]>=chce[i]) mam[oc[i]]+=mam[i]-chce[i];
		else {
			chce[oc[i]]+=K[i]*(chce[i]-mam[i]);
			if(chce[oc[i]]>INF) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << (mam[0]>=chce[0]?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}