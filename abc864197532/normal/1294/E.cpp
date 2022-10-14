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
	int n,m;
	cin >> n >> m;
	int a[n][m];
	fop (i,0,n) {
		fop (j,0,m) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	fop (i,0,m) {
		int b[n], all = n;
		fop (j,0,n) b[j] = 0;
		fop (j,0,n) {
			if ((a[j][i] - i - 1) % m != 0 or a[j][i] > n * m) continue;
			int k = j - ((a[j][i] - i - 1) / m);
			if (k < 0) k += n;
			b[k]++;
		}
		fop (j,0,n) {
			all = min(all, j + n - b[j]);
		}
		ans += all;
	}
	cout << ans << endl; 
}