#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, A = 0, B = 0; char a[1002], b[1002];
	scanf ("%s", a); scanf ("%s", b);
	
	for (i = 0; i < strlen(a); i++) 
		if (a[i] == '1') A++;
	for (i = 0; i < strlen(b); i++) 
		if (b[i] == '1') B++;
	
	printf("%s\n", A + (A % 2) >= B ? "YES" : "NO");
	return 0;
}