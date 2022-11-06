#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1001

char s[N], t[N];

void Prepare()
{
	for (int i = 0; i < N; i ++)
	{
		s[i] = (i & 1) ? '0' : '9';
		if (i) t[i] = (i & 1) ? '9' : (i == 1000 ? '1' : '0');
	}
}

int main()
{
	Prepare();
	scanf("%*d%*d");
	printf("%s\n%s\n", s, t + 1);
	return 0;
}