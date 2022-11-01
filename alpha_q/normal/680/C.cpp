#include <bits/stdc++.h>

using namespace std;

int tot;
string str;
vector <int> V;
int pr[22] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

int main (int argc, char const *argv[]) {
	V.clear();
	for (int i = 0; i < 15; ++i) {
		printf("%d\n", pr[i]);
		fflush(stdout);
		cin >> str;
		if (str == "yes") ++tot, V.push_back(pr[i]);
	}

	if (tot >= 2) {
		printf("composite\n");
	} else {
		for (int i = 0; i < min(5, (int) V.size()); ++i) {
			if (V[i] * V[i] <= 100) {
				printf("%d\n", V[i] * V[i]);
				fflush(stdout);
				cin >> str;
				if (str == "yes") ++tot;
			}
		}
		if (tot >= 2) printf("composite\n");
		else printf("prime\n");
	}
	return 0;
}