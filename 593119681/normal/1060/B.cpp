#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100 + 5

int n, sum;
LL v, x;
char s[N];
bool all_9 = true;

int main()
{
	scanf("%s", s);
	for (n = 0; s[n]; n ++)
	{
		if (n) x = x * 10 + 9, sum += 9;
		v = v * 10 + s[n] - '0';
	}
	for (LL i = v - x; i; i /= 10)
		sum += i % 10;
	printf("%d\n", sum);
	return 0;
}