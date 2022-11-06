#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

void operator delete(void*) {}

int a[1000001];
int ans[1000001];
int num[1000001];

int main() {
//	ios_base::sync_with_stdio(0);
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	memset(num, -1, sizeof(num));
	for (int i = 0; i < n; i++)
		ans[i] = 1, num[a[i]] = i;
	
	for (int i = 0; i < n; i++) {
		for (int j = 2 * a[i]; j <= (int) 1e6; j += a[i])
			if (num[j] != -1)
				ans[num[j]] = max(ans[num[j]], ans[i] + 1);
	}
	
	int answer = 0;
	for (int i = 0; i < n; i++)
		answer = max(answer, ans[i]);
	
	cout << answer << endl;
	
	return 0;
}