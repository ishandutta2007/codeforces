#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int nums[n];
		fop (i,0,n) {
			cin >> nums[i];
		}
		sort(nums,nums+n);
		cout << min(nums[n-2]-1,n-2) << endl;
	}
}