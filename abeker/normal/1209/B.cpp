#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int N;
char s[MAX];
int cnt[MAX];

int main() {
	scanf("%d%s", &N, s);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int curr = s[i] - '0';
		for (int j = 0; j < MAX; j++) {
			cnt[j] += curr;
			if (j >= b && j % a == b % a)
				curr ^= 1;
		}
	}
	
	printf("%d\n", *max_element(cnt, cnt + MAX));
	
	return 0;
}