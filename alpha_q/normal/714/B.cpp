#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, x;
set <int> s;
vector <int> v;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &x), s.insert(x); 

	int m = s.size();
	
	if (m > 3) {
		puts("NO");
		return 0;
	}

	if (m < 3) {
		puts("YES");
		return 0;
	}

	for (int z : s) v.push_back(z);

	if (v[0] + v[2] == v[1] + v[1]) puts("YES");
	else puts("NO");
	return 0;
}