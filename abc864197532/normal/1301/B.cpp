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
		cin >> n;
		int a[n];
		fop (i,0,n) cin >> a[i];
		int now_min = 0;
		vector <int> aa;
		fop (i,1,n-1) {
			if (a[i] == -1) {
				if (a[i-1] != -1) aa.pb(a[i-1]);
				if (a[i+1] != -1) aa.pb(a[i+1]);
			}
		}
		fop (i,1,n) {
			if (a[i] != -1 and a[i-1] != -1) {
				now_min = max(now_min, abs(a[i] - a[i-1]));
			} 
		}
		if (a[0] == -1 and a[1] != -1) aa.pb(a[1]);
		if (a[n-1] == -1 and a[n-2] != -1) aa.pb(a[n-2]);
		if (aa.empty()) {
			cout << now_min << ' ' << 0 << endl;
			continue; 
		}
		sort(aa.begin(), aa.end());
		int kk = aa.back() - aa[0];
		cout << max(now_min, (kk + 1) / 2) << ' ' << (aa.back() + aa[0]) / 2 << endl;
	}
}