#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,tmp;
	cin >> n;
	int nums[n];
	fop (i,0,n) {
		cin >> nums[i];
	}
	sort(nums,nums+n);
	if (nums[0]!=1) nums[0]--;
	fop (i,1,n-1) {
		if (nums[i-1]+1<nums[i] and nums[i]!=1) {
			nums[i]--;
		} else if (nums[i-1]==nums[i] and nums[i]!=nums[i+1]) {
			nums[i]++;
		}
	}
	if (nums[n-2]==nums[n-1]) nums[n-1]++;
	int c=1;
	fop (i,0,n-1) {
		if (nums[i]!=nums[i+1]) c++;
	}
	cout << c << endl;
}