#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

#define pii pair<int, int>

typedef class Heap {
	public:
		priority_queue<pii> q, d;

		void insert(pii x) {
			q.push(x);
		}
		void remove(pii x) {
			d.push(x);
		}
		pii top() {
			while (!q.empty() && !d.empty() && q.top() == d.top())
				q.pop(), d.pop();
			return q.top();
		}
		void pop() {
			top();
			q.pop();
		}
		boolean empty() {
			return q.size() == d.size();
		}
} Heap;

int n;
int a[N], b[N];
int id[N << 1];
Heap h1, h2;
boolean rem[N];
vector<int> ans1, ans2;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", a + i, b + i);
		id[a[i]] = i, id[b[i]] = i;
	}
	int p = n << 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			h1.insert(pii(b[i], i));
		} else {
			rem[i] = true;
		}
	}
	while (!h1.empty()) {
		pii par = h1.top();
		h1.pop();
		ans1.push_back(par.second);
		rem[par.second] = true;
		while (p >= par.first) {
			if (a[id[p]] == p && !rem[id[p]]) {
				h1.remove(pii(b[id[p]], id[p]));
				rem[id[p]] = true;
			}
			p--;
		}
	}
	p = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[i]) {
			h2.insert(pii(-b[i], i));
			rem[i] = false;
		} else {
			rem[i] = true;
		}
	}
	while (!h2.empty()) {
		pii par = h2.top();
		h2.pop();
		par.first = -par.first;
		ans2.push_back(par.second);
		rem[par.second] = true;
		while (p <= par.first) {
			if (a[id[p]] == p && !rem[id[p]]) {
				h2.remove(pii(-b[id[p]], id[p]));
				rem[id[p]] = true;
			}
			p++;
		}
	}
	if (ans1.size() < ans2.size())
		ans1 = ans2;
	printf("%d\n", (signed) ans1.size());
	for (auto x : ans1) {
		printf("%d ", x);
	}
	return 0;
}