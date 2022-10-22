#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 100500;
char theString[maxN];

int prefixType[maxN][3];

int main()
{
	#ifdef LOCAL
	freopen ("a.in", "r", stdin);
	#endif
	
	scanf ("%s", theString);
	int length = strlen (theString);
	
	for (int i = 1; i <= length; i++)
		for (int type = 0; type < 3; type++)
			prefixType[i][type] = prefixType[i - 1][type] + (type == (theString[i - 1] - 'x'));
		
	int nQueries;
	scanf ("%d", &nQueries);
	
	for (int i = 0; i < nQueries; i++)
	{
		int l, r;
		scanf ("%d %d", &l, &r);
		
		int a = prefixType[r][0] - prefixType[l - 1][0];
		int b = prefixType[r][1] - prefixType[l - 1][1];
		int c = prefixType[r][2] - prefixType[l - 1][2];
		
		bool answer = ((max (max (a, b), c) - min (min (a, b), c)) <= 1) || (r - l <= 1);
		printf ("%s\n", answer ? "YES" : "NO");
	}
	
	return 0;
}