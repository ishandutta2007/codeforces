#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	string s;
	cin >> s;
	vector <int> nums;
	int now=1;
	char c=s[0];
	fop (i,1,s.length()) {
		if (c == s[i]) {
			now++;
		} else {
			nums.pb(now);
			c = s[i];
			now = 1;
		}
	}
	nums.pb(now);
	int ans=0;
	fop (i,0,nums.size()) {
		ans += (nums[i] + 4) / 5;
	}
	cout << ans << endl;
}