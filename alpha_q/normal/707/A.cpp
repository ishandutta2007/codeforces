#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	int n, m; cin >> n >> m;
	bool colored = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == 'C' or c == 'M' or c == 'Y') 
				colored = 1;
		}
	if (colored) printf("#Color\n");
	else printf("#Black&White\n");
	return 0;
}