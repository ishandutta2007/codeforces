#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000005;

int n, a[N], p[N], trie[N][2], ptr, tot[N];

void insert (int x) {
	int u = 0;
	for (int i = 29; i >= 0; --i) {
		int bit = (x >> i) & 1;
		int &nxt = trie[u][bit];
		if (nxt == -1) nxt = ++ptr;
		u = nxt;
	}
	++tot[u];
}

stack <int> st;

int get (int x) {
	while (!st.empty()) st.pop();
	int u = 0, ans = 0;
	for (int i = 29; i >= 0; --i) {
		st.push(u);
		int bit = (x >> i) & 1;
		int nxt = trie[u][bit];
		if (nxt == -1) {
			nxt = trie[u][bit ^ 1];
			ans |= 1 << i;
		}
		u = nxt;
	}
	// cout << u << endl;
	--tot[u];
	int at, ch = u;
	if (tot[u] == 0) {
		while (!st.empty()) {
			at = st.top();
			st.pop();
			if (trie[at][0] == -1 or trie[at][1] == -1) {
				trie[at][0] = trie[at][1] = -1;
			} else {
				if (trie[at][0] == ch) trie[at][0] = -1;
				else trie[at][1] = -1;
				break;
			}
			ch = at;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	memset(trie, -1, sizeof trie);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
		insert(p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", get(a[i]));
	}
	puts("");
	return 0;
}