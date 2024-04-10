#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int a[100000];
int b[100000];

int main()
{
	int n, p, i, j;
	long long sum;
	double t, s, g, x;
	scanf("%d%d", &n, &p);
	for(i = 0; i<n; i++)
		scanf("%d%d", &a[i], &b[i]);

	sum = 0;
	for(i = 0; i<n; i++)
		sum += a[i];

	if(p >= sum)
	{
		printf("-1");
		return 0;
	}

	s = 0;
	g = 10000000000;

	for(j = 0; j<100; j++)
	{
		x = (s+g)/2;

		t = 0;
		for(i = 0; i<n; i++)
			t += std::max(0.0, (1.0*a[i]*x - b[i])/p);
		
		if(t > x)
			g = x;
		else
			s = x;
	}

	printf("%.10lf", (s+g)/2);
	return 0;
}