#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s, t, i; 
	char S[10000]; scanf("%d %s", &n, S);
	
	for (i = 0; i < n; i++) 
		if (S[i] != '.') {s = i; break;}
	for (i = n - 1; i >= 0; i--) 
		if (S[i] != '.') {t = i; break;}
	
	if (S[s] == 'L' && S[t] == 'L') {
		printf("%d %d\n", t + 1, s);
		return 0;
	}
	
	if (S[s] == 'R' && S[t] == 'R') {
		printf("%d %d\n", s + 1, t + 2);
		return 0;
	}
	
	if (S[s] == 'R' && S[t] == 'L') {
		while (S[t] == 'L') t--;
		printf("%d %d\n", s + 1, t + 1);
		return 0;
	}
	return 0;
}