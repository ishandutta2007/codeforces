#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[210];

int main()
{
	int n, m, t, s = 1, g = 6000000, x, i;
	scanf("%d%d", &n, &m);

	while(s<g)
	{
		x = (s+g)/2;
		t = 0;
		if(x/2-x/6<n)
			t += n-x/2+x/6;
		if(x/3-x/6<m)
			t += m-x/3+x/6;
		if(x/6>=t)
			g = x;
		else
			s = x+1;
	}

	printf("%d", s);
	return 0;
}