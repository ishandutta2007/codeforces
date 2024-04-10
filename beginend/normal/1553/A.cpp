#include<bits/stdc++.h>
using namespace std;

int po(int x, int y)
{
	int ans = 0;
	while (y) ans *= x, y--;
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", (n + 1) / 10);
	}
	return 0;
}