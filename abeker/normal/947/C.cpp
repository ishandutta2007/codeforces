#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int MAXB = 30;

int N;
int a[MAXN];
int trie[MAXN * MAXB][2];
int dad[MAXN * MAXB], cnt[MAXN * MAXB];
map <int, int> node;
int sz = 1;

void insert(int curr, int bit, int val) {
  cnt[curr]++;
  if (bit == -1) {
    node[val] = curr;
    return;
  }
  int tmp = val >> bit & 1;
  if (trie[curr][tmp] == -1) {
    trie[curr][tmp] = sz++;
    dad[trie[curr][tmp]] = curr;
  }
  insert(trie[curr][tmp], bit - 1, val);
}

void erase(int curr, int val) {
  cnt[curr]--;
  if (!curr) 
		return;
  if (!cnt[curr]) 
		trie[dad[curr]][val % 2] = -1;
  erase(dad[curr], val / 2);
}

int query(int curr, int bit, int val) {
  if (bit == -1) 
		return 0;
  int tmp = val >> bit & 1;
  if (trie[curr][tmp] == -1) 
    return (query(trie[curr][tmp ^ 1], bit - 1, val) | (1 << bit));
  return query(trie[curr][tmp], bit - 1, val);
}

int main() {
	memset(trie, -1, sizeof trie);
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);	
	for (int i = 0; i < N; i++) {
		int p;
		scanf("%d", &p);
		insert(0, MAXB, p);
	}
	
	for (int i = 0; i < N; i++) {
		int ans = query(0, MAXB, a[i]);
		printf("%d ", ans);
		erase(node[ans ^ a[i]], ans ^ a[i]);
	}
	puts("");
	
	return 0;
}