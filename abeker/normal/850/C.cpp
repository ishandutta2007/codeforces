#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

int N;
map <int, int> mask;
unordered_map <int, int> dp, was;

void load() {
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		for (int i = 2; i * i <= x; i++) {
			if (x % i)
				continue;
			int tmp = 0;
			for (; !(x % i); x /= i)
				tmp++;
			mask[i] |= 1 << tmp - 1;
		}
		if (x > 1)
			mask[x] |= 1;
	}
}

int grundy(int mask) {
	int &ref = dp[mask];
	if (was[mask])
		return ref;
	
	was[mask] = 1;
	
	vector <int> pos;
	for (int i = 0; i < 30; i++)
		if (mask >> i & 1)
			pos.push_back(i + 1);
	
	bool bio[35] = {0};
	for (int i = 1; i <= 30; i++) {
		int curr = mask;
		for (auto it : pos)
			if (it >= i) 
				curr ^= 1 << it - 1;
		for (auto it : pos)
			if (it > i)
				curr |= 1 << it - i - 1;
		if (curr != mask)
			bio[grundy(curr)] = true;
	}
	
	for (ref = 0; bio[ref]; ref++);
	
	return ref;
}

int solve() {
	dp[0] = 0;
	was[0] = 1;
	
	int sol = 0;
	for (auto it : mask)
		sol ^= grundy(it.second);
	
	/*for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 6; j++)
			if (i >> j & 1)
				printf("%d ", j + 1);
		printf("-> %d\n", grundy(i));
	}*/
	
	//for (int i = 4; i <= 20; i++)
	//	printf("grundy %d %d %d\n", 3, i, grundy((1 << i - 1) + 4));

	return sol;
}

int main() {
	load();
	puts(solve() ? "Mojtaba" : "Arpa");
	return 0;
}