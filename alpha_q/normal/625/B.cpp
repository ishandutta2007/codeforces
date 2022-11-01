#include <bits/stdc++.h>

using namespace std;

int main () {
	string A, B; cin >> A >> B;
	int Ret = 0, i, j, a = A.length(), b = B.length();
	for (i = 0; i < a; i++) 
		if (A[i] == B[0]) 
			if (A.substr(i, b) == B) 
				Ret++, i += (b - 1);
	printf ("%d\n", Ret);
	return 0;
}