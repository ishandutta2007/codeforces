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
		vector <int> nums;
		int n, tmp;
		cin >> n;
		int now = 1, p;
		cin >> p;
		fop (i,1,n) {
			cin >> tmp;
			if (tmp == p) {
				now++;
			} else {
				nums.pb(now);
				p = tmp;
				now = 1;
			}
		}
		nums.pb(now);
		int ans[3], summ = 0;
		ans[0] = nums[0];
		ans[1] = ans[2] = 0;
		fop (i,0,nums.size()) {
			summ += nums[i];
			if (summ > n / 2) {
				summ -= nums[i];
				p = i;
				break;
			}
		}
		if (p < 3) {
			cout << "0 0 0" << endl;
			continue;
		}
		now = 1;
		fop (i,1,p) {
			ans[now] += nums[i];
			if (ans[now] > ans[0] and now == 1) now++;
		}
		if (ans[2] <= ans[0]) cout << "0 0 0" << endl;
		else fop (i,0,3) cout << ans[i] << " \n"[i == 2]; 
	}
}