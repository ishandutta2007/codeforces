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
	int n, m;
	cin >> n >> m;
	string T[n+1], ans[n+1];
	rep(i, n) cin >> T[i];
	rep(i, n+1) ans[i]="";
	T[n]="";
	rep(j, m) T[n]+="o";
	rep(j, m) {
		int i=n;
		while(i>=0) {
			if(T[i][j]=='o') {
				ans[i]+="o";
				int p=i-1, ile=0;
				while(p>=0 && T[p][j]!='o') {
					if(T[p][j]=='*') ++ile;
					--p;
				}
				--i;
				while(ile--) {
					ans[i]+="*";
					--i;
				}
				i=p+1;
			}
			--i;
		}
		rep(i, n) if(ans[i].size()==j) ans[i]+=".";
	}
	rep(i, n) cout << ans[i] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}