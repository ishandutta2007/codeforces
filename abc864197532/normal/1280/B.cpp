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
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		int a[n][m];
		char cc;
		bool is[4]={false, false, false, false};
		bool b[m], c[n];
		fop (i,0,n) c[i] = true;
		fop (i,0,m) b[i] = true;
		bool iss = true;
		fop (i,0,n) {
			fop (j,0,m) {
				cin >> cc;
				if (cc == 'A') {
					a[i][j] = 1;
					is[3] = true;
					if (i == 0 or i == n-1 or j == 0 or j == m-1) is[2] = true;
				} else {
					a[i][j] = 0;
					iss = false;
					b[j] = false;
					c[i] = false;
				}
			} 
		}
		fop (i,0,n) {
			if (c[i]) {
				if (i == 0 or i == n-1) is[0] = true;
				else is[1] = true;
			}
		}
		fop (i,0,m) {
			if (b[i]) {
				if (i == 0 or i == m-1) is[0] = true;
				else is[1] = true;
			}
		}
		if (iss) {
			cout << 0 << endl;
		} else if (is[0]) {
			cout << 1 << endl;
		} else if (a[0][0] == 1 or a[0][m-1] == 1 or a[n-1][0] == 1 or a[n-1][m-1] == 1 or is[1]) {
			cout << 2 << endl;
		} else if (is[2]) {
			cout << 3 << endl;
		} else if (is[3]) {
			cout << 4 << endl;
		} else {
			cout << "MORTAL" << endl;
		}
	}
}