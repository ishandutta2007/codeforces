#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, x, y;
vector <int> one;

int ask(vector <int> p) {
	printf("? %d", p.size());
	for (auto it : p)
		printf(" %d", it + 1);
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans && ans != x;	
}

void load() {
	scanf("%d%d%d", &N, &x, &y);
}

void solve() {
	int mask = 0;
	for (int i = 0; i < 10; i++) {
		vector <int> tmp, other;
		for (int j = 0; j < N; j++)
			if (j >> i & 1)
				tmp.push_back(j);
			else
			 	other.push_back(j);
		if (tmp.empty())
			continue;
		if (ask(tmp)) {
			mask ^= 1 << i;
			one = tmp.size() < other.size() ? tmp : other;	 
		}
	}
	
	int lo = 1, hi = one.size() + 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		vector <int> tmp;
		for (int i = 0; i < mid; i++)
			tmp.push_back(one[i]);
		if (ask(tmp))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	int p1 = one[lo - 1], p2 = one[lo - 1] ^ mask;
	if (p1 > p2)
		swap(p1, p2);
	printf("! %d %d\n", ++p1, ++p2);
	fflush(stdout);
}

int main() {
	load();
	solve();
	return 0;
}