#include<bits/stdc++.h>

using namespace std;

char s[1 << 9][(1 << 9) + 1];

int main() {
	int k;
	scanf("%d", &k);
	
	s[0][0] = '+';
	for (int i = 0; i < k; i++) {
		int p = 1 << i;
		for (int j = 0; j < p; j++)
			for (int k = 0; k < p; k++) {
				s[j][k + p] = s[j][k];
				s[j + p][k] = s[j][k];
				s[j + p][k + p] = '+' + '*' - s[j][k];
			}
	}
	
	for (int i = 0; i < (1 << k); i++) {
		s[i][1 << k] = 0;
		
		printf("%s\n", s[i]);
	}
	
	return 0;
}