#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define pii pair<int,int>
#define mp make_pair
#define eb emplace_back
int dp[10001];


int main () {
	int n, m;
	cin >> n >> m;
	fop (i,0,10001) dp[i] = -1;
	queue <pii> nums;
	set <int> s1;
	nums.push(mp(n,0));
	while (nums.size()) {
		int a,b;
		tie(a,b) = nums.front();
		if (a == m) {
			cout << b << endl;
			return 0;
		}
		s1.insert(a);
		nums.pop();
		if (a < m and !s1.count(a*2)) nums.push(mp(a * 2, b + 1));
		if (a > 1 and !s1.count(a-1)) nums.push(mp(a - 1, b + 1));
	}
}