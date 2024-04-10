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
	int n,k;
	cin >> n >> k;
	vector <pii> nums[200001];
	fop (i,0,n) {
		int a,b;
		cin >> a >> b;
		nums[a].eb(b,i);
	}
	vector <int> ans;
	set <pii> now;
	fop (i,1,200001) {
		while (now.size() and now.begin()->first == i - 1) now.erase(now.begin());
		fop (j,0,nums[i].size()) {
			now.insert(nums[i][j]);
		}
		while (now.size() > k) {
			ans.pb((--now.end())->second);
			now.erase(--now.end());
		}
	}
    sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	fop (i,0,ans.size()) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
	return 0;
}