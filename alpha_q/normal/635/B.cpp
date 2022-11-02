#include <bits/stdc++.h>

using namespace std;

#define MAX 400005

vector <int> C, D;
int A[MAX], B[MAX], n, i, j;

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", A + i), A[n + i] = A[i];
	for (i = 1; i <= n; i++) scanf("%d", B + i), B[n + i] = B[i];
	
	for (i = 1; i <= n; i++) {
		if (A[i] == 1) {
			for (j = i; j < n + i; j++) 
				if (A[j]) C.push_back(A[j]);
			break;
		}
	}
	
	for (i = 1; i <= n; i++) {
		if (B[i] == 1) {
			for (j = i; j < n + i; j++) 
				if (B[j]) D.push_back(B[j]);
			break;
		}
	}
	
	for (i = 0; i < n - 1; i++)
		if (C[i] != D[i]) {
			puts("NO");
			return 0;
		}
	
	puts("YES");
	return 0;
}