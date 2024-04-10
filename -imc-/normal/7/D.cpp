#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 5000005;

int p[maxN];
char s[maxN];
int N;

const int hashP = 31, hashModule = 1000000009;
long long pPowered[maxN];
int prefixHash[maxN];
int suffixHash[maxN];

long long xmod (long long t)
{
	return t > 0 ? t % hashModule : (hashModule - (-t) % hashModule) % hashModule;
}

int main()
{
	scanf ("%s", s);
	N = strlen (s);

	pPowered[0] = 1;
	for (int i = 1; i < maxN; i++)
		pPowered[i] = (pPowered[i - 1] * hashP) % hashModule;

	prefixHash[0] = 0;
	suffixHash[N] = 0;

	for (int i = N - 1; i >= 0; i--)
		suffixHash[i] = (suffixHash[i + 1] + s[i] * pPowered[N - i - 1]) % hashModule;

	for (int i = 1; i <= N; i++)
		prefixHash[i] = (prefixHash[i - 1] + pPowered[i - 1] * s[i - 1]) % hashModule;

	p[0] = 0;
	long long answer = 0;

	for (int i = 1; i <= N; i++)
	{
		int half = i / 2;
		if ((p[half] || half == 0) && (prefixHash[half] * pPowered[i - half] % hashModule) == xmod (prefixHash[i] - prefixHash[i - half]))
		{
			p[i] = p[half] + 1;
			//printf ("i=%i match: %.*s, %.*s: %.*s has power %i\n", i, half, s, half, s + i - half, i, s, p[i]);
		}
		else if (xmod (prefixHash[i] * pPowered[N - i]) == xmod (suffixHash[0] - suffixHash[i]))
		{
			//printf ("standalone palyndrome %.*s: power %i\n", i, s, 1);
			p[i] = 1;
		}
		else
		{
			//printf ("not equal %.*s %.*s\n", half, s, half, s + i - half);
			p[i] = 0;
		}

		answer += p[i];
	}

	cout << answer << endl;

	return 0;
}