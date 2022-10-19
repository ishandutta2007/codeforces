#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, q;
	cin >> n >> q;
	int T[n];
	ll sum[n];
	rep(i, n) {
		cin >> T[i];
		sum[i]=T[i];
		if(i) sum[i]+=sum[i-1];
		if(i) T[i]=max(T[i], T[i-1]);
		
	}
	while(q--) {
		int a;
		cin >> a;
		if(a<T[0]) {
			cout << 0 << " ";
			continue;
		}
		int po=0, ko=n-1;
		while(po<ko) {
			int sr=(po+ko+1)/2;
			if(T[sr]>a) ko=sr-1; else po=sr;
		}
		cout << sum[po] << " ";
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}