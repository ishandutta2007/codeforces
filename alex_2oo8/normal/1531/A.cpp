#include <bits/stdc++.h>

using namespace std;

char s[42];

int main() {
	string ans = "blue";
	
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, b = 0; i < n; i++) {
		ignore = scanf("%s", s);
		
		string q = s;
		if (q == "lock") b = 1;
		else if (q == "unlock") b = 0;
		else if (b == 0) {
			ans = q;
		}
	}
	
	printf("%s\n", ans.c_str());
	
	return 0;
}