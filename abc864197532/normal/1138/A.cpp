#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,now,b,k=1;
	cin >> n;
	vector <int> nums;
	cin >> b;
	fop (i,1,n) {
		cin >> now;
		if (b==now) {
			k++;
		} else if (b!=now) {
			b=now;
			nums.pb(k);
			k=1;
		}
	}
	nums.pb(k);
	int maxx=0;
	fop (i,1,nums.size()) {
		maxx=max(min(nums[i-1],nums[i]),maxx);
	}
	cout << maxx*2 << endl;
}