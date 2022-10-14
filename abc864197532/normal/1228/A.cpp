#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

bool find (int k) {
	vector <int> nums;
	while (k) {
		nums.pb(k%10);
		k/=10;
	}
	sort(nums.begin(),nums.end());
	fop (i,1,nums.size()) {
		if (nums[i]==nums[i-1]) return false;
	}
	return true;
}

int main () {
	int l,r;
	cin >> l >> r;
	fop (i,l,r+1) {
		if (find(i)) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}