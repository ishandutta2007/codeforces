#include<bits/stdc++.h>

using namespace std;

char s[2000000];
int start, dp[10000];

struct {
	int start, next[26];
} t[1100000];

int newNode() {
	static int tw = 0;
	
	return ++tw;
}

void trie_add(int start) {
	int v = 0;
	for (int i = start; s[i]; i++) {
		int c = s[i] <= 'Z' ? s[i] - 'A' : s[i] - 'a';
		if (t[v].next[c] == 0) t[v].next[c] = newNode();
		
		v = t[v].next[c];
	}
	
	t[v].start = start;
}

void f(int n) {
	if (n < 0) return;
	
	f(n - strlen(s + dp[n]));

	printf("%s ", s + dp[n]);
}

int main() {
	int n, m;
	scanf("%d %s %d", &n, s, &m);
	
	start = n + 1;
	for (int i = 0; i < m; i++) {
		scanf("%s", s + start);
		
		trie_add(start);
		
		start += strlen(s + start) + 1;
	}
	
	for (int i = 0; i < n; i++) {
		int v = 0;
		for (int j = i; j >= 0; j--) {
			v = t[v].next[s[j] - 'a'];
			if (v == 0) break;
			if (t[v].start != 0 && (j == 0 || dp[j - 1] != 0)) {
				dp[i] = t[v].start;
				
				break;
			}
		}
	}
	
	f(n - 1);
	printf("\n");
	
	return 0;
}