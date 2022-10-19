#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll T[n], a=0, b=0;
		rep(i, n) cin >> T[i];
		sort(T, T+n);
		int l=1;
		for(int i=n-1; i>=0; --i) {
			if(l) {
				if(T[i]%2==0) a+=T[i];
			} else {
				if(T[i]%2) b+=T[i];
			}
			l^=1;
		}
		if(a==b) {
			cout << "Tie\n";
			continue;
		}
		cout << (a>b?"Alice":"Bob") << '\n';
	}
}