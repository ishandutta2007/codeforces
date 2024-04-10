#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define MAXN 2000005

using namespace std;

int main ()
{
	int N, Q;
	scanf("%d %d",&N,&Q);
	static int s[MAXN];
	int sc = 1;
	s[0] = -1;
	int i;
	int pos = 0;
	for (i = 0; i < Q; i++)
	{
		int t;
		scanf("%d",&t);
		if (t == 1)
		{
			int delta;
			scanf("%d",&delta);
			pos = (pos + delta + N + N) % N;
		}
		else
		{
			int cur = pos % 2;
			if (s[sc-1] == cur)
			{
				sc--;
			}
			else
			{
				s[sc] = cur;
				sc++;
			}
		}
	}
	int ind;
	if (sc == 1) ind = 0;
	else if (s[1] == 0) ind = (sc-1) % N;
	else ind = (N - ((sc-1) % N) + N) % N;

	//printf("sc = %d\n",sc);
	//printf("ind = %d\n",ind);

	static int p[MAXN];
	static int res[MAXN];
	for (i = 0; i < N; i++)
	{
		if ((i % 2) == 0)
		{
			p[(i + ind) % N] = i;
		}
		else
		{
			p[(i - ind + N) % N] = i;
		}
	}
	for (i = 0; i < N; i++)
	{
		res[i] = p[(i - pos + N) % N];
	}
	for (i = 0; i < N; i++)
	{
		if (i) printf(" ");
		printf("%d",res[i] + 1);
	}
	printf("\n");
	return 0;
}