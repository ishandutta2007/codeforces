#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 105;

int N, K;
string s[MAXN];
string pass;

int calc(int x) {
	return x + (x - 1) / K * 5;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		cin >> s[i];
	cin >> pass;
	
	int a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].size() < pass.size()) a++;
		if (s[i].size() <= pass.size()) b++;
	}
	
	printf("%d %d\n", calc(a + 1), calc(b));
	
	return 0;
}