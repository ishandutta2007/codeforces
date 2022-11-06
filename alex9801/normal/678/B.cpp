#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

bool leap(int x)
{
	return x%400==0 || x%4==0 && x%100!=0;
}

int main()
{
	int n, s = 0, i;
	scanf("%d", &n);
	for(i = n+1;; i++)
	{
		if(leap(i))
			s += 2;
		else
			s++;
		s %= 7;
		if(leap(i)==leap(n) && s==0)
		{
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}