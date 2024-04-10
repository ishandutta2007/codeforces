#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli nums[100000][3],h1[100000],h2[100000],n;

lli dp(int from,int p) {
	if (from>=n) return 0;
	if (nums[from][p]>0) return nums[from][p];
	if (p==0) {
		nums[from][p]=max(dp(from,1),dp(from,2));
	} else if (p==1) {
		nums[from][p]=max(dp(from+1,2)+h1[from],dp(from+2,0)+h1[from]);
	} else {
		nums[from][p]=max(dp(from+1,1)+h2[from],dp(from+2,0)+h2[from]);
	}
	return nums[from][p];
}


int main () {
	cin >> n;
	for (int i=0;i<n;++i) cin >> h1[i];
	for (int i=0;i<n;++i) cin >> h2[i];
	cout << dp(0,0) << endl;
}