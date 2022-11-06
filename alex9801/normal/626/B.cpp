#include <stdio.h>
#include <algorithm>

char arr[210];

int main()
{
	int r = 0, g = 0, b = 0, n, i;
	scanf("%d%s", &n, arr);

	for(i = 0; i<n; i++)
	{
		if(arr[i]=='R')
			r++;
		if(arr[i]=='G')
			g++;
		if(arr[i]=='B')
			b++;
	}
	if(g==0&&r==0 || g!=0&&r!=0 || b!=0&&(g>1||r>1))
		printf("B");
	if(b==0&&r==0 || b!=0&&r!=0 || g!=0&&(b>1||r>1))
		printf("G");
	if(g==0&&b==0 || g!=0&&b!=0 || r!=0&&(g>1||b>1))
		printf("R");
	return 0;
}