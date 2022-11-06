#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	priority_queue<int> pq;

	while (n) {
		pq.push(n ^ (n & (n - 1)));
		n &= n - 1;
	}

	while ((int) pq.size() < k && pq.top() > 1) {
		pq.push(pq.top() >> 1);
		pq.push(pq.top() >> 1);
		pq.pop();
	}


	if((int)pq.size() != k)
		cout << "NO\n";
	else {
		cout << "YES\n";
		while(k--) {
			cout << pq.top() << ' ';
			pq.pop();
		}
	}
	return 0;
}