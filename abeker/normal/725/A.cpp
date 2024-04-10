#include <cstdio>
using namespace std;

const int MAXN = 200005;

int N;
char s[MAXN];

int main() {
	scanf("%d%s", &N, s);
	
	int i = 0;
	for (; i < N && s[i] == '<'; i++);
	
	int j = N - 1; 
	for (; j >= 0 && s[j] == '>'; j--);
	
	printf("%d\n", i + N - j - 1);
	
	return 0;
}