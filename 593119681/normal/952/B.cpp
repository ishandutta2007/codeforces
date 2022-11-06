#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 99

bool ok = 0;
char s[N];

void PrintNormal()
{
	puts("normal");
	exit(0);
}

void PrintGrumpy()
{
	puts("grumpy");
	exit(0);
}

int main()
{
	for (int i = 0; i < 10; i ++)
	{
		printf("%d\n", i);
		fflush(stdout);
		fgets(s, N, stdin);
		if (s[0] == 'g' && s[1] == 'r') PrintNormal();
		if (s[0] == 'c' && s[1] == 'o') PrintNormal();
		if (s[2] == 't' && s[4] == 'b') PrintNormal();
		if (s[6] == 't' && s[7] == 'o') PrintNormal();
		if (s[6] == 't' && s[7] == 'h') PrintNormal();
		if (s[6] == 'e' && s[7] == 'v') PrintGrumpy();
		if (s[6] == ' ' && s[7] == 'i') PrintGrumpy();
		if (s[0] == 'w' && s[1] == 'o') PrintGrumpy();
		if (s[0] == 't' && s[1] == 'e') PrintGrumpy();
		if (s[0] == 'a' && s[1] == 'r') PrintGrumpy();
		if (s[2] == ' ' && s[3] == 'w') PrintGrumpy();
	}
}