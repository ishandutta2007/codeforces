#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 100100

int n,q;
int t[maxn], c[maxn];
vector<int> w[maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		c[t[i]]++;
		if(t[i] > n)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i = n; i > 0; i--)
	{
		while(c[i] > 0)
		{
			q++;
			for(int p = i; p > 0; p--)
			{
				if(c[p] == 0)
				{
					printf("-1\n");
					return 0;
				}
				c[p]--;
				w[p].push_back(q);
			}
		}
	}
	printf("%d\n", q);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", w[t[i]].back());
		w[t[i]].pop_back();
	}
}