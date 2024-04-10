#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
	int t;
	cin >> t;
	string aaa = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	while (t--) {
		int n,m,k;
		cin >> n >> m >> k;
		char a[n][m];
		int r=0;
		fop (i,0,n) {
			fop (j,0,m) {
				cin >> a[i][j];
				if (a[i][j] == 'R') r++;
			}
		}
		int b = r / k;
		int i = 0, j = 0, aa = 0, now = 0, c = 0;
		int ans[n][m];
		while (c < n * m) {
			c++;
			ans[i][j] = aa;
			if (a[i][j] == 'R') {
				now++;
			}
			if (now == b + (aa < r % k)) {
				aa++;
				now = 0;
			}
			if (i % 2) j--;
			else j++;
			if (j < 0) {
				i++;
				j++;
			} else if (j == m) {
				i++;
				j--;
			}
		}
		fop (i,0,n) {
			fop (j,0,m) {
				if (ans[i][j] >= k) ans[i][j] = k - 1;
				cout << aaa[ans[i][j]];
			}
			cout << endl;
		}
	}
}