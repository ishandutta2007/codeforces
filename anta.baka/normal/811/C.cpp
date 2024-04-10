/*
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





 
 

*/

#include <bits/stdc++.h>

using namespace std;

int n, a[5001];
vector<int> l(5001, INT_MAX), r(5001, INT_MIN);
vector<int> seg(5001, -1);
bool valid[5001][5001];
int value[5001][5001];
vector<int> last(5001, -1);
vector<int> value1(5001, 0);
int dp[5001];
int myl[5000], myr[5000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		l[x] = min(l[x], i);
		r[x] = max(r[x], i);
		a[i] = x;
	}
	for(int i = 0; i < 5001; i++) {
		if(l[i] == INT_MAX) continue;
		seg[l[i]] = max(seg[l[i]], r[i]);
	}
	for(int i = 0; i < n; i++) myl[i] = l[a[i]], myr[i] = r[a[i]];
	for(int i = 0; i < n; i++) {
		int lf = myl[i], rg = myr[i];
		for(int j = i; j < n; j++) {
			lf = min(lf, myl[j]);
			rg = max(rg, myr[j]);
			valid[i][j] = false;
			if(i <= lf && rg <= j) valid[i][j] = true;
		}
	}
	/*
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			cout << i << ' ' << j << ' ' << valid[i][j] << '\n';
	return 0;
	*/
	for(int i = 0; i < n; i++) {
		int x = a[i];
		if(last[x] != -1) value1[last[x]] = 0;
		value1[i] = x;
		last[x] = i;
		int curxor = 0;
		for(int j = i; j >= 0; j--) {
			curxor ^= value1[j];
			value[j][i] = curxor;
		}
	}
	/*
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			cout << i << ' ' << j << ' ' << value[i][j] << '\n';
	return 0;
	*/
	for(int i = 0; i < n; i++) {
		if(i) dp[i] = dp[i - 1];
		for(int j = i; j >= 0; j--) if(valid[j][i]) dp[i] = max(dp[i], (j ? dp[j - 1] : 0) + value[j][i]);
	}
	cout << dp[n - 1];
}