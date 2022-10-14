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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> nums;
		nums.pb(0);
		for (int i = 1; i <= sqrt(n); ++i) {
			nums.pb(i);
			if (n / i != i) nums.pb(n / i);
		}
		sort(nums.begin(), nums.end());
		cout << nums.size() << endl;
		fop (i,0,nums.size()) {
			cout << nums[i] << " \n"[i == nums.size() - 1];
		}
	}
}