#include<bits/stdc++.h>
using namespace std;
int h[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;
		for (int i = 1; i <= n; i++) cin >> h[i];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int i = 1; i <= m; i++) pq.push(make_pair(0, i));
		puts("YES");
		for (int i = 1; i <= n; i++) {
			pair<int, int> p = pq.top();
			cout << p.second << ' ', pq.pop();
			p.first += h[i];
			pq.push(p);
		}
		cout << endl;
	}
}