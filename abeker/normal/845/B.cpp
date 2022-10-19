#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int diff(string x, int a, int b, int c) {
	int res = 0;
	res += (x[0] - '0' != a);
	res += (x[1] - '0' != b);
	res += (x[2] - '0' != c);
	return res;
}

int main() {
	string s;
	cin >> s;
	
	string left = s.substr(0, 3), right = s.substr(3, 3);

	int sol = 10;	
	for (int t = 0; t < 30; t++) {
		int a = 10, b = 10;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					if (i + j + k == t) {
						a = min(a, diff(left, i, j, k));
						b = min(b, diff(right, i, j, k));
					}
		sol = min(sol, a + b);
	}
	
	printf("%d\n", sol);
	
	return 0;
}