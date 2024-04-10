#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 50005;

int N;
char buff[MAXN];
string s[MAXN];

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", buff);
		s[i] = buff;
	}
	sort(s, s + N, cmp);
	for (int i = 0; i < N; i++)
		printf("%s", s[i].c_str());
	puts("");
	return 0;
}