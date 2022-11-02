#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int a[500100];
int n;
int nxt[500500];
int dp[500500];
int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
		a[i+2*n] = a[i];
		a[i+3*n] = a[i];
		a[i+4*n] = a[i];
	}
	vector<int> d;
	for(int i = 5*n-1; i >=0; i--) {
		while(d.size() > 0 && a[d.back()] >= a[i]) {
			d.pop_back();
		}
		if(d.size() == 0) {
			nxt[i] = 5*n;
		}else {
			int l = 0;
			int r = (int)d.size()-1;
			int res = -1;
			while(l <= r) {
				int mid = (l+r)>>1;
				if(a[d[mid]] * 2 < a[i]) {
					res = mid;
					l = mid+1;
				}else {
					r = mid-1;
				}
			}
			if(res == -1) {
				nxt[i] = 5*n;
			}else {
				nxt[i] = d[res] - 1;
			}
		}
		d.push_back(i);
	}
	dp[5*n] = 5*n;
	for(int i = 5*n-1; i >= 0; i--) {
		dp[i] = min(dp[i+1], nxt[i]);
	}
	for(int i = 0; i < n; i++) {
		int g = dp[i] - i + 1;
		if(g > 3 * n) cout << -1 << "\n";
		else cout << g << "\n";
	}
 	return 0;
}