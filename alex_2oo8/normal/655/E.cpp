#include<bits/stdc++.h>

using namespace std;

const int MX = 2000000, md = 1000000007;

char s[MX];
int last[26], cnt[26];

int main() {
	int n, k;
	scanf("%d %d %s", &n, &k, s);
	
	for (int i = 0; i < k; i++) last[i] = -1;
	
	int m = strlen(s);
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (char c = 'a'; c < 'a' + k; c++) {
			sum += cnt[c - 'a'];
			if (sum >= md) sum -= md;
		}
		
		cnt[s[i] - 'a'] = sum + 1;
		last[s[i] - 'a'] = i;
	}
	
	for (int i = m; i < m + n; i++) {
		char c = 'a';
		int sum = 0;
		for (char x = 'a'; x < 'a' + k; x++) {
			sum += cnt[x - 'a'];
			if (sum >= md) sum -= md;
			
			if (last[x - 'a'] < last[c - 'a']) c = x;
		}
		
		s[i] = c;
		
		cnt[s[i] - 'a'] = sum + 1;
		last[s[i] - 'a'] = i;
	}
	
	int sum = 1;
	for (char c = 'a'; c < 'a' + k; c++) {
		sum += cnt[c - 'a'];
		if (sum >= md) sum -= md;
	}
	
	printf("%d\n", sum);
	
	return 0;
}