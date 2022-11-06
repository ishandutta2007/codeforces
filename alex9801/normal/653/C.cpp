#include <stdio.h>
#include <algorithm>

int arr[150010];
bool chk[150010];
const int INF = 200000;
int can[10];

bool val(int x)
{
	if(x%2==0)
		return arr[x-1]<arr[x] && arr[x]>arr[x+1];
	return arr[x-1]>arr[x] && arr[x]<arr[x+1];
}

int main()
{
	bool u;
	int n, c = 0, r = 0, t, s, i, j, k;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);

	arr[0] = INF;
	arr[n+1] = n%2==1 ? INF : 0;

	for(i = 1; i<n; i += 2)
	{
		if(arr[i]>=arr[i+1])
		{
			chk[i] = 1;
			chk[i+1] = 1;
		}
	}
	for(i = 2; i<n; i += 2)
	{
		if(arr[i]<=arr[i+1])
		{
			chk[i] = 1;
			chk[i+1] = 1;
		}
	}

	for(i = 1; i<=n; i++)
	{
		if(chk[i])
		{
			if(c==6)
			{
				printf("0");
				return 0;
			}
			can[c++] = i;
		}
	}

	for(i = 0; i<c; i++)
	{
		t = can[i];
		for(j = 1; j<=n; j++)
		{
			if(t==j || chk[j]&&t>j)
				continue;

			s = arr[t];
			arr[t] = arr[j];
			arr[j] = s;

			u = 1;
			if(!val(j))
				u = 0;
			else
			{
				for(k = 0; k<c; k++)
				{
					if(!val(can[k]))
					{
						u = 0;
						break;
					}
				}
			}

			if(u)
				r++;

			s = arr[t];
			arr[t] = arr[j];
			arr[j] = s;
		}
	}
	printf("%d", r);
	return 0;
}