#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];

int main() {
	scanf("%d%s", &N, s);
	sort(s, s + N);
	puts(s);	
	return 0;
}