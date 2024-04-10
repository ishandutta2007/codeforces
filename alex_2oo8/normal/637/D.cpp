#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 200005

using namespace std;

struct node
{
	char t;
	int l;
};

int main ()
{
	int N, M, S, D;
	scanf("%d %d %d %d",&N,&M,&S,&D);
	int i, j;
	N++;
	static int x[MAXN];
	x[0] = -1;
	for (i = 1; i < N; i++)
	{
		scanf("%d",&x[i]);
	}
	sort(x, x+N);
	int maxJump = 0;
	int maxJumpFrom = -1;
	static int w[MAXN];
	for (i = 0; ; i++)
	{
		if (x[i] + 1 > maxJump)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
		w[i] = maxJumpFrom;
		if (i == N-1) break;
		if ((x[i+1] - 1) - (x[i] + 1) >= S)
		{
			maxJump = x[i+1] - 1 + D;
			maxJumpFrom = i;
		}
	}
	static struct node res[2 * MAXN];
	int resc = 0;
	res[resc].t = 'R';
	res[resc].l = M - (x[N-1] + 1);
	if (res[resc].l) resc++;
	int pos = N-1;
	while (pos)
	{
		int posPrev = w[pos];
		res[resc].t = 'J';
		res[resc].l = (x[pos] + 1) - (x[posPrev+1] - 1);
		resc++;
		res[resc].t = 'R';
		res[resc].l = (x[posPrev+1] - 1) - (x[posPrev] + 1);
		resc++;
		pos = posPrev;
	}
	for (i = resc-1; i >= 0; i--)
	{
		if (res[i].t == 'J') printf("JUMP");
		else printf("RUN");
		printf(" %d\n",res[i].l);
	}
	return 0;
}