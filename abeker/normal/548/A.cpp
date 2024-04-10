#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1005;

int N, K;
char s[MAXN];

void load() {
	scanf("%s%d", s, &K);
}

bool check(string x) {
	string y = x;
	reverse(x.begin(), x.end());
	return x == y;
}

bool solve() {
	N = strlen(s);
	if (N % K) return false;
	N /= K;
	string str = s;
	for (int i = 0; i < K; i++)
		if (!check(str.substr(i * N, N)))  
			return false;
	return true;
}

int main() {
	load();
	puts(solve() ? "YES" : "NO");
	return 0;
}