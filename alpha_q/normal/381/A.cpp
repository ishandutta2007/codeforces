#include <bits/stdc++.h>

using namespace std;

int n, z, x[2];
deque <int> d;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &z);
		d.push_back(z);
	}

	for (int i = 0; i < n; ++i) {
		if (d.front() > d.back()) {
			x[i & 1] += d.front();
			d.pop_front();
		} else {
			x[i & 1] += d.back();
			d.pop_back();
		}
	}

	printf("%d %d\n", x[0], x[1]);
    return 0;
}