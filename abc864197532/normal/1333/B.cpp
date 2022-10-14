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

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		fop (i,0,n) cin >> a[i];
		fop (i,0,n) cin >> b[i];
		bool c[3];
		fop (i,0,3) c[i] = false;
		bool is = (a[0] == b[0]);
		fop (i,1,n) {
			c[a[i-1] + 1] = true;
			if (a[i] < b[i] and !c[2]) is = false;
			if (a[i] > b[i] and !c[0]) is = false;
		}
		cout << (is ? "Yes" : "No") << endl;
	}
}