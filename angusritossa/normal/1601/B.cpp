#include <bits/stdc++.h>
using namespace std;
#define MAXN 300010
set<int> unseen;
int pre[MAXN], a[MAXN], b[MAXN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) unseen.insert(i);
	unseen.insert(n+1);
	queue<int> q;
	q.push(n);
	while (q.size()) {
		int i = q.front();
		q.pop();
		int actualpos = i+b[i];
		int mn = actualpos-a[actualpos];
		auto it = unseen.lower_bound(mn);
		while (*it <= actualpos) {
			pre[*it] = i;
			q.push(*it);
			auto oldit = it;
			it++;
			unseen.erase(*oldit);

		}
	}
	if (unseen.find(0) != unseen.end()) {
		printf("-1\n");
	} else {
		vector<int> path;
		int a = 0;
		while (a != n) {
			path.push_back(a);
			a = pre[a];
		}
		reverse(path.begin(), path.end());
		printf("%lu\n", path.size());
		for (int b : path) printf("%d ", b);
		printf("\n");
	}
}