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

void solve () {
	int n;
	cin >> n;
	int a[n];
	fop (i,0,n) cin >> a[i];
	fop (i,1,n) {
		if (abs(a[i-1] - a[i]) >= 2) {
			cout << "YES" << endl;
			cout << i << ' ' << i + 1 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}