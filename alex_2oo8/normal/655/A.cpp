#include<bits/stdc++.h>

using namespace std;

char s[4][4];

void f(int offset) {
	if (s[offset + 1][1] == 'X') swap(s[offset + 1][1], s[offset][1]);
	if (s[offset + 1][0] == 'X') swap(s[offset + 1][0], s[offset][0]);
	if (s[offset][1] == 'X') swap(s[offset][1], s[offset][0]);
}

int main() {
	for (int i = 0; i < 4; i++) scanf("%s", s[i]);
	
	f(0);
	f(2);
	
	for (int i = 0; i < 42; i++) {
		swap(s[0][0], s[0][1]);
		swap(s[0][1], s[1][1]);
		swap(s[1][1], s[1][0]);
		swap(s[1][0], s[0][0]);
		
		if (s[0][1] == s[2][1] && s[1][0] == s[3][0]) {
			printf("YES\n");
			
			return 0;
		}
	}
	printf("NO\n");
	
	return 0;
}