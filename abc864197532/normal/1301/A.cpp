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
		string a, b, c;
		int cnt = 0;
		cin >> a >> b >> c;
		fop (i,0,a.length()) {
			if (a[i] == b[i] and a[i] == c[i]) {
				cnt++;
			}
			if (a[i] != b[i] and (a[i] == c[i] or b[i] == c[i])) {
				cnt++;
			}
		} 
		if (cnt == a.length()) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
}