#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
map <ll, int> lst, prv;

int main() {
	scanf("%d", &N);
	
	int mx = -1;
	ll sol = 0, sum = 0;
	lst[0] = 0;
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		int pos = lst.find(sum) == lst.end() ? -1 : lst[sum];
		prv[sum] = pos;
		lst[sum] = i;
		mx = max(mx, pos);
		sol += i - mx - 1;
	}
	
	printf("%lld\n", sol);
	
	return 0;
}