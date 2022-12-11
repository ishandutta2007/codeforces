#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
int b[1111], used[1111];

int main()
{
	int op = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) if(!used[j] && b[j] == 0)
		{
			printf("%d ", j);
			used[j] = 1;
			for(int q = 1; q+k <= j; q++)
				b[q]--;
			break;
		}
	}
	printf("\n");
}