#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), pr(n + 1);
	pr[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pr[i + 1] = pr[i] + a[i];
	}
	int ans = 0;
	set<int> pr1;
	pr1.insert(pr[0]);
	int end = 0;
	for (int i = 0; i < n; ++i) {
		while(end < n&&pr1.count(pr[end+1]) == 0){
			end += 1;
			pr1.insert(pr[end]);
		}
		ans += end-i;
		pr1.erase(pr[i]);
	}
	cout << ans << endl;
	return 0;
}