#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n,k,d;
		cin >> n >> k >> d;
		int x[n];
		map <int, int> nums;
		fop (i,0,n) cin >> x[i];
		int now=0, minn=0;
		fop (i,0,d) {
			if (!nums.count(x[i])) {
			    nums[x[i]] = 1;
			    now++;
			} else {
			    nums[x[i]]++;
			}
		}
		minn = now;
		for (int i=0, j=d; j<n; ++i, ++j) {
			if (nums[x[i]] == 1) {
				nums.erase(x[i]);
				now--;
			} else {
				nums[x[i]]--;
			} if (!nums.count(x[j])) {
				nums[x[j]] = 1;
				now++;
			} else {
				nums[x[j]]++;
			}
			minn = min(minn, now);
		}
		cout << minn << endl;
	}
}