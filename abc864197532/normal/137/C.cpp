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
	int n;
	cin >> n;
	vector <pii> nums;
	fop (i,0,n) {
		int a,b;
		cin >> a >> b;
		nums.eb(a,b);
	}
	sort(nums.begin(),nums.end());
	int r=nums[0].second, ans=0;
	fop (i,1,n) {
		if (nums[i].second < r) ans++;
		if (r < nums[i].second) r = nums[i].second;
	}
	cout << ans << endl;
	
}