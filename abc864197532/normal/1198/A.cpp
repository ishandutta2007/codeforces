#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
int main () {
	int n,k;
	cin >> n >> k;
	int a[n];
	fop (i,0,n) cin >> a[i];
	sort(a,a+n);
	vector <int> nums;
	int now=a[0],b=1;
	fop (i,1,n) {
		if (a[i] == now)b++;
		else {
			nums.pb(b);
			now = a[i];
			b = 1;
		}
	}
	nums.pb(b);
	int first[nums.size()+1],sec[nums.size()+1];
	first[0] = sec[0] = 0;
	fop (i,1,nums.size()+1) first[i] = first[i-1] + nums[i-1];
	fop (i,1,nums.size()+1) sec[i] = sec[i-1] + nums[nums.size()-i];
	int t=8*k/n;
	if (t >= 19) {
		cout << 0 << endl;
		return 0;
	} else {
		t = 1 << t;
	}
	if (t >= nums.size()) {
		cout << 0 << endl;
		return 0;
	}
	int minn=INT_MAX;
	fop (i,0,nums.size()-t) {
		minn=min(first[i] + sec[nums.size()-t-i],minn);
	}
	cout << minn << endl;
}