#include <stdio.h>
#include <queue>

std::queue<int> q;

int main()
{
	int n, b, t, d, s = 0, i;
	long long c = 0;
	scanf("%d%d", &n, &b);

	for(i = 0; i<n; i++)
	{
		scanf("%d%d", &t, &d);
		while(!q.empty() && (q.front()==-1 || c+q.front()<=t))
		{
			if(q.front()!=-1)
			{
				c += q.front();
				printf("%I64d ", c);
				s--;
			}
			else
				printf("-1 ");
			q.pop();
		}

		if(s<=b)
		{
			if(q.empty())
				c = t;
			q.push(d);
			s++;
		}
		else
			q.push(-1);
	}

	while(!q.empty())
	{
		if(q.front()!=-1)
		{
			c += q.front();
			printf("%I64d ", c);
		}
		else
			printf("-1 ");
		q.pop();
	}
	return 0;
}