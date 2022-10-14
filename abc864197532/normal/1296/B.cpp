#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		while (n > 9) {
			int aa = n / 10;
			ans += aa * 10;
			n -= aa * 10;
			n += aa;
		}
		cout << ans + n << endl; 
	}
}