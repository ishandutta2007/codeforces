#include <bits/stdc++.h>
using namespace std;
char inp[100010];
int n;
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf(" %s", inp);
		n = strlen(inp);
		int am = 0;
		for (int i = 0; i < n; i++) {
			if (inp[i] == '0' && inp[i+1] != '0') {
				am++;
			}
		}
		printf("%d\n", min(am, 2));
	}
}