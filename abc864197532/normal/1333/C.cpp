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
	int n;
	cin >> n;
	int input[n];
	fop (i,0,n) cin >> input[i];
	map <lli, int> m1;
	lli pre = 0, ans = 0;
	int last = -2;
	m1[0] = -1;
	fop (i,0,n) {
		pre += input[i];
		if (m1.count(pre)) {
			last = max(last, m1[pre]);
			ans += (i - last - 1);
		} else if (last != -2) {
			ans += (i - last - 1);
		} else {
			ans += i + 1;
		}
		m1[pre] = i;
	}
	cout << ans << '\n';
}