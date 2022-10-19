#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int a[150005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		pq.push(a[n]);
		int res = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] > pq.top()) res++;
			//cout << pq.top() << endl;
			pq.push(a[i]); 
		}
		while (!pq.empty()) pq.pop();
		cout << res << endl;
	}
	return 0;
}