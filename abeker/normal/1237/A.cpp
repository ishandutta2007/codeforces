#include <bits/stdc++.h>
using namespace std;

int down(int x) {
	if (x > 0)
		return x / 2;
	return -(abs(x) / 2 + 1);
}

int up(int x) {
	if (x > 0)
		return (x + 1) / 2;
	return -(abs(x) / 2);
}

int main() {
	int N;
	scanf("%d", &N);
	vector <int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	
	vector <int> odd;
	vector <int> ans(N);
	for (int i = 0; i < N; i++)
		if (a[i] % 2)
			odd.push_back(i);
		else
			ans[i] = a[i] / 2;
			
	int sz = odd.size();
	assert(!(sz % 2));
	for (int i = 0; i < sz / 2; i++)
		ans[odd[i]] = down(a[odd[i]]);
	for (int i = sz / 2; i < sz; i++)
		ans[odd[i]] = up(a[odd[i]]);
	
	long long sum = 0;
	for (auto it : ans) {
		printf("%d\n", it);
		sum += it;
	}
	assert(!sum);
	
	return 0;
}