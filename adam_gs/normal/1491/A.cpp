#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	int n, q;
	cin >> n >> q;
	int T[n], zero=0, jeden=0;
	rep(i, n) {
		cin >> T[i];
		if(T[i]) ++jeden; else ++zero;
	}
	while(q--) {
		int t, a;
		cin >> t >> a;
		if(t==1) {
			--a;
			if(T[a]) {
				--jeden;
				++zero;
			} else {
				++jeden;
				--zero;
			}
			T[a]^=1;
		} else {
			if(jeden>=a) {
				cout << 1 << '\n';
			} else cout << 0 << '\n';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, typ=0;
	if(typ) cin >> t; else t=1;
	while(t--) solve();
}