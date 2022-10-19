#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n, ans=0;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	rep(i, n-1) {
		if(min(T[i], T[i+1])==2 && max(T[i], T[i+1])==3) {
			cout << "Infinite\n";
			return;
		} else {
			int p=max(T[i], T[i+1]);
			if(p==3) {
				ans+=4;
			} else {
				ans+=3;
			}
		}
	}
	rep(i, n-2) {
		if(T[i]==3 && T[i+1]==1 && T[i+2]==2) --ans;
	}
	cout << "Finite\n" << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}