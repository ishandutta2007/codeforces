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
#define MAXN 100087

vector <int> owo (int n) {
	vector <int> ans;
	int k = n;
	for (int i = 2; i * i <= k; ++i) {
		if (n % i == 0) ans.pb(i);
		while (n % i == 0) n /= i;
	}
	if (n > 1) ans.pb(n);
	return ans;
}

int main () {
	int n;
	cin >> n;
	int in[n], dp[MAXN];
	fop (i,0,MAXN) dp[i] = 0;
	fop (i,0,n) cin >> in[i];
	int ans = 0;
	fop (i,0,n) {
		vector <int> aa = owo(in[i]);
		int aaa = 0;
		for (int i : aa) {
			aaa = max(aaa, dp[i]);
		}
		for (int i : aa) {
			dp[i] = max(dp[i], aaa + 1);
		}
		ans = max(aaa + 1, ans);
	}
	cout << ans << endl; 
}