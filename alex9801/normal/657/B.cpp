#include <stdio.h>
#include <algorithm>

int arr[200010];
long long two[100];

long long ab(long long x)
{
	return x<0 ? -x : x;
}

int main()
{
	int n, k, p = 0, r = 0, i, j;
	bool u;
	long long s, t, x, y;
	scanf("%d%d", &n, &k);
	for(i = 0; i<=n; i++)
		scanf("%d", &arr[i]);

	two[0] = 1;
	for(i = 1; i<63; i++)
		two[i] = two[i-1]*2;

	s = 0;
	for(i = n; i>=0; i--)
	{
		s *= 2;
		s += arr[i];
		if(ab(s)>k)
		{
			p = i;
			break;
		}
	}

	for(i = p; i<p+32 && i<=n; i++)
	{
		s = 0;
		t = 0;
		u = 1;
		for(j = n; j>=0; j--)
		{
			s *= 2;
			s += arr[j];
			if(ab(s)>k)
			{
				if(i-j>50)
				{
					u = 0;
					break;
				}
				if(s>k)
				{
					x = s%two[i-j];
					y = s/two[i-j];
					if(x<ab(x-two[i-j]))
					{
						s = x;
						t -= y;
					}
					else
					{
						s = x-two[i-j];
						t -= y+1;
					}
				}
				else
				{
					x = (-s)%two[i-j];
					y = (-s)/two[i-j];
					if(x<ab(x-two[i-j]))
					{
						s = -x;
						t += y;
					}
					else
					{
						s = -(x-two[i-j]);
						t += y+1;
					}
				}
				if(ab(s)>k)
				{
					u = 0;
					break;
				}
			}
			if(ab(arr[i]+t)>2*k)
			{
				u = 0;
				break;
			}
		}

		if(u)
		{
			if(s!=0)
			{
				if(i>50)
					continue;

				if(s>k)
				{
					x = s%two[i];
					y = s/two[i];
					s = x;
					t -= y;
				}
				else
				{
					x = (-s)%two[i];
					y = (-s)/two[i];
					s = -x;
					t += y;
				}
			}
			if(s==0 && ab(arr[i]+t)<=k &&!(i==n && arr[i]+t==0))
				r++;
		}
	}

	printf("%d", r);
	return 0;
}