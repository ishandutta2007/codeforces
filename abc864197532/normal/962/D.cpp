#include <bits/stdc++.h>
using namespace std;
#define ya pair<long long, int>

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	priority_queue <ya, vector<ya>, greater<ya>> pq;
	for (int i = 0; i < n; ++i) {
		pq.push({a[i], i});
	}
	vector <ya> ans;
	while (pq.size() >= 2) {
		ya A = pq.top(); pq.pop();
		if (A.first != pq.top().first) {
			ans.push_back(A);
		} else {
			ya B = pq.top(); pq.pop();
			pq.push({A.first * 2, B.second});
		}
	}
	ans.push_back(pq.top());
	sort(ans.begin(), ans.end(), [](ya A, ya B) {
		return A.second < B.second;
	});
	cout << ans.size() << endl;
	for (auto A : ans) cout << A.first << ' ';
	cout << endl;
}