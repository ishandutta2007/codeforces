#include <iostream>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, ans=0;
		cin >> n >> m;
		rep(i, n) {
			int a;
			cin >> a;
			ans+=a;
		}
		if(ans==m) cout << "YES"; else cout << "NO";
		cout << '\n';
	}
}