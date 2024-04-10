#include <bits/stdc++.h>
 
using namespace std;

const int N = 2e5 + 10;

char s[N];
int n, pos, res = 0; 

int main (int argc, char const *argv[]) {
	scanf("%d %s", &n, s + 1);

	pos = 1;
	while (pos <= n and s[pos] == '<') ++pos;
	res += (pos - 1);

	pos = 1;
	while (pos <= n and s[n + 1 - pos] == '>') ++pos;
	res += (pos - 1);

	printf("%d\n", res); 
	return 0;
}