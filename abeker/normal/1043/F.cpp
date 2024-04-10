#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int MAXP = 9;

int N;
int cnt[MAXN];
int p[MAXN];
vector <pii> sqfree;
int choose[MAXN][MAXP];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

bool test(int k) {
	int tot = 0;
	for (auto it : sqfree)
		tot = add(tot, it.second ? -choose[it.first][k] : choose[it.first][k]);
	return tot;
}

int solve() {
	choose[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		choose[i][0] = 1;
		for (int j = 1; j < MAXP; j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
	
	for (int i = 1; i < MAXN; i++)
		for (int j = 2 * i; j < MAXN; j += i)
			cnt[i] += cnt[j];
			
	for (int i = 2; i < MAXN; i++)
		if (!p[i])
			for (int j = i; j < MAXN; j += i)
				if (!p[j])
					p[j] = i;
	
	for (int i = 1; i < MAXN; i++) {
		int x = i, c = 0;
		while (x > 1) {
			int tmp = p[x], ex = 0;
			for (; !(x % tmp); x /= tmp)
				ex++;
			if (ex > 1) {
				c = -1;
				break;
			}
			c ^= 1;
		}
		if (c != -1)
			sqfree.push_back({cnt[i], c});
	}
	
	for (int i = 1; i < MAXP; i++)
		if (test(i))
			return i;
	
	return -1;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}