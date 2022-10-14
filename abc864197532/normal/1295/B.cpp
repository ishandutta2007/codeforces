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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	int n,x;
	string s;
	while (t--) {
		int tmp = 0;
		cin >> n >> x >> s;
		int a[n+1];
		a[0] = 0;
		fop (i,0,n) {
			if (s[i] == '1') tmp--;
			else tmp++;
			a[i+1] = tmp;
		}
		int ans = 0;
		if (tmp == 0) {
			fop (i,0,n+1) {
				if (a[i] == x) ans = -1;
			}
		} else {
			fop (i,0,n) {
				if ((a[i] - x) % tmp == 0 and (a[i] - x) / tmp <= 0) ans++;
			}
		}
		cout << ans << endl;
	}
}