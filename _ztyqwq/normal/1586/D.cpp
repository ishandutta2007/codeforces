#include <bits/stdc++.h>
using namespace std;
int nxt[110], ans[110];
bool pre[110];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		putchar('?');
		for(int j = 1; j < i; j++)
			printf(" 1");
		printf(" 2");
		for(int j = i + 1; j <= n; j++)
			printf(" 1");
		putchar('\n');
		fflush(stdout);
		int pos;
		scanf("%d", &pos);

		if(pos && pos < i)
			nxt[i] = pos, pre[pos] = true;
		putchar('?');
		for(int j = 1; j < i; j++)
			printf(" 2");
		printf(" 1");
		for(int j = i + 1; j <= n; j++)
			printf(" 2");
		putchar('\n');
		fflush(stdout);
		scanf("%d", &pos);
		if(pos && pos < i)
			nxt[pos] = i, pre[i] = true;
	}
	int rt = 0;
	for(int i = 1; i <= n; i++)
		if(!pre[i])
		{
			rt = i;
			break;
		}
	for(int i = 1; i <= n; i++, rt = nxt[rt])
		ans[rt] = i;
	putchar('!');
	for(int i = 1; i <= n; i++)
		printf(" %d", ans[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}