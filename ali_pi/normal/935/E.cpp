#include <bits/stdc++.h>

using namespace std;

string E;
char O[] = { '+', '-' };

typedef vector<array<int, 2>> T;

void update(array<int, 2> &a, array<int, 2> &a1, array<int, 2> &a2, char op) {
	if (op == '+') {
		a[0] = min(a[0], a1[0] + a2[0]);
		a[1] = max(a[1], a1[1] + a2[1]);
	} else {
		a[0] = min(a[0], a1[0] - a2[1]);
		a[1] = max(a[1], a1[1] - a2[0]);
	}
}

T merge(T &v1, T &v2) {
	T v(v1.size() + v2.size(), { (int)1e9, -(int)1e9 });
	for (int i = 0; i < v1.size(); ++i)
		for (int j = 0; j < v2.size(); ++j)
			for (int k = 0; k < 2; ++k)
				update(v[i + j + k], v1[i], v2[j], O[k]);
	return v;
}

T f() {
	static int i = 0;
	if (E[i] != '(') {
		char c = E[i++] - '0';
		return{ {c, c} };
	}
	++i;
	auto v1 = f();
	++i;
	auto v2 = f();
	++i;
	return merge(v1, v2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> E;

	int P, M;
	cin >> P >> M;

	if (P < M)
		swap(O[0], O[1]);

	cout << f()[min(P, M)][1];
	return 0;
}