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

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = INT_MAX, l = 0, r = 0, nowx = 0, nowy = 0;
		map <pii, int> nums;
		nums[{0,0}] = -1;
		fop (i,0,n) {
			if (s[i] == 'R') nowy++;
			if (s[i] == 'L') nowy--;
			if (s[i] == 'U') nowx++;
			if (s[i] == 'D') nowx--;
			if (nums.count({nowx, nowy})) {
				if (ans > i - nums[{nowx, nowy}]) {
					ans = i - nums[{nowx, nowy}];
					l = nums[{nowx, nowy}];
					r = i;
				}
			}
			nums[{nowx, nowy}] = i;
		}
		if (ans == INT_MAX) cout << -1 << endl;
		else cout << l + 2 << ' ' << r + 1 << endl;
	}
}