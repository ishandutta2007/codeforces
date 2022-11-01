#include <bits/stdc++.h>

using namespace std;

int n, k;
queue <int> q;


int main() {
	cin >> n >> k;
	int x = (n - 1) / k, y = (n - 1) % k;
	int dist = x + x;
	if (y == 1) ++dist;
	else if (y > 1) dist += 2;
	cout << dist << '\n';
	int ptr = 2;
	for (int i = 1; i <= k; ++i) {
		printf("1 %d\n", ptr);
		q.push(ptr);
		++ptr;
	}
	while (not q.empty()) {
		int top = q.front();
		q.pop();
		if (ptr <= n) {
			printf("%d %d\n", top, ptr);
			q.push(ptr);
			++ptr;
		}
	}
	return 0;
}