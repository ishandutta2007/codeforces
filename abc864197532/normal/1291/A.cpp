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
		string s;
		cin >> n >> s;
		string ans = "";
		int now = 0;
		fop (i,0,n) {
			if ((s[i]- '0') % 2) {
				ans += s[i];
				now++;
			}
			if (now == 2) break;
		}
		if (now != 2) cout << -1 << endl;
		else cout << ans << endl;
	}
}