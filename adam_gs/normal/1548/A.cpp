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
const int LIM=2e5+7;
int ile[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	int ans=n;
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		++ile[min(a, b)];
		if(ile[min(a, b)]==1) --ans;
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(x==1) {
			int a, b;
			cin >> a >> b; --a; --b;
			++ile[min(a, b)];
			if(ile[min(a, b)]==1) --ans;
		} else if(x==2) {
			int a, b;
			cin >> a >> b; --a; --b;
			--ile[min(a, b)];
			if(ile[min(a, b)]==0) ++ans;
		} else {
			cout << ans << '\n';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}