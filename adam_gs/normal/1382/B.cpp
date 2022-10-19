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
		int T[n];
		rep(i, n) cin >> T[i];
		int ans=0;
		for(; ans<n && T[ans]==1; ++ans);
		cout << ((ans%2==0)^(ans==n)?"First":"Second") << '\n';
	}
}