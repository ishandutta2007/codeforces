#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int X[400010], Y[400010];

int main()
{
	int n;
	scanf("%d", &n);
	int Sz = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x) X[++Sz] = x;
	}
	Sz = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x) Y[++Sz] = x;
	}
	for(int i = 1; i < n; i++) X[i + n - 1] = X[i];
	for(int i = 1; i < n; i++)
		if(X[i] == Y[1])
		{
			for(int j = 1; j < n; j++)
				if(X[j + i - 1] != Y[j])
				{
					puts("NO");
					return 0;
				}
			break;
		}
	puts("YES");
	return 0;
}