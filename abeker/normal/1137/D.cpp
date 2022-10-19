#include <bits/stdc++.h>
using namespace std;

bool go(vector <int> v) {
	printf("next ");
	for (auto it : v)
		printf("%d ", it);
	puts("");
	fflush(stdout);
	int k;
	scanf("%d", &k);
	if (k == 1) {
		puts("done");
		fflush(stdout);
		exit(0);
	}
	bool ok = false;
	while (k--) {
		string s;
		cin >> s;
		bool zero = false, one = false;
		for (auto it : s) {
			if (it == '0')
				zero = true;
			if (it == '1')
				one = true;
		}
		ok |= zero && one;
	}
	return ok;
}

int main() {
	while (1) {
		go({0, 1});
		go({0, 1});
		if (go({0}))
			break;
	}
	
	while (1) 
		go({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	
	return 0;
}