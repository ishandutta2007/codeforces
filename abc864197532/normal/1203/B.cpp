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
		int nums[4*n];
		fop (i,0,4*n) cin >> nums[i];
		int sum=0;
		bool is=false;
		sort(nums,nums+4*n);
		fop (i,0,n*2) {
			if (nums[2*i]!=nums[2*i+1]) {
				is=true;
				break;
			}
		}
		if (is) {
			cout << "NO" << endl;
			continue;
		}
		fop (i,0,n*2) {
			if (is) break;
			sum=nums[i]*nums[4*n-i-1];
			fop (j,0,n*2) {
				if (i==j) continue;
				if (sum!=nums[j]*nums[4*n-1-j]) break;
				if (j==n*2-1) is=true;
			}
		}
		if (is) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}