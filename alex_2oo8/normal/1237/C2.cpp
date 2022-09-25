#include <bits/stdc++.h>

using namespace std;

const int MX = 50000;

int x[MX], y[MX], z[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d %d %d", x + i, y + i, z + i);
	
	auto comp = [](int a, int b) {
		if (x[a] != x[b]) return x[a] < x[b];
		if (y[a] != y[b]) return y[a] < y[b];
		if (z[a] != z[b]) return z[a] < z[b];
		return false;
	};
	
	vector<int> vec(n);
	iota(vec.begin(), vec.end(), 0);
	sort(vec.begin(), vec.end(), comp);
	
	int it = 0;
	for (int i = 0; i < n; i++) {
		if (it > 0 &&
		    x[vec[it - 1]] == x[vec[i]] &&
		    y[vec[it - 1]] == y[vec[i]]) {
			printf("%d %d\n", vec[it - 1] + 1, vec[i] + 1);
			it--;
		}
		else {
			vec[it++] = vec[i];
		}
	}
	
	n = it;
	it = 0;
	
	for (int i = 0; i < n; i++) {
		if (it > 0 && x[vec[it - 1]] == x[vec[i]]) {
			printf("%d %d\n", vec[it - 1] + 1, vec[i] + 1);
			it--;
		}
		else {
			vec[it++] = vec[i];
		}
	}
	
	n = it;
	it = 0;
	
	for (int i = 0; i < n; i++) {
		if (it > 0) {
			printf("%d %d\n", vec[it - 1] + 1, vec[i] + 1);
			it--;
		}
		else {
			vec[it++] = vec[i];
		}
	}
	
	return 0;
}