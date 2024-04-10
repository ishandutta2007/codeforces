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
		int w, h, n, ans=1;
		cin >> w >> h >> n;
		while(w%2==0) { w/=2; ans<<=1; }
		while(h%2==0) { h/=2; ans<<=1; }
		cout << (ans>=n?"YES":"NO") << '\n';
	}
}