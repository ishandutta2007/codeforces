#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
multiset <int> X1, Y1, X2, Y2;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
		X1.insert(x1[i]);
		Y1.insert(y1[i]);
		X2.insert(x2[i]);
		Y2.insert(y2[i]);
	}
	
	for (int i = 0; i < N; i++) {
		X1.erase(X1.find(x1[i]));
		Y1.erase(Y1.find(y1[i]));
		X2.erase(X2.find(x2[i]));
		Y2.erase(Y2.find(y2[i]));
		
		int lox = *X1.rbegin(), hix = *X2.begin();
		int loy = *Y1.rbegin(), hiy = *Y2.begin();
		
		if (lox <= hix && loy <= hiy) {
			printf("%d %d\n", lox, loy);
			return 0;
		}
		
		X1.insert(x1[i]);
		Y1.insert(y1[i]);
		X2.insert(x2[i]);
		Y2.insert(y2[i]);
	}
	
	return 0;
}