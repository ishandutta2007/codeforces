#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
lli dp[300010];
lli MOD=998244353;

lli summ (vector <int> nums) {
	int a=nums[0],now=1;
	lli ans=1;
	fop (i,1,nums.size()) {
		if (nums[i] == a) now++;
		else {
			ans *= dp[now];
			ans %= MOD;
			a = nums[i];
			now = 1;
		}
	}
	ans *= dp[now];
	return ans % MOD;
}

lli summ2 (vector <pii> nums) {
	int a,b,now=1;
	tie(a,b) = nums[0];
	lli ans=1;
	fop (i,1,nums.size()) {
		if (b > nums[i].second) return 0;
		if (nums[i] == mp(a,b)) now++;
		else {
			ans *= dp[now];
			ans %= MOD;
			tie(a,b) = nums[i];
			now = 1;
		}
	}
	ans *= dp[now];
	return ans % MOD;
}



int main () {
	int n;
	cin >> n;
	vector <pii> nums(n);
	vector <int> f(n), s(n);
	fop (i,0,n) {
		cin >> nums[i].first >> nums[i].second;
		f[i] = nums[i].first;
		s[i] = nums[i].second;
	}
	dp[1] = 1;
	fop (i,2,n+1) {
		dp[i] = dp[i-1] * i % MOD;
	}
	sort(nums.begin(),nums.end());
	sort(f.begin(),f.end());
	sort(s.begin(),s.end());
	lli ans=0;
	ans += dp[n];
	ans += summ2(nums);
	ans -= summ(f);
	ans -= summ(s);
	while (ans < 0) ans += MOD;
	cout << ans % MOD << endl;
}