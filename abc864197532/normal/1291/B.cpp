#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		bool is = true, is2 = false;
		fop (i,0,n) cin >> a[i];
		fop (i,0,n/2) {
			if (a[i] < i) {
				is = false;
			}
		}
		fop (i,n/2,n) {
			if (a[i] < n - i - 1) {
				is = false;
			}
		}
		if (n % 2 == 0) {
			if (a[n/2] == a[n/2-1] and a[n/2] == n/2-1) is = false;
		}
		if (is) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}