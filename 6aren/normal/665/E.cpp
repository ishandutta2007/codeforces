#include<bits/stdc++.h>
using namespace std;

struct Trie {
	int child[2], cnt[2];
	Trie() {
		memset(child, -1, sizeof(child));
		memset(cnt, 0, sizeof(cnt));
	}
};

Trie trie[30000000];
int nNode = 0, a[1000005];

bool bit(int i, int x) {
	return (x >> i) & 1;
}

void add(int x) {
	int cur = 0;
	for (int i = 31; i >= 0; i--) {
		int u = bit(i, x);
		if (trie[cur].child[u] == -1) {
			trie[cur].child[u] = ++nNode;
		}
		trie[cur].cnt[u]++;
		cur = trie[cur].child[u];
	}
}

void erase(int x) {
	int cur = 0;
	for (int i = 31; i >= 0; i--) {
		int u = bit(i, x);
		trie[cur].cnt[u]--;
		cur = trie[cur].child[u];
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	add(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] = a[i - 1] ^ a[i];
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int pos = 31; pos >= 0; pos--) {
			int u = bit(pos, a[i]);
			int v = bit(pos, k);
			if (v == 0) {
				res += trie[cur].cnt[1 - u];
				if (pos == 0) res += trie[cur].cnt[u];
				cur = trie[cur].child[u];
			} else {
				if (pos == 0) res += trie[cur].cnt[1 - u];
				cur = trie[cur].child[1 - u];
			}
			if (cur == -1) {
				break;
			}
		}
		add(a[i]);
	}
	cout << res << endl;
	return 0;
}