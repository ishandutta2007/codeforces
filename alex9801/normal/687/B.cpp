#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

std::queue<int> q1, q2;

int main()
{
	int n, k, t, a, i;
	scanf("%d%d", &n, &k);

	for(i = 2; i<=1000; i++)
	{
		if(k%i)
			continue;
		t = 1;
		while(1)
		{
			if(k%i==0)
			{
				k /= i;
				t *= i;
			}
			else
				break;
		}
		q1.push(t);
	}

	if(k!=1)
		q1.push(k);

	for(i = 0; i<n; i++)
	{
		scanf("%d", &a);
		while(!q1.empty())
		{
			t = q1.front();
			q1.pop();
			if(a%t)
				q2.push(t);
		}
		while(!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	if(q1.empty())
		printf("Yes");
	else
		printf("No");

	return 0;
}