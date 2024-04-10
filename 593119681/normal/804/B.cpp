#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000000 + 5
#define Mod 1000000007

int len, ans, cur, Pow[N];
char s[N];

inline int Inc(int a, int b)
{
	return a + b - (a + b >= Mod ? Mod : 0);
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	Pow[0] = 1;
	for (int i = 1; i < len; i ++)
		Pow[i] = Inc(Pow[i - 1], Pow[i - 1]);
	for (int i = 0; i < len; i ++)
	{
		if (s[i] == 'a') cur ++;
		else ans = Inc(ans, Pow[cur] - 1);
	}
	printf("%d\n", ans);
	return 0;
}