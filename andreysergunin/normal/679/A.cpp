#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex> 
#include <ctime>
#include <cstring>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < sz(p); ++i) {
		printf("%d\n", p[i]);
		fflush(stdout);

		char s[4];
		scanf("%s", s);
		if (strcmp(s, "yes") == 0) {
			for (int j = i; j < sz(p) && p[i] * p[j] <= 100; ++j) {
				printf("%d\n", p[i] * p[j]);
				fflush(stdout);

				char s[4];
				scanf("%s", s);
				if (strcmp(s, "yes") == 0) {
					printf("composite\n");
					return 0;
				}
			}
			printf("prime\n");
			return 0;
		}
	}
	printf("prime\n");
	return 0;
}