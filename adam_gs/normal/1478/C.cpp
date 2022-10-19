#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll T[2*n];
		rep(i, 2*n) cin >> T[i];
		sort(T, T+2*n);
		int l=1, sp=0;
		rep(i, 2*n-1) {
			if(T[i]!=T[i+1]) {
				if(l==1) {
					sp=1;
					break;
				}
				l=0;
			}
			l+=1;
			if(l==3 || T[i]%2==1) {
				sp=1;
				break;
			}
		}
		if(sp && T[2*n-1]%2==1) {
			cout << "NO\n";
			continue;
		}
		rep(i, n) T[i]=T[2*i]/2;
		ll o=0;
		for(ll i=n-1; i>=0; --i) {
			T[i]-=o;
			if(T[i]<=0) {
				sp=1;
				break;
			}
			if(T[i]%(i+1)) {
				sp=1;
				break;
			}
			T[i]/=(i+1);
			o+=T[i];
		}
		cout << (sp?"NO":"YES") << '\n';
	}
}