#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 1005;
char a[maxN], b[maxN];

int count (char* x)
{
	int l = strlen (x);
	int nOnes = 0;
	for (int i = 0; i < l; i++)
		if (x[i] == '1')
			nOnes++;

	return nOnes;
}

int main()
{
	scanf ("%s %s", a, b);
	int aOnes = count (a), bOnes = count (b);

	int m = aOnes % 2 ? aOnes + 1 : aOnes;
	printf ("%s\n", m >= bOnes ? "YES" : "NO");

	return 0;
}