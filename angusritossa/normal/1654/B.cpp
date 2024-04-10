#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int t;
int occ[200];
char str[200010];
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf(" %s", str);
		int len = strlen(str);
		fill_n(occ, 200, 0);
		for (int i = 0; i < len; i++) {
			occ[str[i]]++;
		}
		for (int i = 0; i < len; i++) {
			if (occ[str[i]] == 1) {
				printf("%s\n", str+i);
				break;
			} else {
				occ[str[i]]--;
			}
		}
	}
}