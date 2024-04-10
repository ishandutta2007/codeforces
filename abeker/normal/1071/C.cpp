#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct triple {
	int x, y, z;
};

int N;
int a[MAXN];
vector <int> v[15];
vector <triple> ans;
int id1[MAXN], id2[MAXN];
int dad[1 << 15];
queue <int> Q;

void init() {
	for (int n = 1; n < 15; n++)
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (k - j == j - i)	
						v[n].push_back((1 << i) | (1 << j) | (1 << k));
	
	for (int i = 0; i < 1 << 6; i++)
		for (int k = 0; k < v[13].size(); k++)
			for (int l = 0; l < v[13].size(); l++)
				if (!((i ^ v[13][k] ^ v[13][l]) & 63)) {
					id1[i] = v[13][k];
					id2[i] = v[13][l];
				}
}

void apply(int x, int y, int z) {
	ans.push_back({x, y, z});
	a[x] ^= 1;
	a[y] ^= 1;
	a[z] ^= 1;
}

triple get(int mask) {
	vector <int> res;
	for (int i = 0; i < 13; i++)
		if (mask >> i & 1)
			res.push_back(i);
	return {res[0], res[1], res[2]};
}

int main() {
	init();
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
		
	int pos = 0;
	for (; pos < N - 13; pos += 6) {
		int tmp = 0;
		for (int j = 0; j < 6; j++)
			if (a[pos + j])
				tmp |= 1 << j;
		triple t1 = get(id1[tmp]);
		triple t2 = get(id2[tmp]);
		apply(pos + t1.x, pos + t1.y, pos + t1.z);
		apply(pos + t2.x, pos + t2.y, pos + t2.z);
	}
	
	int rest = 0;
	for (int i = pos; i < N; i++)
		if (a[i])
			rest |= 1 << i - pos;
	
	memset(dad, -1, sizeof dad);
	dad[rest] = rest;
	Q.push(rest);
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		for (auto it : v[N - pos]) {
			int nxt = curr ^ it;
			if (dad[nxt] == -1) {
				Q.push(nxt);
				dad[nxt] = curr;
			}
		}
	}
	
	if (dad[0] == -1) {
		puts("NO");
		return 0;
	}
	
	for (int x = 0; x != rest; x = dad[x]) {
		triple t = get(x ^ dad[x]);
		apply(pos + t.x, pos + t.y, pos + t.z);
	}
	
	for (int i = 0; i < N; i++)
		assert(!a[i]);
	
	puts("YES");
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d %d %d\n", it.x + 1, it.y + 1, it.z + 1);
	
	return 0;
}