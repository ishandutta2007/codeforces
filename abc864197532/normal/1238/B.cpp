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
		int n,r,tmp;
		cin >> n >> r;
		vector <int> nums;
		set <int> s;
		fop (i,0,n) {
			cin >> tmp;
			s.insert(tmp);
		}
		for (auto i : s) {
			nums.pb(i);
		}
		sort(nums.begin(),nums.end());
		int ans=0;
		while (true) {
			ans++;
			if (nums.size()<=ans) break;
			if (nums[nums.size()-1-ans]<=ans*r) break;
		}
		cout << ans << endl;
	}
}