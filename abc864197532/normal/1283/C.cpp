#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define endl '\n'

int main () {
	srand(time(NULL));
	int n;
	cin >> n;
	int a[n];
	set <int> s1;
	vector <int> nums;
	fop (i,1,n+1) s1.insert(i);
	fop (i,0,n) cin >> a[i], s1.erase(a[i]);
	for (int i : s1) nums.pb(i);
	int ans[n];
	while (true) {
		int now = 0;
		random_shuffle(nums.begin(), nums.end());
		fop (i,0,n) {
			if (now < nums.size() and a[i] == 0) ans[i] = nums[now], now++;
			else ans[i] = a[i];
		}
		bool is = true;
		fop (i,0,n) {
			if (ans[i] == i + 1) is = false;
		}
		if (is) break;
	}
	fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}