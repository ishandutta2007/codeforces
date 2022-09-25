#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

char s[MX + 1];

int main() {
	ignore = scanf("%s", s);
	int n = strlen(s);
	
	vector<int> L, R;
	for (int l = 0, r = n - 1; l < r; l++, r--) {
		while (l < r && s[l] != '(') l++;
		while (l < r && s[r] != ')') r--;
		
		if (l < r) {
			L.push_back(l);
			R.push_back(r);
		}
	}
	
	if (L.empty()) {
		printf("%d\n", 0);
		return 0;
	}
	
	reverse(R.begin(), R.end());
	
	printf("1\n%zu\n", 2 * L.size());
	for (int x : L) printf("%d ", x + 1);
	for (int x : R) printf("%d ", x + 1);
	printf("\n");
	
	return 0;
}