#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
int a[MAXN];

bool test(int k) {
	for (int i = k + 1; i <= N; i++)
		if (a[i] != a[i - k])
			return false;
	return true;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	
	for (int i = N; i; i--)
		a[i] -= a[i - 1];
	
	vector <int> ans;
	for (int i = 1; i <= N; i++)
		if (test(i))
			ans.push_back(i);
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d ", it);
	puts("");
	
	return 0;
}