#include <bits/stdc++.h>

using namespace std;

int n, x, y, r, z, gh;
int t[101];
priority_queue <int> pq;

void solve()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		pq.push(t[i]);
	}
	x=0; // ile ma pierwszy
	y=0; // ile ma drugi
	r=0;
	while(!pq.empty())
	{
		if(r)
		{
			z=pq.top();
			pq.pop();
			if(y>=z)
			{
				--y;
			}
			else
			{
				--z;
				swap(y, z);
			}
			if(z)
			{
				pq.push(z);
			}
		}
		else
		{
			z=pq.top();
			pq.pop();
			if(x>=z)
			{
				--x;
			}
			else
			{
				--z;
				swap(x, z);
			}
			if(z)
			{
				pq.push(z);
			}
		}
		r^=1;
	}
	if(r)
	{
		if(x>=y)
		{
			printf("T\n");
		}
		else
		{
			printf("HL\n");
		}
	}
	else
	{
		if(x>y)
		{
			printf("T\n");
		}
		else
		{
			printf("HL\n");
		}
	}
}

int main()
{
	scanf("%d", &gh);
	for(int i=0; i<gh; ++i)
	{
		solve();
	}
	return 0;
}