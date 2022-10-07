#include <bits/stdc++.h>

std::mt19937 rnd(time(0));

const int N = 100005;
const long long LIM = 1500000ll * 1500000ll;

int n;

struct Node {
	int x, y;

	Node() { x = 0, y = 0; }
	Node(int _x, int _y) : x(_x), y(_y) {}

	Node operator + (const Node &rhs) const {
		return Node(x + rhs.x, y + rhs.y);
	}

	Node operator * (const int t) const {
		return Node(x * t, y * t);
	}
	
	long long len2() {
		return 1ll * x * x + 1ll * y * y;
	}
};

Node a[N];
int p[N];
int ans[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].x >> a[i].y;
	}
	while (1) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
		}
		std::shuffle(p + 1, p + 1 + n, rnd);
		Node now(0, 0);
		for (int i = 1; i <= n; ++i) {
			Node nx1 = now + a[p[i]], nx2 = now + a[p[i]] * (-1);
			if ((nx1.len2() <= LIM) == (nx2.len2() <= LIM)) {
				if (rnd() & 1) {
					now = nx1;
					ans[p[i]] = 1;
				} else {
					now = nx2;
					ans[p[i]] = -1;
				}
			} else if (nx1.len2() <= LIM) {
				now = nx1;
				ans[p[i]] = 1;
			} else {
				now = nx2;
				ans[p[i]] = -1;
			}
		}
		if (now.len2() <= LIM) {
			for (int i = 1; i <= n; ++i) {
				std::cout << ans[i] << " \n"[i == n];
			}
			return 0;
		}
	}
}