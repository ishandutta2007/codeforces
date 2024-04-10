#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;

int main () {
	int t;
	cin >> t;
	fop (i,0,t) {
		int n,m,k;
		cin >> n >> m >> k;
		int h[n];
		fop (j,0,n) cin >> h[j];
		bool is=true;
		fop (j,0,n-1) {
			if (h[j]+m+k>=h[j+1]) {
				m+=min(h[j]-h[j+1]+k,h[j]);
			} else {
				is=false;
				break;
			}
		}
		if (is) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}