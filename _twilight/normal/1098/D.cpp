#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int bzmax = 32;

typedef class Heap {
	public:
		int size;
		priority_queue<int, vector<int>, greater<int> > q, d;

		Heap() : size(0) {	}

		void push(int x) {	++size, q.push(x);	}
		void remove(int x) {	--size, d.push(x);	}
		boolean empty() {	return !size;	}
		int top() {
			while (!q.empty() && !d.empty() && q.top() == d.top())
				q.pop(), d.pop();
			return q.top();
		}
} Heap;

int n;
char _[10];
ll sums[bzmax];
Heap hs[bzmax];

int getId(int x) {		// [2^(rt - 1), 2^rt)
	return 32 - __builtin_clz(x);
}

inline void solve() {
	scanf("%d", &n);
	int x, sz = 0;
	while (n--) {
		scanf("%s%d", _, &x);
		int id = getId(x);
		if (_[0] == '+') {
			sz++;
			sums[id] += x;
			hs[id].push(x);
		} else {
			sz--;
			sums[id] -= x;
			hs[id].remove(x);
		}
		int ans = sz;
		ll sum = 0;
		for (int i = 1; i < bzmax; i++) {
			if (hs[i].empty()) {
				continue;
			}
			if (hs[i].top() > (sum << 1)) {
				ans--;
			}
			sum += sums[i];
		}
		printf("%d\n", ans);
	}
}

int main() {
	solve();
	return 0;
}