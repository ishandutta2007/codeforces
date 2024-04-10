#include <bits/stdc++.h>

using namespace std;

const int MAX = 1050;

int N, X[MAX], Y[MAX], Ret = 0;

int main() {	
	//freopen("input.txt", "r", stdin);
	
	scanf("%d", &N); 
	for (int i = 1; i <= N; i++) scanf("%d %d", X + i, Y + i);
	X[N + 1] = X[1], Y[N + 1] = Y[1];
	X[N + 2] = X[2], Y[N + 2] = Y[2];

	for (int i = 1; i <= N; i++) {
		int CCW = (X[i + 1] - X[i]) * (Y[i + 2] - Y[i]) - (Y[i + 1] - Y[i]) * (X[i + 2] - X[i]);
		Ret += (CCW > 0);
	}

	printf("%d\n", Ret);
    return 0;
}