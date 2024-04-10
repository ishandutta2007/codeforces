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
	int n,m;
	lli d;
	cin >> n >> m >> d;
	lli a[m+1], b[m+1], t[m+1];
	lli dp[2][n];
	t[0] = 0;
	fop (i,1,m+1) cin >> a[i] >> b[i] >> t[i], a[i]--;
	int before = 0;
	long long ans = LLONG_MIN;
	fop (i,0,n) dp[0][i] = 0;
	deque <int> dq;
	fop (i,1,m+1) {
	    before = 0;
		fop (j,0,n) {
		    int f = max(0ll, j - d * (t[i] - t[i-1])), s = min(1ll * n, j + d * (t[i] - t[i-1]) + 1);
		    while (!dq.empty() and dq.front() < f) dq.pop_front();
		    while (before < s) {
		        while (!dq.empty() and dp[!(i & 1)][dq.back()] < dp[!(i & 1)][before]) dq.pop_back();
		        dq.push_back(before);
		        before++;
		    }
		    dp[i & 1][j] = b[i] - abs(a[i] - j) + dp[!(i & 1)][dq.front()];
		}
		dq.clear();
	}
    cout << *max_element(dp[m & 1], dp[m & 1] + n) << endl;
}