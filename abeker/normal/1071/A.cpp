#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A, B;
vector <int> a, b;

bool check(int val) {
	a.clear();
	b.clear();
	ll sum = A, rest = 0;
	for (int i = val; i; i--)
		if (sum >= i) {
			a.push_back(i);
			sum -= i;
		}
		else {
			rest += i;
			b.push_back(i);
		}
	return rest <= B;	
}

void output(vector <int> v) {
	printf("%d\n", v.size());
	for (auto it : v)
		printf("%d ", it);
	puts("");
}

int main() {
	scanf("%d%d", &A, &B);
	
	int lo = 0, hi = 1e5;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	
	check(lo);
	
	output(a);
	output(b);
	
	return 0;
}