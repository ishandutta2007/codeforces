#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=507;
int T[LIM*LIM], ans[LIM], n;
map<int,int>ile;
int nwd(int a, int b) {
	if(!a) return b;
	return nwd(b%a, a);
}
void solve() {
	cin >> n;
	rep(i, n*n) {
		cin >> T[i];
		++ile[T[i]];
	}
	sort(T, T+n*n);
	int nr=n;
	for(int i=n*n-1; i>=0; --i) {
		if(!ile[T[i]]) continue;
		--nr;
		--ile[T[i]];
		ans[nr]=T[i];
		for(int j=nr+1; j<n; ++j) {
			ile[nwd(ans[nr], ans[j])]-=2;
		}
	}
	rep(i, n) cout << ans[i] << " ";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}