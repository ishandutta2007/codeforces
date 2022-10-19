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
		if(n==1) {
			cout << "9\n";
			continue;
		}
		cout << "98";
		n-=2;
		int l=8;
		rep(i, n) {
			++l;
			l%=10;
			cout << l;
		}
		cout << '\n';
	}
}