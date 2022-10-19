#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		int T[n], ans=1;
		rep(i, n) {
			cin >> T[i];
			if(T[i]>d) ans=0;
		}
		sort(T, T+n);
		cout << (ans || T[0]+T[1]<=d?"YES":"NO") << '\n';
	}
}