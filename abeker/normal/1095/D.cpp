#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];

bool check(int x, int y, int z, int w) {
	return min(x, y) == min(z, w) && max(x, y) == max(z, w);
}

void go(int nxt1, int nxt2) {
	vector <int> ans;
	ans.push_back(1);
	ans.push_back(nxt1);
	int curr = nxt2;
	int prv = nxt1;
	for (int i = 0; i < N - 2; i++) {
		ans.push_back(curr);
		int nxt = a[prv] ^ b[prv] ^ curr;
		if (nxt < 1 || nxt > N)
			return;
		prv = curr;
		curr = nxt;
	}
	
	bool ok = true;
	for (int i = 0; i < N; i++)
		ok &= check(ans[(i + 1) % N], ans[(i + 2) % N], a[ans[i]], b[ans[i]]);
	
	if (ok) {
		for (auto it : ans)
			printf("%d ", it);
		puts("");
		exit(0);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", a + i, b + i);
	
	go(a[1], b[1]);
	go(b[1], a[1]);
	
	return 0;
}